/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_DB2618AE_F498_4792_900C_A4BD1DC2E35C
#define LANG_DB2618AE_F498_4792_900C_A4BD1DC2E35C

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./Object.h"

//-----------------------------------------------------------------------------------------
#include "./ErrorCode.h"
#include "./Thread.h"
#include "./Kernel.h"
#include "./Runnable.h"
#include "./Svchost.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class System; 
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
class lang::System final : public lang::Object{
  friend Object;
  
  /* **************************************************************************************
   * Variable <Public>
   */
  
  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    static lang::Kernel* mKernel;
    static lang::Svchost* mSvchost;
  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private:
  
    /**
     * @brief Construct a new System object
     * 
     */
    System(void);

    /**
     * @brief Destroy the System object
     * 
     */
    virtual ~System(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:

    /**
     * @brief 設備重新啟動
     * 
     */
    static void reboot(void);
    
    /**
     * @brief 
     * 
     */
   static void setup(lang::Kernel& kernel);    
      
    /**
     * @brief 系統初始化核心
     * 
     * @param kernel 核心方法，建議使用CMSIS-RTOS2 
     */
   static void start(lang::Runnable& task, uint32_t stackSize, uint32_t svchostStackSize);

    /**
     * @brief 核心啟動
     * 
     * @param address 
     * @param code
     */
    static void error(const void* address, ErrorCode code);
    
    /**
     * @brief Get the Core Clock object
     * 
     * @return uint32_t 
     */
    static uint32_t getCoreClock(void);
    
    /**
     * @brief 
     * 
     * @param times 
     */
    static void lowerDelay(uint32_t times);
  
    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    static void execute(lang::Runnable& runnable);
    
    /**
     *
     */
    static Thread& allocThread(lang::Runnable& runnable);
    
    /**
     *
     */
    static Thread& allocThread(lang::Runnable& runnable, lang::Data& stackMemory);
    
  /* **************************************************************************************
   * Public Method <Inline Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */
  
  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};

using lang::System;

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
