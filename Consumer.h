/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD
#define LANG_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD

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
  template<typename T> interface Consumer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
interface lang::Consumer extends virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param t 
   */
  virtual void accept(T t) abstract;
   
};


/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD */