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
