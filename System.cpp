/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./System.h"

//-------------------------------------------------------------------------------
#include <stdlib.h>

#include "mframe.h"

/* ******************************************************************************
 * Namespace
 */

/* ******************************************************************************
 * Extern
 */

/* ******************************************************************************
 * Using
 */
using mframe::lang::System;

//-------------------------------------------------------------------------------
using mframe::io::PrintBuffer;
using mframe::lang::managerment::Kernel;
using mframe::lang::managerment::Svchost;

/* ******************************************************************************
 * Global Operator
 */

/* ******************************************************************************
 * Static Variable
 */
Svchost* System::mSvchost;

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
System::System(void) {
  return;
}

//-------------------------------------------------------------------------------
System::~System(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
PrintBuffer& System::out(void) {
  return System::mSvchost->mPrintBuffer;
}

//-------------------------------------------------------------------------------
mframe::io::ReadBuffer& System::in(void) {
  return System::mSvchost->mRingBuffer;
}

//-------------------------------------------------------------------------------
void System::reboot(void) {
  System::mSvchost->mKernel.kernelReboot();
  return;
}

//-------------------------------------------------------------------------------
void System::setup(Kernel& kernel) {
  System::setup(kernel, 128, 128);
}

//-------------------------------------------------------------------------------
void System::setup(Kernel& kernel, uint32_t outSize, uint32_t inSize) {
  System::mSvchost = new Svchost(kernel, outSize, inSize, 32);
  if (System::mSvchost->mKernel.kernelInitialize() == false)
    System::error("SYSTEM", mframe::lang::ErrorCode::SYSTEM_ERROR);

  return;
}

//-------------------------------------------------------------------------------
void System::start(mframe::lang::Runnable& task, uint32_t stackSize, uint32_t svchostStackSize) {
  System::mSvchost->start(task, stackSize);
  System::mSvchost->mKernel.kernelStart(*System::mSvchost, svchostStackSize);
  return;
}

//-------------------------------------------------------------------------------
void System::error(const void* address, ErrorCode code) {
  /*
  bool result = false;
  if(System::mSystemRegister->mErrorCodeHandler){
    result = System::mSystemRegister->mErrorCodeHandler(address, code);
  }

  if(result)
    return;
  */
  while (1)
    ;
}

//-------------------------------------------------------------------------------
uint32_t System::getCoreClock(void) {
  return System::mSvchost->mKernel.kernelGetCoreClock();
}

//-------------------------------------------------------------------------------
void System::execute(mframe::lang::Runnable& runnable) {
  if (System::mSvchost->execute(runnable))
    return;

  runnable.run();
  return;
}

//-------------------------------------------------------------------------------
mframe::lang::Thread& System::allocThread(mframe::lang::Runnable& runnable, uint32_t stackSize) {
  mframe::lang::Thread* result = System::mSvchost->mKernel.kernelAllocThread(runnable, stackSize);

  if (result == nullptr)
    System::error("SYSTEM", mframe::lang::ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-------------------------------------------------------------------------------
mframe::lang::Thread& System::allocThread(mframe::lang::Runnable& runnable, mframe::lang::Data& stackMemory) {
  mframe::lang::Thread* result = System::mSvchost->mKernel.kernelAllocThread(runnable, stackMemory);

  if (result == nullptr)
    System::error("SYSTEM", mframe::lang::ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-------------------------------------------------------------------------------
void System::lowerDelay(uint32_t times) {
#pragma clang optimize off
  while (times) {
    --times;
  }
#pragma clang optimize on
}

//-------------------------------------------------------------------------------
bool System::delay(int milliseconds) {
  return System::mSvchost->mKernel.kernelDelay(static_cast<uint32_t>(milliseconds));
}

//-------------------------------------------------------------------------------
void System::wait(void) {
  System::wait(0);
}

//-------------------------------------------------------------------------------
bool System::wait(int timeout) {
  return System::mSvchost->mKernel.kernelWait(static_cast<uint32_t>(timeout));
}

//-------------------------------------------------------------------------------
bool System::yield(void) {
  return System::mSvchost->mKernel.kenrelYield();
}

//-------------------------------------------------------------------------------
mframe::lang::Thread* System::currentThread(void) {
  return System::mSvchost->mKernel.kernelGetCurrentThread();
}

//-------------------------------------------------------------------------------
int System::lock(void) {
  return System::mSvchost->mKernel.kernelLock();
}

//-------------------------------------------------------------------------------
int System::unlock(void) {
  return System::mSvchost->mKernel.kernelUnlock();
}

/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

/* ******************************************************************************
 * Protected Method <Static>
 */

/* ******************************************************************************
 * Protected Method <Override>
 */

/* ******************************************************************************
 * Protected Method
 */

/* ******************************************************************************
 * Private Method
 */

/* ******************************************************************************
 * End of file
 */
