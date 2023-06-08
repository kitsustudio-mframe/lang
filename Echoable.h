/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_222C3DA5_0CEC_43AE_8CBE_04BF7A36FE4C
#define LANG_222C3DA5_0CEC_43AE_8CBE_04BF7A36FE4C

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
  struct Echoable;
  struct WriteBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct lang::Echoable : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 啟用或停用echo模式
   * 
   * @param enable 
   * @return true 啟用echo
   * @return false 停用echo
   */
  virtual bool echo(bool enable) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_222C3DA5_0CEC_43AE_8CBE_04BF7A36FE4C */
