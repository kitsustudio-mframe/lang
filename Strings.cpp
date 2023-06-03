/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

#include <stdio.h>
#include <string.h>
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Class.h"
#include "./HashGen.h"
#include "./Strings.h"
#include "./System.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */
using lang::Class;
using lang::Memory;
using lang::Strings;

/* ******************************************************************************
 * Variable
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Strings::Strings(void* pointer, uint32_t size) : Memory(pointer, size) {
  return;
}

//-------------------------------------------------------------------------------
Strings::Strings(const char* str) : Memory(str, strlen(str) + 1) {
  return;
}

//-------------------------------------------------------------------------------
Strings::Strings(size_t length) : Memory(length) {
  return;
}

//-------------------------------------------------------------------------------
Strings::Strings(const Memory& memory) : Memory(memory) {
  return;
}

//-------------------------------------------------------------------------------
Strings::~Strings(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
Strings Strings::format(int bufferSize, const char* format, ...) {
  Strings buffer = Strings(static_cast<size_t>(bufferSize));

  va_list args;
  va_start(args, format);
  buffer.format(format, args);
  va_end(args);

  if (buffer.size() >= static_cast<int>((static_cast<float>(buffer.length()) * 0.9f)))
    return buffer;

  Strings result = Strings(static_cast<uint32_t>(buffer.size()));
  result.copy(buffer, static_cast<int>(result.length()));
  return result;
}

//-------------------------------------------------------------------------------
Strings Strings::empty(void) {
  return Strings("\0");
}

//-------------------------------------------------------------------------------
int Strings::getLength(const char* src) {
  return static_cast<int>(strlen(src));
}

/* ******************************************************************************
 * Public Method <Override> - lang::Memory
 */

//-------------------------------------------------------------------------------
int Strings::indexOfData(const void* destination, int destinationLen, int start) const {
  return Pointer::indexOfData(destination, destinationLen, start, this->size());
}

/* ******************************************************************************
 * Public Method <Override> - lang::Object
 */

//-------------------------------------------------------------------------------
int Strings::hashcode(void) const {
  return lang::HashGen::getHashcode(this->pointer(Class<const char>::cast()));
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
void Strings::clear(void) {
  this->pointer(Class<char>::cast())[0] = 0x00;
  return;
}

//-------------------------------------------------------------------------------
int Strings::bufferSize(void) {
  return Memory::length();
}

//-------------------------------------------------------------------------------
int Strings::scanFormat(const char* format, ...) {
  va_list args;
  va_start(args, format);
  int result = vsscanf(static_cast<char*>(this->pointer()), format, args);
  va_end(args);
  return result;
}

//-------------------------------------------------------------------------------
int Strings::format(const char* format, va_list args) {
  if (this->isReadOnly())
    return 0;

  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  return result;
}

//-------------------------------------------------------------------------------
int Strings::format(const char* format, ...) {
  if (this->isReadOnly())
    return 0;

  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  va_end(args);
  return result;
}

//-------------------------------------------------------------------------------
void Strings::convertUpper(void) {
  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for (int i = 0; i < max; ++i) {
    if ((ptr[i] >= 'a') && (ptr[i] <= 'z')) {
      ptr[i] -= 32;
    }
  }
}

//-------------------------------------------------------------------------------
void Strings::convertLower(void) {
  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for (int i = 0; i < max; ++i) {
    if ((ptr[i] >= 'A') && (ptr[i] <= 'Z')) {
      ptr[i] += 32;
    }
  }
}

//-------------------------------------------------------------------------------
Strings Strings::toUpper(void) const {
  int max = this->size();
  Strings result = Strings(static_cast<uint32_t>(max + 1));

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for (int i = 0; i < max; ++i) {
    if ((src[i] >= 'a') && (src[i] <= 'z'))
      dst[i] -= 32;

    else
      dst[i] = src[i];
  }
  result[max] = 0x00;
  return result;
}

//-------------------------------------------------------------------------------
Strings Strings::toLower(void) const {
  int max = this->size();
  Strings result = Strings(static_cast<uint32_t>(max + 1));

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for (int i = 0; i < max; ++i) {
    if ((src[i] >= 'A') && (src[i] <= 'Z'))
      dst[i] -= 32;

    else
      dst[i] = src[i];
  }
  result[max] = 0x00;
  return result;
}

//-------------------------------------------------------------------------------
Strings Strings::clone(void) const {
  if (this->isReadOnly())
    return Strings(static_cast<const char*>(this->pointer()));

  else
    return this->clone(0, this->size());
}

//-------------------------------------------------------------------------------
Strings Strings::clone(int length) const {
  return this->clone(0, length);
}

//-------------------------------------------------------------------------------
Strings Strings::clone(int offset, int length) const {
  int size = this->size();
  if (offset >= size)
    return Strings::empty();

  if (length > size)
    length = size;

  Strings result = Strings(static_cast<size_t>(length + 1));
  result.copy(this->pointer(offset), static_cast<int>(length));
  result[length] = 0x00;
  return result;
}

//-------------------------------------------------------------------------------
int Strings::size(void) const {
  size_t result = strlen(static_cast<const char*>(this->pointer()));

  if (result >= static_cast<uint32_t>(this->length()))
    result = static_cast<uint32_t>(this->length());

  return static_cast<int>(result);
}

//-------------------------------------------------------------------------------
int Strings::replace(char oldChar, char newChar) {
  int result = 0;
  if (this->isReadOnly())
    return 0;

  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());
  for (int i = 0; i < max; ++i) {
    if (ptr[i] == oldChar) {
      ptr[i] = newChar;
      ++result;
    }
  }

  return result;
}

//-------------------------------------------------------------------------------
Strings& Strings::append(const char* str) {
  if(this->isReadOnly())
    return *this;

  int len = Strings::getLength(str);
  int start = this->size();
  start += this->copy(str, 0, start, len);

  this->pointer(Class<char>::cast())[start] = 0x00;
  return *this;
}

//-------------------------------------------------------------------------------
Strings& Strings::append(lang::ReadBuffer& readBuffer){
  if(this->isReadOnly())
    return *this;

  int i = this->size();
  int max = this->bufferSize() - 1;
  char* ch = this->pointer(Class<char>::cast());
  
  for(; i<max; ++i){
    char cache;
    if(readBuffer.getByte(cache) < 0)
      break;
    
    if(cache == 0)
      cache = '.';

    ch[i] = cache;
  }

  ch[i] = 0x00;


  return *this;
}

//-------------------------------------------------------------------------------
Strings& Strings::append(int value){
  if(this->isReadOnly())
    return *this;

  int i = this->size();
  int max = this->bufferSize();

  snprintf(this->pointer(i, Class<char>::cast()), static_cast<size_t>(max), "%d", value);  
  return *this;
}

//-------------------------------------------------------------------------------
Strings& Strings::append(double value){
  if(this->isReadOnly())
    return *this;

  int i = this->size();
  int max = this->bufferSize();

  snprintf(this->pointer(i, Class<char>::cast()), static_cast<size_t>(max), "%f", value);  
  return *this;
}

//-------------------------------------------------------------------------------
Strings& Strings::append(bool boolean){
  if(boolean)
    return this->append("TRUE");

  return this->append("FALSE");
}

//-------------------------------------------------------------------------------
Strings& Strings::set(const char* str) {
  int len = Strings::getLength(str);
  this->copy(str, 0, 0, (len + 1));
  return *this;
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
