/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./Data.h"

//-------------------------------------------------------------------------------
#include "mframe.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */
using mframe::lang::Data;

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Data::Data(void) : Pointer() {
  this->mLength = 0;
  return;
}

//-------------------------------------------------------------------------------
Data::Data(const void* pointer, int length) : Pointer(pointer) {
  if(length < 0)
  length = 0;

  this->mLength = (static_cast<uint32_t>(length) | 0x80000000);
  return;
}

//-------------------------------------------------------------------------------
Data::Data(void* pointer, int length) : Pointer(pointer) {
  if(length < 0)
  length = 0;
  
  Data::mLength = static_cast<uint32_t>(length);
}

//-------------------------------------------------------------------------------
Data::Data(const Data& other) {
  *this = other;
  return;
}

//-------------------------------------------------------------------------------
Data::~Data(void) {
  Data::mLength = 0;
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
void Data::wipe(void* pointer, uint8_t value, int length) {
  if (length <= 0)
    return;

  Pointers::wipe(pointer, value, length);
  return;
}

//-------------------------------------------------------------------------------
void Data::wipe(void* pointer, int length) {
  Data::wipe(pointer, 0x00, length);
  return;
}

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::Pointer
 */

//-------------------------------------------------------------------------------
int Data::copy(const void* source, int shift, int start, int length) {
  if (length <= 0)
    return 0;

  if (Data::isReadOnly())
    return 0;

  int max = Data::length();

  if (shift > max)
    return 0;

  if (length > (max - shift))
    length = (max - shift);

  return Pointer::copy(source, shift, start, length);
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
int Data::wipe(uint8_t value, int start, int length) {
  if (Data::isReadOnly())
    return 0;

  if (length <= 0)
    return 0;

  int max = Data::length();
  if ((start + length) > max)
    length = max - start;

  Pointers::wipe(Data::pointer(start), value, length);
  return length;
}

//-------------------------------------------------------------------------------
bool Data::inRange(void* address) const {
  uint32_t start = reinterpret_cast<uint32_t>(Data::pointer());
  uint32_t end = start + static_cast<uint32_t>(Data::length());
  uint32_t adr = reinterpret_cast<uint32_t>(address);

  if ((adr < start) && (adr >= end))
    return false;

  return true;
}

//-------------------------------------------------------------------------------
Data Data::subData(int beginIndex, int length) const {
  int max = Data::length();

  if (beginIndex >= max)
    return Data();

  int remainingLength = (max - beginIndex);
  if (length >= remainingLength)
    length = remainingLength;

  return Data(Data::pointer(static_cast<int>(beginIndex)), length);
}

//-------------------------------------------------------------------------------
int Data::insertArray(const void* source, int shift, int start, int length) {
  if (length <= 0)
    return 0;

  int max = Data::length();

  if (start + length > max)
    length = max - start;

  int less = max - (start + length);

  if (less != 0)
    Data::copy(Data::pointer(start), 0, (start + length), less);

  Data::copy(source, 0, start, length);

  return 0;
}

//-------------------------------------------------------------------------------
int Data::popArray(void* source, int shift, int start, int length) {
  if (length <= 0)
    return 0;

  int max = Data::length();

  if (start + length > max)
    length = max - start;

  int less = max - (start + length);

  if (source != nullptr)
    Data::copyTo(source, shift, start, length);

  if (less != 0)
    Data::copy(Data::pointer(start), 0, (start + length), less);

  Data::wipe(0x00, (start + less), length);

  return length;
}

//-------------------------------------------------------------------------------
int Data::indexOf(char ch) const {
  return Data::indexOf(ch, 0);
}

//-------------------------------------------------------------------------------
int Data::indexOf(char ch, int start) const {
  return Pointer::indexOf(ch, start, Data::length());
}

//-------------------------------------------------------------------------------
int Data::indexOfData(const void* destination, int destinationLen, int start) const {
  return Pointer::indexOfData(destination, destinationLen, start, Data::length());
}

//-------------------------------------------------------------------------------
int Data::indexOfStrings(const char* str) const {
  return Pointer::indexOfStrings(str, Data::length());
}

//-------------------------------------------------------------------------------
int Data::hashdata(void) const {
  return HashGenerator::getHashcode(this->pointer(), this->length());
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
