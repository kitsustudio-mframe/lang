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
#include "./InputStream.h"
#include "./System.h"


/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::InputStream;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
InputStream::InputStream(void) {
  this->mAttachment = nullptr;
  this->mCompletionHandler = nullptr;
  this->mWriteBuffer = nullptr;
  this->mResult = 0;
  this->mHandling = false;
  return;
}

//-------------------------------------------------------------------------------
InputStream::~InputStream(void) {
  this->abortRead();
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
void InputStream::run(void){
  CompletionHandler<int, void*>* handler = this->mCompletionHandler;
  void* attachment = this->mAttachment;
  int result = this->mResult;

  this->mResult = 0;
  this->mWriteBuffer = nullptr;
  this->mHandling = false;
  
  if (handler)
    handler->completed(result, attachment);

  return;
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool InputStream::abortRead(void) {
  if (!this->readBusy())
    return false;

  this->execute();
  return true;
}

//-------------------------------------------------------------------------------
bool InputStream::readBusy(void) {
  return (this->mWriteBuffer != nullptr);
}

//-------------------------------------------------------------------------------
bool InputStream::read(lang::WriteBuffer& writeBuffer, int timeout) {
  Future future = Future();
  if (this->read(writeBuffer, future) == false)
    return false;

  future.waitDone(timeout);
  if (future.isBusy())
    this->abortRead();

  future.waitDone();
  return true;
}

//-------------------------------------------------------------------------------
bool InputStream::read(lang::WriteBuffer& writeBuffer,
                       void* attachment,
                       lang::CompletionHandler<int, void*>* handler) {
  if (this->readBusy())
    return false;

  this->mWriteBuffer = &writeBuffer;
  this->mAttachment = attachment;
  this->mCompletionHandler = handler;
  this->mResult = 0;

  if (this->mWriteBuffer->isFull())
    this->execute();

  this->onReadEvent();
  return true;
}

//-------------------------------------------------------------------------------
bool InputStream::read(lang::WriteBuffer& writeBuffer, lang::Future& future) {
  if (!future.isIdle())
    return false;

  future.setWait();
  bool result = this->read(writeBuffer, nullptr, &future);
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
void InputStream::execute(void) {
  if (!this->readBusy())
    return;

  if(this->mHandling)
    return;

  this->mHandling = true;
  System::execute(*this);
  return;
}

//-------------------------------------------------------------------------------
void InputStream::onReadEvent(void) {
  return;
}
/* ******************************************************************************
 * End of file
 */
