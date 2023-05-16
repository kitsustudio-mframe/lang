/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7
#define LANG_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Object.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class Maths;
}



/* ****************************************************************************************
 * Class Math
 */  
class lang::Maths : public lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private:

    /**
     * @brief Construct a new Math object
     * 
     */
    Maths(void);

    /**
     * @brief Destroy the Math object
     * 
     */
    virtual ~Maths(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */ 
  public:
    /**
     * @brief 返回x的反餘弦弧度。
     * 
     * @param x 
     * @return double 
     */
    static double acos(double x);

    /**
     * @brief 返回x的正弦弧線弧度。
     * 
     * @param x 
     * @return double 
     */
    static double asin(double x);

    /**
     * @brief 返回x的反正切值，以弧度為單位。
     * 
     * @param x 
     * @return double 
     */
    static double atan(double x);

    /**
     * @brief 返回y/x的以弧度為單位的反正切值，根據這兩個值，以確定正確的象限上的標誌。
     * 
     * @param y 
     * @param x 
     * @return double 
     */
    static double atan2(double y, double x);

    /**
     * @brief 返回的弧度角x的餘弦值。
     * 
     * @param x 
     * @return double 
     */
    static double cos(double x);

    /**
     * @brief 返回x的雙曲餘弦。
     * 
     * @param x 
     * @return double 
     */
    static double cosh(double x);

    /**
     * @brief 返回一個弧度角x的正弦。
     * 
     * @param x 
     * @return double 
     */
    static double sin(double x);

    /**
     * @brief 返回x的雙曲正弦。
     * 
     * @param x 
     * @return double 
     */
    static double sinh(double x);

    /**
     * @brief 返回x的雙曲正切。
     * 
     * @param x 
     * @return double 
     */
    static double tanh(double x);

    /**
     * @brief The returned value is the mantissa and the integer yiibaied to by exponent is 
     *        the exponent. The resultant value is x = mantissa * 2 ^ exponent.
     * 
     * @param x 
     * @param exponent 
     * @return double 
     */
    static double frexp(double x, int *exponent);

    /**
     * @brief Returns x multiplied by 2 raised to the power of exponent.
     * 
     * @param x 
     * @param exponent 
     * @return double 
     */
    static double ldexp(double x, int exponent);
      
    /**
     * @brief 返回自然對數的x（基準-E對數）
     * 
     * @param x 
     * @return double 
     */
    static double log(double x);

    /**
     * @brief 返回x的常用對數（以10為底）。
     * 
     * @param x 
     * @return double 
     */
    static double log10(double x);

    /**
     * @brief 返回的值是小數成分（小數點後的部分），並設置整數的整數部分。
     * 
     * @param x 
     * @param integer 
     * @return double 
     */
    static double modf(double x, double *integer);

    /**
     * @brief 返回x的y次方。
     * 
     * @param x 
     * @param y 
     * @return double 
     */
    static double pow(double x, double y);

    /**
     * @brief 返回x的平方根。
     * 
     * @param x 
     * @return double 
     */
    static double sqrt(double x);
    
    /**
     * @brief 返回大於或等於x的最小整數值。
     * 
     * @param x 
     * @return double 
     */
    static double ceil(double x);

    /**
     * @brief 返回x的絕對值
     * 
     * @param x 
     * @return double 
     */
    static double fabs(double x);

    /**
     * @brief 返回的最大整數值小於或等於x。
     * 
     * @param x 
     * @return double 
     */
    static double floor(double x);
    
    /**
     * @brief 返回的x除以y的餘數。
     * 
     * @param x 
     * @param y 
     * @return double 
     */
    static double fmod(double x, double y);
  
  /* **************************************************************************************
   * Public Method <Static Inline>
   */   
  public:

    /**
     * @brief Returns the absolute value of an int value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Integer.MIN_VALUE, the 
     *        most negative representable int value, the result is that same value, which 
     *        is negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline int abs(int a){
      if(a)
        return ~a;
      
      return a;
    }

    /**
     * @brief Returns the absolute value of a long value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Long.MIN_VALUE, the most 
     *        negative representable long value, the result is that same value, which is 
     *        negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline long abs(long a){
      if(a<0)
        return (a * (-1));
      
      return a;
    }

    /**
     * @brief Returns the absolute value of a float value. If the argument is not negative, 
     *        the argument is returned. If the argument is negative, the negation of the 
     *        argument is returned.
     * 
     *        Note that if the argument is equal to the value of Float.MIN_VALUE, the most 
     *        negative representable float value, the result is that same value, which is
     *        negative.
     * 
     * @param a the argument whose absolute value is to be determined
     * @return the absolute value of the argument.
     */
    static inline float abs(float a){
      if(a<0)
        return (a * (-1));
      
      return a;
    }  
    
    /**
     * @brief 
     * 
     * @param value 
     * @return uint32_t 
     */
    static inline uint32_t align32bit(uint32_t value){
      if(value & 0x00000003)
        return  (value & 0xFFFFFFF4) + 4;
      
      return value;
    }
    
    /**
     * @brief 
     * 
     * @param value 
     * @return uint32_t 
     */
    static inline uint32_t align64bit(uint32_t value){
      if(value & 0x00000007)
        return  (value & 0xFFFFFFF8) + 8;
      
      return value;
    }  
    
    /**
     * @brief 
     * 
     * @param dividend 
     * @param divisor 
     * @return int 
     */
    static inline int ceil(int dividend, int divisor){
      return (dividend + (divisor-1)) / divisor;
    }

    /**
     * @brief 
     * 
     * @param dividend 
     * @param divisor 
     * @return uint32_t 
     */
    static inline uint32_t ceil(uint32_t dividend, uint32_t divisor){
      return (dividend + (divisor-1)) / divisor;
    }  
    
    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return uint32_t 
     */
    static inline uint32_t min(uint32_t a, uint32_t b){
      return ((a)<(b)?(a):(b));
    }
    
    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return int 
     */
    static inline int min(int a, int b){
      return ((a)<(b)?(a):(b));
    }    

    /**
     * @brief 
     * 
     * @param a 
     * @param b 
     * @return uint32_t 
     */
    static inline uint32_t max(uint32_t a, uint32_t b){
      return ((a)>(b)?(a):(b));
    }  

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* LANG_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7 */
