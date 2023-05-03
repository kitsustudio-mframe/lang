/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include <math.h>

//-----------------------------------------------------------------------------------------
#include "./Maths.h"
 
/* ****************************************************************************************
 * Using
 */  
using lang::Maths;
 
/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Math object
 * 
 */
Maths::Maths(void){
  return;
}

/**
 * @brief Destroy the Math object
 * 
 */
Maths::~Maths(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
/**
 * @brief 返回x的反餘弦弧度。
 * 
 * @param x 
 * @return std::double
 */
double Maths::acos(double x){
  return std::acos(x);
}

/**
 * @brief 返回x的正弦弧線弧度。
 * 
 * @param x 
 * @return std::double
 */
double Maths::asin(double x){
  return std::asin(x);
}

/**
 * @brief 返回x的反正切值，以弧度為單位。
 * 
 * @param x 
 * @return std::double
 */
double Maths::atan(double x){
  return std::atan(x);
}

/**
 * @brief 返回y/x的以弧度為單位的反正切值，根據這兩個值，以確定正確的象限上的標誌。
 * 
 * @param y 
 * @param x 
 * @return std::double
 */
double Maths::atan2(double y, double x){
  return std::atan2(y, x);
}

/**
 * @brief 返回的弧度角x的餘弦值。
 * 
 * @param x 
 * @return std::double
 */
double Maths::cos(double x){
  return std::cos(x);
}

/**
 * @brief 返回x的雙曲餘弦。
 * 
 * @param x 
 * @return std::double
 */
double Maths::cosh(double x){
  return std::cosh(x);
}

/**
 * @brief 返回一個弧度角x的正弦。
 * 
 * @param x 
 * @return std::double
 */
double Maths::sin(double x){
  return std::sin(x);
}

/**
 * @brief 返回x的雙曲正弦。
 * 
 * @param x 
 * @return std::double
 */
double Maths::sinh(double x){
  return std::sinh(x);
}

/**
 * @brief 返回x的雙曲正切。
 * 
 * @param x 
 * @return std::double
 */
double Maths::tanh(double x){
  return std::tanh(x);
}

/**
 * @brief The returned value is the mantissa and the integer yiibaied to by exponent is 
 *        the exponent. The resultant value is x = mantissa * 2 ^ exponent.
 * 
 * @param x 
 * @param exponent 
 * @return std::double
 */
double Maths::frexp(double x, int *exponent){
  return std::frexp(x, exponent);
}

/**
 * @brief Returns x multiplied by 2 raised to the power of exponent.
 * 
 * @param x 
 * @param exponent 
 * @return std::double
 */
double Maths::ldexp(double x, int exponent){
  return std::ldexp(x, exponent);
}
  
/**
 * @brief 返回自然對數的x（基準-E對數）
 * 
 * @param x 
 * @return std::double
 */
double Maths::log(double x){
  return std::log(x);
}

/**
 * @brief 返回x的常用對數（以10為底）。
 * 
 * @param x 
 * @return std::double
 */
double Maths::log10(double x){
  return std::log10(x);
}

/**
 * @brief 返回的值是小數成分（小數點後的部分），並設置整數的整數部分。
 * 
 * @param x 
 * @param integer 
 * @return std::double
 */
double Maths::modf(double x, double *integer){
  return std::modf(x, integer);
}

/**
 * @brief 返回x的y次方。
 * 
 * @param x 
 * @param y 
 * @return std::double
 */
double Maths::pow(double x, double y){
  return std::pow(x, y);
}

/**
 * @brief 返回x的平方根。
 * 
 * @param x 
 * @return std::double
 */
double Maths::sqrt(double x){
  return std::sqrt(x);
}

/**
 * @brief 返回大於或等於x的最小整數值。
 * 
 * @param x 
 * @return std::double
 */
double Maths::ceil(double x){
  return std::ceil(x);
}

/**
 * @brief 返回x的絕對值
 * 
 * @param x 
 * @return std::double
 */
double Maths::fabs(double x){
  return std::fabs(x);
}

/**
 * @brief 返回的最大整數值小於或等於x。
 * 
 * @param x 
 * @return std::double
 */
double Maths::floor(double x){
  return std::floor(x);
}

/**
 * @brief 返回的x除以y的餘數。
 * 
 * @param x 
 * @param y 
 * @return std::double
 */
double Maths::fmod(double x, double y){
  return std::fmod(x, y);
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
