/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_35E45212_24D5_4AF3_80AF_9A7F60D7A550
#define LANG_35E45212_24D5_4AF3_80AF_9A7F60D7A550

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/Interface.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  struct Executor;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct lang::Executor : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 非阻塞式執行進入點
   * 
   * 可註冊於系統自動倫尋執行。
   * 
   */
  virtual void execute(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_35E45212_24D5_4AF3_80AF_9A7F60D7A550 */
