/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./OutputStream.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::OutputStream;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
OutputStream::OutputStream(void) {
  this->mAttachment = nullptr;
  this->mCompletionHandler = nullptr;
  this->mReadBuffer = nullptr;
  return;
}

//-------------------------------------------------------------------------------
OutputStream::~OutputStream(void) {
  this->abortWrite();
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool OutputStream::abortWrite(void) {
  if (!this->writeBusy())
    return false;

  this->execute(0);
  return true;
}

//-------------------------------------------------------------------------------
bool OutputStream::writeBusy(void) {
  return (this->mReadBuffer != nullptr);
}

//-------------------------------------------------------------------------------
bool OutputStream::write(lang::ReadBuffer& readBuffer, int timeout) {
  Future future = Future();
  if (this->write(readBuffer, future) == false)
    return false;

  future.waitDone(timeout);
  if (future.isDone() == false)
    this->abortWrite();

  future.waitDone();
  return true;
}

//-------------------------------------------------------------------------------
bool OutputStream::write(lang::ReadBuffer& readBuffer,
                         void* attachment,
                         lang::CompletionHandler<int, void*>* handler) {
  if (this->writeBusy())
    return false;

  this->mReadBuffer = &readBuffer;
  this->mCompletionHandler = handler;
  this->mAttachment = attachment;

  if(readBuffer.isEmpty())
    this->execute(0);

  return true;
}

//-------------------------------------------------------------------------------
bool OutputStream::write(lang::ReadBuffer& readBuffer, lang::Future& future) {
  if (!future.isIdle())
    return false;

  future.setWait();
  bool result = this->write(readBuffer, nullptr, &future);
  if (result == false)
    future.clear();

  return result;
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
void OutputStream::execute(int result) {
  if (!this->writeBusy())
    return;

  CompletionHandler<int, void*>* handler = this->mCompletionHandler;
  void* attachment = this->mAttachment;

  this->mReadBuffer = nullptr;

  if (handler)
      handler->completed(result, attachment);
    
  return;
}

/* ******************************************************************************
 * End of file
 */
