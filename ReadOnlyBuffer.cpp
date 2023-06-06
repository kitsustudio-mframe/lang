/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

#include <string.h>

//-------------------------------------------------------------------------------
#include "./ReadOnlyBuffer.h"
#include "./WriteBuffer.h"
//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::ReadOnlyBuffer;
using lang::WriteBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
ReadOnlyBuffer::ReadOnlyBuffer(const char* str) : Data(str, strlen(str)) {
  this->mPosition = 0;
  return;
}

//-------------------------------------------------------------------------------
ReadOnlyBuffer::ReadOnlyBuffer(const void* pointer, size_t length) : Data(pointer, length) {
  this->mPosition = 0;
  return;
}

//-------------------------------------------------------------------------------
ReadOnlyBuffer::~ReadOnlyBuffer(void) {
  this->mPosition = 0;
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
int ReadOnlyBuffer::pollByte(char& result) {
  if (this->isEmpty())
    return -1;

  result = *static_cast<char*>(this->pointer(this->mPosition));
  ++this->mPosition;

  return this->avariable();
}

//-------------------------------------------------------------------------------
int ReadOnlyBuffer::poll(lang::WriteBuffer& writeBuffer) {
  return ReadOnlyBuffer::poll(writeBuffer, this->avariable());
}

//-------------------------------------------------------------------------------
int ReadOnlyBuffer::poll(lang::WriteBuffer& writeBuffer, int length) {
  if (this->isEmpty())
    return 0;

  int max = this->avariable();
  if (length > max)
    length = max;

  int result = writeBuffer.put(this->pointer(mPosition), this->avariable());
  this->mPosition += result;
  return result;
}

//-------------------------------------------------------------------------------
int ReadOnlyBuffer::poll(void* buffer, int bufferSize) {
  if (this->isEmpty())
    return 0;

  int result = this->length();
  if (result >= bufferSize)
    bufferSize = result;

  if (buffer != nullptr)
    this->copyTo(buffer, 0, this->mPosition, bufferSize);

  this->mPosition += result;
  return result;
}

//-------------------------------------------------------------------------------
int ReadOnlyBuffer::skip(int value) {
  return this->poll(nullptr, value);
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool ReadOnlyBuffer::position(int newPosition) {
  if (newPosition < 0)
    return false;

  if (newPosition > this->capacity())
    return false;

  this->mPosition = newPosition;
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

/* ******************************************************************************
 * End of file
 */
