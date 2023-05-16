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
  template<typename T, typename U> struct BiConsumer;
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
template<typename T, typename U>
struct lang::BiConsumer : public virtual lang::Interface{

  /* **************************************************************************************
   * Method 
   */
  
  /**
   * @brief 
   * 
   * @param t 
   * @param u 
   */
  virtual void accept(T t, U u) = 0;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_CE48C601_AB18_4B36_8C89_8ACA733118B1 */
