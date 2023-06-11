/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_11DE2BBA_4823_4E3F_884E_9A333C00AD9F
#define MFRAME_11DE2BBA_4823_4E3F_884E_9A333C00AD9F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class E>
  struct Iterable;
}  // namespace mframe::lang

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class E>
struct mframe::lang::Iterable {
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 檢索但不刪除此隊列的值，如果訪問此列隊位置為空，則返回false。
   *
   * @param index 位置
   * @param result 結果
   * @return true 訪問成功，結果將存放於result
   * @return false 訪問失敗，可能超出上限或是列隊為空
   */
  virtual bool peekIndex(int index, E& result) abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_11DE2BBA_4823_4E3F_884E_9A333C00AD9F */
