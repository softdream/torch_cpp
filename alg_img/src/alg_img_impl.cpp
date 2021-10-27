/*
 * @Author: yafeng.zhou
 * @Date: 2021-10-11 18:23:15
 * @LastEditTime: 2021-10-12 14:48:48
 * @LastEditors: yafeng.zhou
 * @Description: Implementation class of Alg interface.
 * @FilePath: /algorithm/src/alg_img_impl.cpp
 * @Version: 1.0
 */
#include "alg_img_impl.h"
#include <iostream>


// void AlgImgImpl::Init(const std::string &cfg_file_path)
// {
//   cfg_file_path_ = cfg_file_path;
// }

void AlgImgImpl::Release()
{
	delete this;
}

const std::string AlgImgImpl::Run(const std::string &img_b64_str)
{
  	//std::cout << "[ configuration file path ] "
        //  		<< cfg_file_path_ << std::endl;

	cv::Mat image = base64::Base2Mat( img_b64_str );	

	alg_torch_.addAnInputImg( image );

	std::string alg_ret = alg_torch_.ForwardProcess();

  	std::cout << "[ input and update ] " << img_b64_str << std::endl;
  	std::cout << "[ algimg return    ] " << alg_ret << std::endl;

 	return alg_ret;
}

void AlgImgImpl::LoadModel( const std::string &model_file_path )
{
	alg_torch_.LoadTorchModel( model_file_path );
}



