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
 
#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#pragma clang diagnostic ignored "-Wdeprecated-copy-dtor"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++17-extensions" 

//-----------------------------------------------------------------------------------------
#include <stdint.h>
#include <stdarg.h>

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  struct Interface;
  class Object;
}


/* ****************************************************************************************
 * Class/struct/Struct/Enum
 */
struct lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Destroy the struct object
   * 
   */
  virtual ~Interface(void) = default;
  
  /**
   *
   */
  virtual lang::Object& getObject(void) = 0;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
