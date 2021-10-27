/*
 * @Author: yafeng.zhou
 * @Date: 2021-10-11 18:13:54
 * @LastEditTime: 2021-10-12 14:46:33
 * @LastEditors: yafeng.zhou
 * @Description: Implementation class of Alg interface.
 * @FilePath: /algorithm/include/alg_img_impl.h
 * @Version: 1.0
 */
#pragma once

#include "alg_api.h"

#include "alg_torch.h"

#include "alg_base64.h"

class AlgImgImpl : public AlgImg
{
public:
  AlgImgImpl(const std::string &cfg_file_path) : cfg_file_path_(cfg_file_path) {}
  virtual ~AlgImgImpl() {}

public:
  /**
   * @brief: Release the created AlgImg instance object.
   */
  virtual void Release();

  /**
   * @brief: load a model.
   * @param {string} &model_file_path: the path of the .pt file
   */
  virtual void LoadModel( const std::string &model_file_path );

  /**
   * @brief: The algorithm executes the calling function, the input parameter is
   *        the image string format data of base64, and the return parameter is 
   *        the result data of the string format after the algorithm is executed.
   * @returns {*} The result after recognizing the image, including classID 
   *        and score. eg:"2,0.97823".
   * @param {string} &img_b64_str: Image string format data of base64.
   */
  virtual const std::string Run(const std::string &img_b64_str);

private:
	std::string cfg_file_path_;

	alg::AlgTorch alg_torch_;	
};
