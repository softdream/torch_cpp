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
