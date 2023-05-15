/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_E5B93ACC_6FA3_4527_B356_93D76C4F913E
#define LANG_E5B93ACC_6FA3_4527_B356_93D76C4F913E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./Interface.h"
#include "./Runnable.h"
#include "./Thread.h"
#include "./InputBuffer.h"
#include "./OutputBuffer.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  interface Kernel;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface lang::Kernel extends virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool kernelInitialize(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool kernelStart(lang::Runnable& runnable, uint32_t stackSize) abstract;

  /**
   * @brief 
   * 
   * @return int 
   */
  virtual int kernelLock(void) abstract;

  /**
   * @brief 
   * 
   * @return int 
   */
  virtual int kernelUnlock(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t kernelGetTickCount(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t kernelGetTickFreq(void) abstract;
  
  /**
   * @brief 
   * 
   * @return uint32_t Thread ID.
   */
  virtual uint32_t kernelGetThreadId(void) abstract;
  
  /**
   * @brief 
   *  
   */
  virtual bool kernelDelay(uint32_t milliseconds) const abstract;
  
  /**
   * @brief 
   * 
   * @param timeout 
   * @return true 
   * @return false 
   */
  virtual bool kernelWait(uint32_t timeout) const abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual void kernelReboot(void) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual Thread* kerneAllocThread(lang::Runnable& task) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual Thread* kerneAllocThread(lang::Runnable& task, int stackSize) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual Thread* kerneGetCurrentThread(void) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual Thread* kerneGetThread(uint32_t threadID) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual InputBuffer* kernelGetInputBuffer(void) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual OutputBuffer* kernelGetOutputBuffer(void) abstract;
  
  /**
   * @brief 
   *
   * @return
   */
  virtual uint32_t kerneGetCurrentThreadID(void) abstract;  
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_E5B93ACC_6FA3_4527_B356_93D76C4F913E */
