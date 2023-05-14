/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_CE48C601_AB18_4B36_8C89_8ACA733118B1
#define LANG_CE48C601_AB18_4B36_8C89_8ACA733118B1

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
  template<typename T, typename U> interface BiConsumer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T, typename U>
interface lang::BiConsumer extends virtual lang::Interface{

  /* **************************************************************************************
   * Method 
   */
  
  /**
   * @brief 
   * 
   * @param t 
   * @param u 
   */
  virtual void accept(T t, U u) abstract;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_CE48C601_AB18_4B36_8C89_8ACA733118B1 */