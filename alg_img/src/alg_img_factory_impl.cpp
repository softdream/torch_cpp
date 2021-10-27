/*
 * @Author: yafeng.zhou
 * @Date: 2021-10-11 18:47:06
 * @LastEditTime: 2021-10-12 11:26:54
 * @LastEditors: yafeng.zhou
 * @Description: Implementation class of AlgFactory interface.
 * @FilePath: /algorithm/src/alg_img_factory_impl.cpp
 * @Version: 1.0
 */
#include "alg_img_factory_impl.h"
#include "alg_img_impl.h"

AlgImgFactory *AlgImgFactoryInstance()
{
  return new AlgImgFactoryImpl();
}

void AlgImgFactoryImpl::Release()
{
  delete this;
}

AlgImg *AlgImgFactoryImpl::CreateAlgImg(const std::string &cfg_file_path)
{
  return new AlgImgImpl(cfg_file_path);
}
