/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_866C8352_DB87_4C00_A483_93113124908D
#define LANG_866C8352_DB87_4C00_A483_93113124908D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Interface.h"
#include "./Data.h"

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  struct WriteBuffer;
  struct ReadBuffer;
}


/* ****************************************************************************************
 * Class/struct/Struct/Enum
 */
struct lang::WriteBuffer : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 取得WriteBuffer是否已滿
   * 
   * @return true 已滿
   * @return false 未滿，仍有空間
   */
  virtual bool isFull(void) const = 0;

  /**
   * @brief 取得WriteBuffer內資料數量
   * 
   * @return int WriteBuffer內資料數量
   */
  virtual int remaining(void) const = 0;

  /**
   * @brief 將data輸入至WriteBuffer
   * 
   * @param data 資料來源
   * @return true 成功將data輸入至WriteBuffer
   * @return false WriteBuffer已滿
   */
  virtual bool putByte(const char data) = 0;

  /**
   * @brief 將outputBuffer內資料輸入至WriteBuffer
   * 
   * @param byteBuffer 資料來源
   * @return int 移動資料數量(byte)
   */
  virtual int put(lang::ReadBuffer& outputBuffer) = 0;
  
  /**
   * @brief 將outputBuffer內資料輸入至WriteBuffer並指定輸入長度
   * 
   * @param byteBuffer 資料來源
   * @param length 輸入長度
   * @return int 移動資料數量(byte)
   */
  virtual int put(lang::ReadBuffer& outputBuffer, int length) = 0;  

  /**
   * @brief 將buffer內資料輸入至WriteBuffer
   * 
   * @param buffer 資料來源
   * @param length 輸入長度
   * @return int 移動資料數量(byte)
   */
  virtual int put(const void* buffer, int length) = 0;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_866C8352_DB87_4C00_A483_93113124908D */
