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
lang::SystemConfig System::config;

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
  System::config.kernel->kernelReboot();
  return;
}

/**
 * @brief 
 * 
 */
void System::setup(lang::SystemConfig& config){
  System::config = config;
  return;
}

/**
 * @brief 
 * 
 * @param userThread 
 */
void System::start(void){
  System::config.kernel->kernelInitialize();
  System::config.kernel->kernelStart();
  /*
  System::sKernel->kernelInitialize();
  

  
  
  System::mCoreThread 
    = new CoreThread(langCoreEcecutorTaskNumber, 
                     &userThread);
  
  System::mCoreThread->start();
  System::sKernel->kernelStart();
  
  delete System::mCoreThread;
  System::mCoreThread = nullptr;
  */
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
  return 0;
}

/**
 * @brief 
 * 
 * @param runnable 
 * @return true 
 * @return false 
 */
void System::execute(lang::Runnable& runnable){

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
