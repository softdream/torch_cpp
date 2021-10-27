#ifndef __ALG_BASE64_H_
#define __ALG_BASE64_H_

#include "opencv2/opencv.hpp"

namespace base64{

/**
* @brief: Decode base64 string.
* @returns {string}: Return the decoded string.
* @param {const char *} Data: input image data array.
* @param {const int} DataByte: length of the input array
*/
const std::string base64Decode(const char* Data, const int DataByte);

/**     
* @brief: Encode base64 string.
* @returns {string}: Return the Encoded string.
* @param {const unsigned char *} Data: input base64 data array.
* @param {const int} DataByte: length of the input array
*/
const std::string base64Encode(const unsigned char* Data, const int DataByte);

/**
* @brief: Convert cv::Mat to base64 string.
* @returns {string}: Return the Encoded string.
* @param {const cv::Mat} &img: input image.
* @param {string} &imgType: input image's type. eg: jpg, png ....
*/
const std::string Mat2Base64(const cv::Mat &img, std::string &imgType);

/**
* @brief: Convert base64 string to cv::Mat.
* @returns {string}: Return the decoded Image.
* @param {const string} &base65_data: input base64 string.
*/
const cv::Mat Base2Mat(const std::string &base64_data);

}

#endif /* BASE64_H */
