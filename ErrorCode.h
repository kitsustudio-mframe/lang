/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212
#define LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212

/* ******************************************************************************
 * Include
 */  
 
//-------------------------------------------------------------------------------
#include "./Interface.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */  
namespace lang{
  enum struct ErrorCode : int;
}

/* ******************************************************************************
 * Class Object
 */  
enum struct lang::ErrorCode : int{
  NONE                          = 0x00000000 + 0,  ///<預設無異常
  HARD_FAULT,                                      ///<硬體錯誤
  SYSTEM_ERROR,                                    ///<系統錯誤
  INSUFFICIENT_MEMORY,                             ///<系統內存不足
  INSUFFICIENT_STACK_MEMORY,                       ///<執行緒內存不足
  NULL_POINTER,                                    ///<物件值為null
  ILLEGAL_ARGUMENT,                                ///<方法呼叫時參數型態不同
  WRITE_TO_READONLY_MEMORY,                        ///<寫入至唯讀記憶體
  ARRAY_INDEX_OUT_OF_BOUNDS,                       ///<陣列索引值小於0或超過陣列邊界
  
  RESERVED                   = 0x7FFFFFFF       ///<RESERVED
};

/* *******************************************************************************
 * End of file
 */ 

#endif /* LANG_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212 */
