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
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool InputStream::abortRead(void) {
  if (!this->readBusy())
    return false;

  this->execute(0);
  return true;
}

//-------------------------------------------------------------------------------
bool InputStream::readBusy(void) {
  return (this->mWriteBuffer != nullptr);
}

//-------------------------------------------------------------------------------
bool InputStream::read(lang::WriteBuffer& writeBuffer, int timeout) {
  Future future = Future();
  bool result = this->read(writeBuffer, future);
  if (result)
    future.waitDone(timeout);

  return result;
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
  this->mResult = -1;

  if (this->mWriteBuffer->isFull())
    this->execute(0);

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
void InputStream::execute(int result) {
  if (!this->readBusy())
    return;

  CompletionHandler<int, void*>* handler = this->mCompletionHandler;
  void* attachment = this->mAttachment;

  this->mWriteBuffer = nullptr;

  if (handler)
    handler->completed(result, attachment);

  return;
}

/* ******************************************************************************
 * End of file
 */
