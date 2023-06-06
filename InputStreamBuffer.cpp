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
#include "./InputStreamBuffer.h"

#include "./System.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::InputStreamBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
InputStreamBuffer::InputStreamBuffer(void) {
  return;
}

//-------------------------------------------------------------------------------
InputStreamBuffer::~InputStreamBuffer(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> - lang::WriteBuffer
 */

//-------------------------------------------------------------------------------
bool InputStreamBuffer::isFull(void) const {
  if (this->mWriteBuffer == nullptr)
    return true;

  return this->mWriteBuffer->isFull();
}

//-------------------------------------------------------------------------------
int InputStreamBuffer::remaining(void) const {
  if (this->mWriteBuffer == nullptr)
    return 0;

  return this->mWriteBuffer->remaining();
}

//-------------------------------------------------------------------------------
int InputStreamBuffer::putByte(const char data) {
  if (this->mWriteBuffer == nullptr)
    return -1;

  int status = this->mWriteBuffer->putByte(data);

  if (status >= 0)
    ++this->mResult;

  if (status <= 0)
    this->execute();

  return status;
}

//-------------------------------------------------------------------------------
int InputStreamBuffer::put(lang::ReadBuffer& readBuffer) {
  return this->put(readBuffer, readBuffer.avariable());
}

//-------------------------------------------------------------------------------
int InputStreamBuffer::put(lang::ReadBuffer& readBuffer, int length) {
  if (this->mWriteBuffer == nullptr)
    return 0;

  int result = this->mWriteBuffer->put(readBuffer, length);
  this->mResult += result;

  if (this->mWriteBuffer->isFull())
    this->execute();

  return result;
}

//-------------------------------------------------------------------------------
int InputStreamBuffer::put(const void* buffer, int length) {
  if (this->mWriteBuffer == nullptr)
    return 0;

  int result = this->mWriteBuffer->put(buffer, length);
  this->mResult += result;

  if (this->mWriteBuffer->isFull())
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
