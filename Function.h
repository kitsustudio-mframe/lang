/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE
#define LANG_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "./Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  template<typename T, typename R> struct Function;
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
template<typename T, typename R>
struct lang::Function : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param t 
   * @return R 
   */
  virtual R apply(T t) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE */
