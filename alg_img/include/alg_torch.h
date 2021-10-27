#ifndef __ALG_TORCH_H_
#define __ALG_TORCH_H_

#include <iostream>
#include "torch/script.h"
#include "torch/torch.h"

#include <chrono>
#include <string>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

namespace alg{

class AlgTorch
{
public:
	AlgTorch()
	{
	
	}

	~AlgTorch()
	{
	
	}

	/**
	* @brief: Load the trained model.
	* @returns {bool} true: loaded, false: loaded failed.
	* @param {string} &file_path: model file path.
	*/
	bool LoadTorchModel( const std::string &file_path );

	 /**
        * @brief: Add an input Image.
        * @param {cv::Mat} &img_src: input image.
        */
	void addAnInputImg( cv::Mat &img_src );

	 /**
        * @brief: Image Processing.
        * @returns {string} The result after recognizing the image, 
	* 		    including classID and score. eg:"2,0.97823".
        */
	const std::string ForwardProcess();

	 /**
        * @brief: Get Input images' number.
        * @returns {const int} intput images's number
        */
	inline const int GetInputImgNumber() const
	{	
		return inputs_.size();
	}
	
	/**
        * @brief: Judge weather if the input container is empty.
        * @returns {bool} true: empty, false: not empty
        */
	inline bool IsInputsEmpty() const 
	{
		return inputs_.empty();
	}

private:
	/**
        * @brief: Image Crop.
        * @param {cv::Mat} &img_src: source image.
	* @param {cv::Mat} &img_dst: destination image
        */
	void ImgCrop( cv::Mat &img_src, cv::Mat &img_dst );

	/**
        * @brief: Convert cv::Mat to torch::Tensor.
        * @returns {torch::Tensor} torch tensor.
        * @param {cv::Mat} &img_src: source image
        */
        const torch::Tensor ImgPreProcess( cv::Mat &img_src );

private:	
	torch::DeviceType device_type_ = torch::kCPU;

	torch::jit::script::Module module_;

	std::vector<torch::jit::IValue> inputs_;
};

}

#endif
