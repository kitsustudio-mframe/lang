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
#include "./OutputStreamBuffer.h"

#include "./System.h"
/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::OutputStreamBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
OutputStreamBuffer::OutputStreamBuffer(void) {
  this->mResult = 0;
  this->mHandling = false;
  return;
}

//-------------------------------------------------------------------------------
OutputStreamBuffer::~OutputStreamBuffer(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> - lang::ReadBuffer
 */

//-------------------------------------------------------------------------------
bool OutputStreamBuffer::isEmpty(void) const {
  if (this->mReadBuffer == nullptr)
    return true;

  return this->mReadBuffer->isEmpty();
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::avariable(void) const {
  if (this->mReadBuffer == nullptr)
    return 0;

  return this->mReadBuffer->avariable();
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::getByte(char& result) {
  if (this->mReadBuffer == nullptr)
    return 0;

  int status = this->mReadBuffer->getByte(result);

  if (status >= 0)
    ++this->mResult;

  if (status <= 0)
    this->execute();

  return status;
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::get(lang::WriteBuffer& writeBuffer) {
  if (this->mReadBuffer == nullptr)
    return 0;

  int result = this->mReadBuffer->get(writeBuffer);

  if (this->mReadBuffer->isEmpty())
    this->execute();

  return result;
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::get(lang::WriteBuffer& writeBuffer, int length) {
  if (this->mReadBuffer == nullptr)
    return 0;

  int result = this->mReadBuffer->get(writeBuffer, length);

  if (this->mReadBuffer->isEmpty())
    this->execute();

  return result;
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::get(void* buffer, int bufferSize) {
  if (this->mReadBuffer == nullptr)
    return 0;

  int result = this->mReadBuffer->get(buffer, bufferSize);

  if (this->mReadBuffer->isEmpty())
    this->execute();

  return result;
}

//-------------------------------------------------------------------------------
int OutputStreamBuffer::skip(int value) {
  if (this->mReadBuffer == nullptr)
    return 0;

  int result = this->mReadBuffer->skip(value);

  if (this->mReadBuffer->isEmpty())
    this->execute();

  return result;
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
