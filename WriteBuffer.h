/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_866C8352_DB87_4C00_A483_93113124908D
#define LANG_866C8352_DB87_4C00_A483_93113124908D

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Data.h"
#include "./Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  struct WriteBuffer;
  struct ReadBuffer;
}  // namespace lang

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */

/**
 * @brief 寫緩衝區 <Interface>
 * 
 */
struct lang::WriteBuffer : public virtual lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief 取得WriteBuffer是否已滿。
   *
   * @return true 已滿。同remaining()返回0。
   * @return false 未滿，仍有空間。
   */
  virtual bool isFull(void) const abstract;

  /**
   * @brief 取得緩衝區剩餘空閒字節數。
   *
   * @return int 剩餘的空閒字節數。
   */
  virtual int remaining(void) const abstract;

  /**
   * @brief 將字節輸入至緩衝區。
   *
   * @param data 資料來源
   * @return int 實際輸入至緩衝區的字節數。
   */
  virtual int putByte(const char data) abstract;

  /**
   * @brief 將readBuffer內資料輸入至緩衝區。
   *
   * @param readBuffer 資料來源
   * @return int 實際輸入至緩衝區的字節數。
   */
  virtual int put(lang::ReadBuffer& readBuffer) abstract;

  /**
   * @brief 將readBuffer內資料輸入至緩衝區，限定最大輸入數量為length。
   *
   * @param readBuffer 資料來源
   * @param length 最大輸入字節數
   * @return int 實際輸入至緩衝區的字節數，最大不超過length。
   */
  virtual int put(lang::ReadBuffer& readBuffer, int length) abstract;

  /**
   * @brief 將任一唯獨指針內資料輸入至緩衝區。
   *
   * @param buffer 資料來源
   * @param length 輸入長度
   * @return int 實際輸入至緩衝區的字節數，最大不超過length。
   */
  virtual int put(const void* buffer, int length) abstract;
};

/* ******************************************************************************
 * End of file
 */

#endif /* LANG_866C8352_DB87_4C00_A483_93113124908D */
