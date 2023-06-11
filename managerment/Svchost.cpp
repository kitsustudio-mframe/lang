/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./Svchost.h"

//-------------------------------------------------------------------------------
#include "mframe.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */
using mframe::lang::managerment::Svchost;

//-------------------------------------------------------------------------------
using mframe::io::InputStream;
using mframe::io::OutputStream;
using mframe::lang::Runnable;
using mframe::lang::managerment::Kernel;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Svchost::Svchost(Kernel& kernel,
                 uint32_t outSize,
                 uint32_t inSize,
                 uint32_t taskQuanity) : mKernel(kernel),
                                         mPrintBuffer(outSize),
                                         mRingBuffer(inSize),
                                         mArrayQueue(taskQuanity) {
  this->mUserThread = nullptr;
  this->mThread = nullptr;
  return;
}

//-------------------------------------------------------------------------------
Svchost::~Svchost(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> mframe::lang::Runnable
 */

//-------------------------------------------------------------------------------
void Svchost::run(void) {
  if (this->mThread)
    return;

  this->mThread = this->currentThread();
  this->mStart = true;
  this->mAction = false;
  this->mStream = false;

  this->mUserThread->start("explorer");

  while (this->mStart) {
    this->action();
    this->wait(20);
  }
}

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::CompletionHandler<int, void*>
 */

//-------------------------------------------------------------------------------
void Svchost::completed(int result, void* attachment) {
  this->mStream = false;
  this->mThread->notify();
}

//-------------------------------------------------------------------------------
void Svchost::failed(void* exc, void* attachment) {
  this->mStream = false;
  this->mThread->notify();
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
void Svchost::stop(void) {
  this->mStart = false;
}

//-------------------------------------------------------------------------------
bool Svchost::execute(Runnable& task) {
  if (!this->mArrayQueue.offer(&task))
    return false;

  this->mThread->notify();
  return true;
}

//-------------------------------------------------------------------------------
bool Svchost::action(void) {
  if (this->mAction)
    return false;

  this->mAction = true;

  if (!this->mStream) {
    this->mStream = this->checkOutputStream();
    this->mStream &= this->checkInputStream();
  }

  while (true) {
    Runnable* runnable = this->mArrayQueue.poll();
    if (runnable == nullptr)
      break;

    runnable->run();
  }

  this->mAction = false;
  return true;
}

//-------------------------------------------------------------------------------
bool Svchost::start(Runnable& task, uint32_t stackSize) {
  if (this->mUserThread)
    return false;

  this->mUserThread = &mframe::lang::System::allocThread(task, stackSize);
  return true;
}

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

//-------------------------------------------------------------------------------
bool Svchost::checkOutputStream(void) {
  if (this->mPrintBuffer.isEmpty())
    return false;

  OutputStream* o = this->mKernel.kernelGetOutputStream();
  if (o == nullptr)
    return false;

  return o->write(this->mPrintBuffer, this, this);
}

//-------------------------------------------------------------------------------
bool Svchost::checkInputStream(void) {
  if (this->mRingBuffer.isFull())
    return false;

  InputStream* i = this->mKernel.kernelGetInputStream();
  if (i == nullptr)
    return false;

  return i->read(this->mRingBuffer, this, this);
}

/* ******************************************************************************
 * End of file
 */
