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
#include "./Interface.h"

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
  NONE                       = 0x00000000 + 0,  ///<預設無異常
  HARD_FAULT                 = 0x00000000 + 1,  ///<HARD_FAULT
  SYSTEM_ERROR               = 0x00000000 + 2,  ///<SYSTEM_ERROR
  OUT_OF_MEMORY              = 0x00000000 + 3,  ///<OUT_OF_MEMORY
  OUT_OF_THREAD_STACK_MEMORY = 0x00000000 + 4,  ///<OUT_OF_THREAD_STACK_MEMORY
  NULL_POINTER               = 0x00000000 + 5,  ///<NULL_POINTER
  ILLEGAL_ARGUMENT           = 0x00000000 + 6,  ///<ILLEGAL_ARGUMENT
  INSUFFICIENT_MEMORY        = 0x00000000 + 7,  ///<INSUFFICIENT_MEMORY
  WRITE_TO_READONLY_MEMORY   = 0x00000000 + 8,  ///<WRITE_TO_READONLY_MEMORY
  MEMORY_NOT_ALIGNMENT_32BIT = 0x00000000 + 9,  ///<MEMORY_NOT_ALIGNMENT_32BIT
  MEMORY_NOT_ALIGNMENT_64BIT = 0x00000000 + 10, ///<MEMORY_NOT_ALIGNMENT_64BIT
    
  RTX_STACK_UNDERFLOW        = 0x10000000 + 0,  ///<RTX_STACK_UNDERFLOW
  RTX_ISR_QUEUE_OVERFLOW     = 0x10000000 + 1,  ///<RTX_ISR_QUEUE_OVERFLOW
  RTX_TIMER_QUEUE_OVERFLOW   = 0x10000000 + 2,  ///<RTX_TIMER_QUEUE_OVERFLOW
  RTX_CLIB_SPACE             = 0x10000000 + 3,  ///<RTX_CLIB_SPACE
  RTX_CLIB_MUTEX             = 0x10000000 + 4,  ///<RTX_CLIB_MUTEX
  
  RESERVED                   = 0x7FFFFFFF       ///<RESERVED
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212 */
