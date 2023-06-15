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
using mframe::io::ReadBuffer;
using mframe::io::WriteBuffer;
using mframe::lang::Runnable;
using mframe::lang::managerment::Kernel;
using mframe::lang::managerment::SystemConfig;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Svchost::Svchost(SystemConfig& config) : mOutputStream(*config.console.outputStream),
                                         mInputStream(*config.console.inputStream),
                                         mPrintBuffer(config.console.sizePrintBiffer),
                                         mRingBuffer(config.console.sizeScanner),
                                         mArrayQueue(config.svchost.taskQuantity) {
  this->mUserThread = nullptr;
  this->mCustomReadBuffer = nullptr;
  this->mCustomWriteBuffer = nullptr;
  this->mThread = &System::allocThread(*this, config.svchost.stackSize);

  if (this->mThread == nullptr)
    MFRAME_THROW("svchost thread alloc fail.", ErrorCode::NULL_POINTER);

  this->mStart = false;

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
 * Public Method <Override> - mframe::lang::managerment::SystemControl
 */

//-------------------------------------------------------------------------------
void Svchost::setCustomReadBuffer(mframe::io::ReadBuffer* readBuffer) {
  this->mOutputStream.abortWrite();
  this->mCustomReadBuffer = readBuffer;
  this->checkOutputStream();
}

//-------------------------------------------------------------------------------
void Svchost::setCustomWriteBuffer(mframe::io::WriteBuffer* writeBuffer) {
  this->mInputStream.abortRead();
  this->mCustomWriteBuffer = writeBuffer;
  this->checkInputStream();
}

/* ******************************************************************************
 * Public Method <Override> mframe::lang::Runnable
 */

//-------------------------------------------------------------------------------
void Svchost::run(void) {
  if (this->mStart)
    return;

  this->mStart = true;
  this->mAction = false;
  this->mStream = false;

  this->mUserThread->start("explorer");
  if (this->mUserThread == nullptr)
    MFRAME_THROW("explorer thread alloc fail.", ErrorCode::NULL_POINTER);

  while (this->mStart) {
    this->action();
    this->wait(100);
  }
}

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::CompletionHandler<int, void*>
 */

//-------------------------------------------------------------------------------
void Svchost::completed(int result, void* attachment) {
  this->mStream = false;
  this->mThread->notify();
  return;
}

//-------------------------------------------------------------------------------
void Svchost::failed(void* exc, void* attachment) {
  this->mStream = false;
  this->mThread->notify();
  return;
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
void Svchost::stop(void) {
  this->mStart = false;
  return;
}

//-------------------------------------------------------------------------------
bool Svchost::execute(Runnable& task) {
  if (!this->mArrayQueue.offer(&task))
    return false;

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
bool Svchost::start(Runnable& task, int stackSize) {
  if (this->mUserThread)
    return false;

  this->mThread->start("svchost");

  this->mUserThread = &System::allocThread(task, stackSize);

  if (this->mUserThread == nullptr)
    MFRAME_THROW("explorer thread alloc fail.", ErrorCode::NULL_POINTER);

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
  ReadBuffer* rb = &this->mPrintBuffer;
  if (this->mCustomReadBuffer)
    return rb = this->mCustomReadBuffer;

  if(rb->isEmpty())
    return false;

  return this->mOutputStream.write(*rb, this, this);
}

//-------------------------------------------------------------------------------
bool Svchost::checkInputStream(void) {
  WriteBuffer* rb = &this->mRingBuffer;
  if (this->mCustomWriteBuffer) 
    rb = this->mCustomWriteBuffer;

  if(rb->isFull())
    return false;

  return this->mInputStream.read(*rb, this, this);
}

/* ******************************************************************************
 * End of file
 */
