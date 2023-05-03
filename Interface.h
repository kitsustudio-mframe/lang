/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D
#define MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./lang.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  interface Interface;
  class Object;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Destroy the Interface object
   * 
   */
  virtual ~Interface(void) = default;
  
  /**
   *
   */
  virtual lang::Object& getObject(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
