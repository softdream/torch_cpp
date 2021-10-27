#ifndef __ALG_API_H__
#define __ALG_API_H__

#include <string>

//==============================================================================
class AlgImg;
class AlgImgFactory;
//==============================================================================
/**
 * @brief: C function, create AlgImgFactory instance from JAVA.
 */
extern "C"
{
  AlgImgFactory *AlgImgFactoryInstance();
}

/**
 * @brief: Image recognition execution algorithm interface class.
 */
class AlgImg
{
public:
  /**
   * @param {string} &cfg_file_path: The path of the project configuration file 
   *        required by the algorithm to run the program
   */
  AlgImg() {}
  virtual ~AlgImg() {}

public:
  /**
   * @brief: Release the created AlgImg instance object.
   */
  virtual void Release() = 0;

  /**
   * @brief: load a model.
   * @param {string} &model_file_path: the path of the .pt file
   */
  virtual void LoadModel( const std::string &model_file_path ) = 0;

  /**
   * @brief: The algorithm executes the calling function, the input parameter is
   *        the image string format data of base64, and the return parameter is 
   *        the result data of the string format after the algorithm is executed.
   * @returns {*} The result after recognizing the image, including classID 
   *        and score. eg:"2,0.97823".
   * @param {string} &img_b64_str: Image string format data of base64.
   */
  virtual const std::string Run(const std::string &img_b64_str) = 0;
};

class AlgImgFactory
{
public:
  AlgImgFactory() {}
  virtual ~AlgImgFactory() {}

public:
  /**
   * @brief: Release the created AlgImgFactory instance object.
   */
  virtual void Release() = 0;

  /**
   * @brief: Create an instantiated object of AlgImg.
   * @returns {*} Return the created AlgImg instantiation object.
   */
  virtual AlgImg *CreateAlgImg(const std::string &cfg_file_path) = 0;
};

#endif
