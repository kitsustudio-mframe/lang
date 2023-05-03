/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55
#define LANG_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55

/* ****************************************************************************************
 * Include
 */

#include "./InputBuffer.h"
#include "./CompletionHandler.h"
#include "./Future.h"
#include "./Object.h"
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  interface InputStream;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
interface lang::InputStream extends virtual lang::Interface{

  /* **************************************************************************************
   *  Method <Public>
   */
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abortRead(void) abstract;  
  
  /**
   * @brief 
   * 
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool readBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param outputBuffer 
   * @return int 
   */
  virtual bool read(lang::InputBuffer& inputBuffer, int timeout) abstract;
  
  /**
   * @brief nonblocking
   * 
   * @param outputBuffer 
   * @param attachment 
   * @param handler 
   * @return true successful.
   * @return false fail.
   */
  virtual bool read(lang::InputBuffer& inputBuffer, 
                    void* attachment,
                    lang::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param outputBuffer 
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool read(lang::InputBuffer& inputBuffer, lang::Future& future) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @param attachment 
   * @param handler 
   * @return true 
   * @return false 
   */
  virtual bool skip(int value, 
                    void* attachment,
                    lang::CompletionHandler<int, void*>* handler) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @param future 
   * @return true 
   * @return false 
   */
  virtual bool skip(int value, lang::Future& future) abstract;

};

/* *****************************************************************************************
 *    End of file
 */ 

#endif /* LANG_C4AC526D_9A52_4C98_93F6_8C1F0EB6CB55 */
