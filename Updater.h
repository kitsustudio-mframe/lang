/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43
#define LANG_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43

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
  struct Updater;
}


/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
struct lang::Updater :public virtual lang::Interface{

  /* ****************************************************************************
   * Method
   */

  /**
   * @brief 更新資源
   * 
   * @return true 開始嘗試更新成功
   * @return false 開始嘗試更新失敗
   */
  virtual bool update(void) abstract;

  /**
   * @brief 是否正在更新
   * 
   * @return true 正在更新中
   * @return false 等待更新
   */
  virtual bool isUpdating(void) abstract;
};

/* ******************************************************************************
 * End of file
 */

#endif /* LANG_CF8A21F0_A644_4EE4_A29D_B76F28A9FD43 */
