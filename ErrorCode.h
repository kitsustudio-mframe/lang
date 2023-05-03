/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212
#define LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "./Object.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  enum struct ErrorCode : int;
}

/* ****************************************************************************************
 * Class Object
 */  
enum struct lang::ErrorCode : int{
  NONE                       = 0x00000000 + 0,
  HARD_FAULT                 = 0x00000000 + 1,
  SYSTEM_ERROR               = 0x00000000 + 2,
  OUT_OF_MEMORY              = 0x00000000 + 3,
  OUT_OF_THREAD_STACK_MEMORY = 0x00000000 + 4,
  NULL_POINTER               = 0x00000000 + 5,
  ILLEGAL_ARGUMENT           = 0x00000000 + 6,
  INSUFFICIENT_MEMORY        = 0x00000000 + 7,
  WRITE_TO_READONLY_MEMORY   = 0x00000000 + 8,
  MEMORY_NOT_ALIGNMENT_32BIT = 0x00000000 + 9,
  MEMORY_NOT_ALIGNMENT_64BIT = 0x00000000 + 10,
    
  RTX_STACK_UNDERFLOW        = 0x10000000 + 0,
  RTX_ISR_QUEUE_OVERFLOW     = 0x10000000 + 1,
  RTX_TIMER_QUEUE_OVERFLOW   = 0x10000000 + 2,
  RTX_CLIB_SPACE             = 0x10000000 + 3,
  RTX_CLIB_MUTEX             = 0x10000000 + 4,
  
  RESERVED                   = 0x7FFFFFFF
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212 */
