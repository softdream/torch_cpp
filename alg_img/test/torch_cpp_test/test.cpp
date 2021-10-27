#include "alg_torch.h"

int main()
{
	std::cout<<"---------------- Torch CPP Test ------------------"<<std::endl;

	alg::AlgTorch at;

	at.LoadTorchModel( "/home/ddf/Test/java_torch_project/alg_img/model/weights_alexnet_cpu_newout.pt" );

	cv::Mat src = cv::imread( "/home/ddf/Test/java_torch_project/alg_img/test_images/1.jpg" );
        cv::imshow( "input image", src );
        cv::waitKey(0);

	at.addAnInputImg( src );

	std::string ret = at.ForwardProcess();
	std::cout<<"result: "<<std::endl<<ret<<std::endl;

	return 0;
}
