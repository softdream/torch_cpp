#include "alg_torch.h"

namespace alg{

bool AlgTorch::LoadTorchModel( const std::string &file_path )
{
	try{
		module_ = torch::jit::load( file_path );
	}
	catch( const c10::Error &e ){
		std::cerr<<"Can not load the model ..."<<std::endl;
                return false;
	}

	std::cerr<<"Load the Model ..."<<std::endl;

	module_.to( device_type_ );

	module_.eval();

	return true;
}

void AlgTorch::ImgCrop( cv::Mat &img_src, cv::Mat &img_dst )
{
	// 1. convert color
	cv::cvtColor( img_src, img_src, cv::COLOR_BGR2RGB );

	// 2. image crop
	if( img_src.size().height == 600 && img_src.size().width == 800 ){
		cv::Rect roi( 120, 70, 560, 230 );
		img_dst = img_src( roi );
	}
	else {
		img_dst = img_src;
	}
	
}

const torch::Tensor AlgTorch::ImgPreProcess( cv::Mat &img_src )
{
	cv::Mat image;
	this->ImgCrop( img_src, image );

	cv::Mat img_float;
	cv::resize( image, img_float, cv::Size(224, 224) );

	torch::Device device( device_type_ );

	torch::Tensor img_tensor = torch::from_blob( img_float.data, {1, 224, 224, 3}, torch::kByte ).to(device);

	img_tensor = img_tensor.permute( {0, 3, 1, 2} );
        img_tensor = img_tensor.toType( torch::kFloat );
        img_tensor = img_tensor.div( 255 );

        img_tensor[0][0] = img_tensor[0][0].sub_(0.485).div_(0.229);
        img_tensor[0][1] = img_tensor[0][1].sub_(0.456).div_(0.224);
        img_tensor[0][2] = img_tensor[0][2].sub_(0.406).div_(0.225);

	return img_tensor;
}

void AlgTorch::addAnInputImg( cv::Mat &img_src )
{
	auto img_tensor = this->ImgPreProcess( img_src );

	inputs_.push_back( img_tensor );
}

const std::string AlgTorch::ForwardProcess()
{
#ifdef TEMINAL_DEBUG
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
#endif
	at::Tensor output = module_.forward( inputs_ ).toTensor();

#ifdef TEMINAL_DEBUG
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout<<"Processing time : "<<( std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count() ) / 1000000.0 <<" sec"<<std::endl;

	std::cout<<output.sizes()<<std::endl;
        std::cout<<output.slice( 1, 0, 3 )<<std::endl;
#endif

	auto max_result = torch::max( output, 1 );
        auto max_prob = std::get<0>(max_result).item<float>();
        auto max_index = std::get<1>(max_result).item<int>();

#ifdef TEMINAL_DEBUG
	std::cout<<"------------- Result -------------"<<std::endl;
        std::cout<<"belief: "<<log10(max_prob)<<std::endl;
        std::cout<<"index: "<<max_index<<std::endl;
#endif

	std::string ret = std::to_string( max_index ) + "," + std::to_string( log10(max_prob) );

	return ret;	
}

}
