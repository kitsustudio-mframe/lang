/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4
#define LANG_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4

/* ****************************************************************************************
 * Include
 */
#include "./ReadBuffer.h"
#include "./CompletionHandler.h"
#include "./Future.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  struct OutputStream;
}



/* ****************************************************************************************
 * Class/struct/Struct
 */
struct lang::OutputStream : public virtual lang::Interface{

  /* **************************************************************************************
   *  Method <Public>
   */
  
  /**
   * @brief 
   * 取消當前的輸出串流寫入
   *
   * @return true為成功終止當前的輸出至OutputStream，false則否，有可能當前輸出串流並未忙碌
   */
  virtual bool abortWrite(void) abstract;
  
  /**
   * @brief 
   * 取得輸出串流是否為寫入忙碌
   * 
   * @return true為輸出串流忙碌中，無法接受新的寫入，false則否
   */
  virtual bool writeBusy(void) abstract;
  
  /**
   * @brief write witt io mode.
   * 
   * @param readBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(lang::ReadBuffer& readBuffer, int timeout) abstract;  
  
  /**
   * @brief write with aio mode.
   * 
   * @param readBuffer
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool write(lang::ReadBuffer& readBuffer, 
                     void* attachment,
                     lang::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 從給定的緩衝區向該通道寫入一個字節序列。
   * 該方法啟動異步寫入操作，以從給定的緩衝區向該通道寫入字節序列。
   * 該方法的行為方式與 write(ReadBuffer,void*,CompletionHandler)方法完全相同，不同的是，該方法不是指定完成處理程序，
   * 而是返回一個Future待處理結果的Future。Future的get方法返回寫入的字節數。
   *
   * 
   * @param readBuffer - 要檢索字節的緩衝區 
   * @param future - 代表操作結果的未來
   * @return true為建立寫入成功，false則否
   */
  virtual bool write(lang::ReadBuffer& readBuffer, lang::Future& future) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* LANG_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
