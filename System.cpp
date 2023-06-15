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
namespace mframe::lang {
  static mframe::lang::managerment::Kernel* mKernel = nullptr;
  static mframe::lang::managerment::HardwareInfo* mHardwareInfo = nullptr;
  static mframe::lang::managerment::Allocator* mAllocator = nullptr;
  static mframe::lang::managerment::Svchost* mSvchost = nullptr;
}  // namespace mframe::lang

/* ******************************************************************************
 * Extern
 */

/* ******************************************************************************
 * Using
 */
using mframe::lang::System;

//-------------------------------------------------------------------------------
using namespace mframe::lang;
using mframe::io::PrintBuffer;
using mframe::lang::managerment::Kernel;
using mframe::lang::managerment::Svchost;

/* ******************************************************************************
 * Global Operator
 */
//-------------------------------------------------------------------------------
void* operator new(size_t n) {
  if (mAllocator)
    return mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-------------------------------------------------------------------------------
void* operator new[](size_t n) {
  if (mAllocator)
    return mAllocator->allocAlignment64(static_cast<int>(n));

  else
    return malloc(n);
}

//-------------------------------------------------------------------------------
void operator delete(void* p) {
  if (mAllocator)
    mAllocator->free(p);

  else
    free(p);
}

/* ******************************************************************************
 * Static Variable
 */

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
  return mSvchost->mPrintBuffer;
}

//-------------------------------------------------------------------------------
mframe::io::ReadBuffer& System::in(void) {
  return mSvchost->mRingBuffer;
}

//-------------------------------------------------------------------------------
void System::reboot(void) {
  mKernel->kernelReboot();
  return;
}

//-------------------------------------------------------------------------------
void System::setup(mframe::lang::managerment::SystemConfig& systemConfig) {
  if (mSvchost)
    return;

  mKernel = systemConfig.system.kernel;
  mAllocator = systemConfig.system.allocator;
  mHardwareInfo = systemConfig.system.hardwareInfo;

  if (mKernel->kernelInitialize() == false)
    System::error("SYSTEM", mframe::lang::ErrorCode::SYSTEM_ERROR);

  mSvchost = new Svchost(systemConfig);
  return;
}

//-------------------------------------------------------------------------------
void System::start(mframe::lang::Runnable& task, int stackSize) {
  if (mSvchost->start(task, stackSize))
    mKernel->kernelStart();

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
void System::throwError(const char* message, const char* path, ErrorCode code) {
  while (1)
    ;
}

//-------------------------------------------------------------------------------
int System::getCoreClock(void) {
  if (mHardwareInfo)
    return mHardwareInfo->systemClock();

  else
    return -1;
}

//-------------------------------------------------------------------------------
void System::execute(mframe::lang::Runnable& runnable) {
  if (mSvchost->execute(runnable))
    return;

  runnable.run();
  return;
}

//-------------------------------------------------------------------------------
mframe::lang::Thread& System::allocThread(mframe::lang::Runnable& runnable, int stackSize) {
  mframe::lang::Thread* result = mKernel->kernelAllocThread(runnable, stackSize);

  if (result == nullptr)
    System::error("SYSTEM", mframe::lang::ErrorCode::SYSTEM_ERROR);

  return *result;
}

//-------------------------------------------------------------------------------
mframe::lang::Thread& System::allocThread(mframe::lang::Runnable& runnable, mframe::lang::Data& stackMemory) {
  mframe::lang::Thread* result = mKernel->kernelAllocThread(runnable, stackMemory);

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
  return mKernel->kernelDelay(static_cast<uint32_t>(milliseconds));
}

//-------------------------------------------------------------------------------
void System::wait(void) {
  System::wait(0);
}

//-------------------------------------------------------------------------------
bool System::wait(int timeout) {
  return mKernel->kernelWait(static_cast<uint32_t>(timeout));
}

//-------------------------------------------------------------------------------
bool System::yield(void) {
  return mKernel->kenrelYield();
}

//-------------------------------------------------------------------------------
mframe::lang::Thread* System::currentThread(void) {
  return mKernel->kernelGetCurrentThread();
}

//-------------------------------------------------------------------------------
int System::lock(void) {
  return mKernel->kernelLock();
}

//-------------------------------------------------------------------------------
int System::unlock(void) {
  return mKernel->kernelUnlock();
}

//-------------------------------------------------------------------------------
mframe::lang::managerment::Allocator* System::getAllocator(void) {
  return mAllocator;
}

//-------------------------------------------------------------------------------
mframe::lang::managerment::SystemControl& System::getControl(void){
  return *mSvchost;
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
