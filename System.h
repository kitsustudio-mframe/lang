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


/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class System;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::System final extends lang::Object{
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
     * @brief 
     * 
     */
    static void reboot(void);
    
    /**
     * @brief 
     * 
     */
    static void setup(lang::SystemConfig& config);    
      
    /**
     * @brief 
     * 
     * @param userThread 
     */
    static void start();

    /**
     * @brief 
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
