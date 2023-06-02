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
#include "./StreamSkipper.h"

//-------------------------------------------------------------------------------
#include "./ReadBuffer.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::StreamSkipper;
using lang::ReadBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
StreamSkipper::StreamSkipper(void){
  this->mPosition abstract;
  this->mCapacity abstract;
  return;
}

//-------------------------------------------------------------------------------
StreamSkipper::~StreamSkipper(void){
  this->mPosition abstract;
  this->mCapacity abstract;
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> - lang::InputBuffer
 */

//-------------------------------------------------------------------------------
int StreamSkipper::putByte(const char result){
  if(this->isFull())
    return -1;

  ++this->mPosition;
  return this->remaining();
}

//-------------------------------------------------------------------------------
int StreamSkipper::put(ReadBuffer& outputBuffer){
  int result = outputBuffer.skip(this->remaining());
  this->mPosition += result;
  return result;
}

//-------------------------------------------------------------------------------
int StreamSkipper::put(ReadBuffer& outputBuffer, int length){ 
  int max = this->remaining();
  if(length > max)
    length = max;
  
  int result = outputBuffer.skip(length);
  this->mPosition += result;
  return result;
}   

//-------------------------------------------------------------------------------
int StreamSkipper::put(const void* buffer, int length){
  if(this->isFull())
    return 0;

  int result = this->remaining();
  if(result > length)
    result = length;

  this->mPosition += result;
  return result;
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
