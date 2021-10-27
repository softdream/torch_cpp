/*
 * @Author: yafeng.zhou
 * @Date: 2021-10-11 18:02:58
 * @LastEditTime: 2021-10-12 11:57:45
 * @LastEditors: yafeng.zhou
 * @Description: Convert the Alg interface program in C++ format to other 
 *               programming languages based on SWIG.
 * @FilePath: /algorithm/swig/alg_api.i
 * @Version: 1.0
 */
%module AlgApi
%include "std_string.i"
%{
#include "alg_api.h"
%}
%include "alg_api.h"
