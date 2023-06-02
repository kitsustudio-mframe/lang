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
#include "./System.h"

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
  this->mResult = 0;
  this->mHandling = false;
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
 * Public Method <Override> - lang::Runnable
 */

//-------------------------------------------------------------------------------
void OutputStream::run(void){
  CompletionHandler<int, void*>* handler = this->mCompletionHandler;
  void* attachment = this->mAttachment;
  int result = this->mResult;

  this->mResult = 0;
  this->mReadBuffer = nullptr;
  this->mHandling = false;
  
  if (handler)
    handler->completed(result, attachment);

  return;
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool OutputStream::abortWrite(void) {
  if (!this->writeBusy())
    return false;

  this->execute();
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
  if (future.isBusy())
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
  this->mResult = 0;

  if (readBuffer.isEmpty())
    this->execute();

  this->onWriteEvent();
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
void OutputStream::execute(void) {
  if (!this->writeBusy())
    return;

  if(this->mHandling)
    return;

  this->mHandling = true;
  System::execute(*this);
  return;
}

//-------------------------------------------------------------------------------
void OutputStream::onWriteEvent(void){
  return;
}

/* ******************************************************************************
 * End of file
 */
