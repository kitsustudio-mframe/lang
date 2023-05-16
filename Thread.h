/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293
#define LANG_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Object.h"
#include "./Runnable.h"
#include "./ThreadPriority.h"
#include "./ThreadState.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  struct Thread;
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
struct lang::Thread : public lang::Runnable{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief Set the Name object
   * 
   * @param name 
   */
  virtual void setThreadName(const char* name) = 0;
  
  /**
   * @brief Get the Thread Name object
   * 
   * @return const char* 
   */
  virtual const char* getThreadName(void) const = 0;
    
  /**
   * @brief Get the Priority object
   * 
   * @return lang::ThreadPriority 
   */
  virtual lang::ThreadPriority getPriority(void) const = 0;

  /**
   * @brief Get the State object
   * 
   * @return lang::ThreadState 
   */
  virtual lang::ThreadState getState(void) const = 0;
    
  /**
   * @brief Get the Stack Size object
   * 
   * @return uint32_t 
   */
  virtual int getStackSize(void) const = 0;
    
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool start(void) = 0;
    
  /**
   * @brief 
   * 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool start(lang::ThreadPriority priority) = 0;
    
  /**
   * @brief 
   * 
   */
  virtual void notify(void) = 0;
    
  /**
   * @brief Set the Priority object
   * 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool setPriority(lang::ThreadPriority priority) = 0;  

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isActive(void) = 0;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
