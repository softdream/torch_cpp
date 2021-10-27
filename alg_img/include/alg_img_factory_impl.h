/*
 * @Author: yafeng.zhou
 * @Date: 2021-10-11 18:18:39
 * @LastEditTime: 2021-10-12 11:23:41
 * @LastEditors: yafeng.zhou
 * @Description: Implementation class of AlgFactory interface.
 * @FilePath: /algorithm/include/alg_img_factory_impl.h
 * @Version: 1.0
 */
#pragma once

#include "alg_api.h"

class AlgImgFactoryImpl : public AlgImgFactory
{
public:
  AlgImgFactoryImpl() {}
  virtual ~AlgImgFactoryImpl() {}

public:
  /**
   * @brief: Release the created AlgImgFactory instance object.
   */
  virtual void Release();

  /**
   * @brief: Create an instantiated object of AlgImg.
   * @returns {*} Return the created AlgImg instantiation object.
   */
  virtual AlgImg *CreateAlgImg(const std::string &cfg_file_path);
};
