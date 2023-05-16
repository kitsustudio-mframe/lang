/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdlib.h>

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./System.h"
#include "./Svchost.h"

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Extern
 */  

/* ****************************************************************************************
 * Using
 */  
using lang::System;

/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  
lang::Kernel* System::mKernel;
lang::Svchost* System::mSvchost;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new System object
 * 
 */
System::System(void){
  return;
}

/**
 * @brief Destroy the System object
 * 
 */
System::~System(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 */
void System::reboot(void){
  System::mKernel->kernelReboot();
  return;
}

/**
 * @brief 
 * 
 */
void System::setup(lang::Kernel& kernel){
  System::mKernel = &kernel;

  return;
}

/**
 * @brief 
 * 
 * @param userThread 
 */
void System::start(lang::Runnable& task, uint32_t stackSize, uint32_t svchostStackSize){
  System::mKernel->kernelInitialize();
  System::mSvchost = new lang::Svchost(task, stackSize);
  System::mKernel->kernelStart(*System::mSvchost, svchostStackSize);
  return;
}

/**
 * 
 */
void System::error(const void* address, ErrorCode code){
  /*
  bool result = false;
  if(System::mSystemRegister->mErrorCodeHandler){
    result = System::mSystemRegister->mErrorCodeHandler(address, code);
  }
  
  if(result)
    return;
  */
  while(1);
}

/**
 *
 */
uint32_t System::getCoreClock(void){
  return System::mKernel->kernelGetCoreClock();
}

/**
 * @brief 
 * 
 * @param runnable 
 * @return true 
 * @return false 
 */
void System::execute(lang::Runnable& runnable){
  if(System::mSvchost->execute(runnable))
    return;
  
  runnable.run();
  return;
}


/**
 * @brief 
 * 
 * @param times 
 */
void System::lowerDelay(uint32_t times){
#pragma clang optimize off
  while(times){
    --times;
  }
#pragma clang optimize on
}


/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
