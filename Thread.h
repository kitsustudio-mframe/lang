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
struct lang::Thread : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */
  /**
   * @brief Get the Thread Name object
   * 
   * @return const char* 
   */
  virtual const char* getThreadName(void) const abstract;
    
  /**
   * @brief Get the Priority object
   * 
   * @return lang::ThreadPriority 
   */
  virtual lang::ThreadPriority getPriority(void) const abstract;

  /**
   * @brief Get the State object
   * 
   * @return lang::ThreadState 
   */
  virtual lang::ThreadState getState(void) const abstract;
    
  /**
   * @brief Get the Stack Size object
   * 
   * @return uint32_t 
   */
  virtual int getStackSize(void) const abstract;
    
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool start(const char* name) abstract;
    
  /**
   * @brief 
   * 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool start(const char* name, lang::ThreadPriority priority) abstract;
    
  /**
   * @brief 
   * 
   */
  virtual void notify(void) abstract;
    
  /**
   * @brief Set the Priority object
   * 
   * @param priority 
   * @return true 
   * @return false 
   */
  virtual bool setPriority(lang::ThreadPriority priority) abstract;  

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isActive(void) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
