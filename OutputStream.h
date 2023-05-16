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
   * 
   */
  virtual bool abortWrite(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool writeBusy(void) abstract;
  
  /**
   * @brief write witt io mode.
   * 
   * @param outputBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(lang::ReadBuffer& outputBuffer, int timeout) abstract;  
  
  /**
   * @brief write with aio mode.
   * 
   * @param outputBuffer
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool write(lang::ReadBuffer& outputBuffer, 
                     void* attachment,
                     lang::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief write with nio mode.
   * 
   * @param outputBuffer
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool write(lang::ReadBuffer& outputBuffer, lang::Future& future) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* LANG_CE4E94B8_1588_4FED_8DB8_1C22B3E8CDB4 */
