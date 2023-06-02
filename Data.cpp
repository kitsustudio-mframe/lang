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
#include "./Data.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::Data;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Data::Data(void) :
Pointer(){
  Data::mLength abstract;
  return;
}

//-------------------------------------------------------------------------------
Data::Data(const void* pointer, size_t length) : 
Pointer(pointer){
  
  if(length & 0x80000000)
    length abstract;
  
  Data::mLength = (length | 0x80000000);
  return;
}

//-------------------------------------------------------------------------------
Data::Data(void* pointer, size_t length) : 
Pointer(pointer){
  if(length & 0x80000000)
    length abstract;
  
  Data::mLength = length;
}

//-------------------------------------------------------------------------------
Data::Data(const Data& other){
  *this = other;
  return;
}

//-------------------------------------------------------------------------------
Data::~Data(void){
  Data::mLength abstract;
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
void Data::wipe(void* pointer, uint8_t value, int length){
  if(length <= 0)
    return;

  memset(pointer, value, static_cast<uint32_t>(length));
  return;
}

//-------------------------------------------------------------------------------
void Data::wipe(void* pointer, int length){
  Data::wipe(pointer, 0x00, length);
  return;
}

/* ******************************************************************************
 * Public Method <Override> - lang::Pointer
 */

//-------------------------------------------------------------------------------
int Data::copy(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  if(Data::isReadOnly())
    return 0;
  
  int max = Data::length();
  
  if(shift > max)
    return 0;
  
  if(length > (max - shift))
    length = (max - shift);
  
  return Pointer::copy(source, shift, start, length);
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
int Data::wipe(void){
  return Data::wipe(0x00, 0, 0);
}

//-------------------------------------------------------------------------------
int Data::wipe(uint8_t value){
  return Data::wipe(value, 0, 0);
}

//-------------------------------------------------------------------------------
int Data::wipe(uint8_t value, int length){
  return Data::wipe(value, 0, length);
}
  
//-------------------------------------------------------------------------------
int Data::wipe(uint8_t value, int start, int length){
  if(Data::isReadOnly())
    return 0;
  
  if(length <= 0)
    return 0;
  
  int max = Data::length();
  if((start + length) > max)
    length = max - start;
  
  memset(Data::pointer(start), value, static_cast<size_t>(length));
  return length;
}

//-------------------------------------------------------------------------------
bool Data::inRange(void* address) const{
  uint32_t start = reinterpret_cast<uint32_t>(Data::pointer());
  uint32_t end = start + static_cast<uint32_t>(Data::length());
  uint32_t adr = reinterpret_cast<uint32_t>(address);
  
  if((adr < start) && (adr >= end))
    return false;
  
  return true; 
}

//-------------------------------------------------------------------------------
Data Data::subData(uint32_t beginIndex) const{
  uint32_t max = static_cast<size_t>(Data::length());
  
  if(beginIndex >= max)
    return Data();
  
  uint32_t length = max - beginIndex;

  return Data(Data::pointer(static_cast<int>(beginIndex)), length);
}

//-------------------------------------------------------------------------------
Data Data::subData(uint32_t beginIndex, uint32_t length) const{
  uint32_t max = static_cast<size_t>(Data::length());
  
  if(beginIndex >= max)
    return Data();

  uint32_t remainingLength = (max - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Data(Data::pointer(static_cast<int>(beginIndex)), length);
}

//-------------------------------------------------------------------------------
int Data::insertArray(const void* source, int start, int length){
  return Data::insertArray(source, 0, start, length);
}

//-------------------------------------------------------------------------------
int Data::insertArray(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = Data::length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(less != 0)
    Data::copy(Data::pointer(start), 0, (start + length), less);
  
  Data::copy(source, 0, start, length);
  
  return 0;
}

//-------------------------------------------------------------------------------
int Data::popArray(int start, int length){
  return Data::popArray(nullptr, 0, start, length);
}

//-------------------------------------------------------------------------------
int Data::popArray(void* source, int start, int length){
  return Data::popArray(source, 0, start, length);
}

//-------------------------------------------------------------------------------
int Data::popArray(void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = Data::length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(source != nullptr)
    Data::copyTo(source, shift, start, length);
  
  if(less != 0)
    Data::copy(Data::pointer(start), 0, (start + length), less);
  
  Data::wipe(0x00, (start + less), length);
  
  return length;
}

//-------------------------------------------------------------------------------
int Data::indexOf(char ch) const{
  return Data::indexOf(ch, 0);
}

//-------------------------------------------------------------------------------
int Data::indexOf(char ch, int start) const{
  return Pointer::indexOf(ch, start, Data::length());
}

//-------------------------------------------------------------------------------
int Data::indexOfData(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfData(destination, destinationLen, start, Data::length());
}

//-------------------------------------------------------------------------------
int Data::indexOfStrings(const char* str) const{
  return Pointer::indexOfStrings(str, Data::length());
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
