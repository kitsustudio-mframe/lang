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
#include "lang/EmptyReadBuffer.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::EmptyReadBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
EmptyReadBuffer::EmptyReadBuffer(void) {
  return;
}

//-------------------------------------------------------------------------------
EmptyReadBuffer::~EmptyReadBuffer(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 *  Public Method <Override> - lang::Iterable<char>
 */

//-------------------------------------------------------------------------------
bool peekIndex(int index, char& result){
  return false;
}

/* ******************************************************************************
 * Public Method <Override> - lang::ReadBuffer
 */

//-------------------------------------------------------------------------------
bool EmptyReadBuffer::isEmpty(void) const {
  return true;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::avariable(void) const {
  return 0;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::pollByte(char& result) {
  return 0;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::poll(lang::WriteBuffer& writeBuffer) {
  return 0;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::poll(lang::WriteBuffer& writeBuffer, int length) {
  return 0;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::poll(void* buffer, int bufferSize) {
  return 0;
}

//-------------------------------------------------------------------------------
int EmptyReadBuffer::skip(int value) {
  return 0;
}

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
