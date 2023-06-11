/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_35E45212_24D5_4AF3_80AF_9A7F60D7A550
#define MFRAME_35E45212_24D5_4AF3_80AF_9A7F60D7A550

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang {
  struct Executor;
}  // namespace mframe::lang

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::lang::Executor : public virtual mframe::lang::Interface {
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

#endif /* MFRAME_35E45212_24D5_4AF3_80AF_9A7F60D7A550 */
