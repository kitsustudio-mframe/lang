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
  interface InputBuffer;
  interface OutputBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface lang::InputBuffer extends virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 取得InputBuffer是否已滿
   * 
   * @return true 已滿
   * @return false 未滿，仍有空間
   */
  virtual bool isFull(void) const abstract;

  /**
   * @brief 取得InputBuffer內資料數量
   * 
   * @return int InputBuffer內資料數量
   */
  virtual int remaining(void) const abstract;

  /**
   * @brief 將data輸入至InputBuffer
   * 
   * @param data 資料來源
   * @return true 成功將data輸入至InputBuffer
   * @return false InputBuffer已滿
   */
  virtual bool putByte(const char data) abstract;

  /**
   * @brief 將outputBuffer內資料輸入至InputBuffer
   * 
   * @param byteBuffer 資料來源
   * @return int 移動資料數量(byte)
   */
  virtual int put(lang::OutputBuffer& outputBuffer) abstract;
  
  /**
   * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
   * 
   * @param byteBuffer 資料來源
   * @param length 輸入長度
   * @return int 移動資料數量(byte)
   */
  virtual int put(lang::OutputBuffer& outputBuffer, int length) abstract;  

  /**
   * @brief 將buffer內資料輸入至InputBuffer
   * 
   * @param buffer 資料來源
   * @param length 輸入長度
   * @return int 移動資料數量(byte)
   */
  virtual int put(const void* buffer, int length) abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_866C8352_DB87_4C00_A483_93113124908D */
