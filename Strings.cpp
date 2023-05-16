/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

#include <string.h>
#include <stdio.h>
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Strings.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using lang::Strings;
using lang::Memory;

/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Strings:: Strings object
 * 
 * @param pointer 
 * @param size 
 */
Strings::Strings(void* pointer, uint32_t size) : Memory(pointer, size){
  return;
}

/**
 * @brief Construct a new Strings:: Strings object
 * 
 * @param str 
 */
Strings::Strings(const char* str) : Memory(str, strlen(str) + 1){
  return;
}

/**
 * @brief Construct a new Strings:: Strings object
 * 
 * @param length 
 */
Strings::Strings(size_t length) : Memory(length){
  return;
}

/**
 * @brief Construct a new Strings:: Strings object
 * 
 * @param memory 
 */
Strings::Strings(const Memory& memory) : Memory(memory){
  return;
}

/**
 * @brief Destroy the Strings:: Strings object
 * 
 */
Strings::~Strings(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @param format 
 * @param arg 
 * @return int 
 */
int Strings::format(void* buffer, size_t bufferSize, const char* format, va_list args){
  return vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
}

/**
 * @brief 
 * 
 * @param memory 
 * @param format 
 * @param arg 
 * @return int 
 */
int Strings::format(const lang::Memory& memory, const char* format, va_list args){
  if(memory.isReadOnly())
    return 0;

  return vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @param format 
 * @param ... 
 * @return int 
 */
int Strings::format(void* buffer, uint32_t bufferSize, const char* format, ...){
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 * @param memory 
 * @param format 
 * @param ... 
 * @return int 
 */
int Strings::format(const lang::Memory& memory, const char* format, ...){
  if(memory.isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 * @param bufferSize 
 * @param format 
 * @param ... 
 * @return Strings 
 */
Strings Strings::format(int bufferSize, const char* format, ...){
  Strings buffer = Strings(static_cast<size_t>(bufferSize));

  va_list args;
  va_start(args, format);  
  buffer.format(format, args);
  va_end(args);
  
  if(buffer.size() >= static_cast<int>((static_cast<float>(buffer.length()) * 0.9f)))
    return buffer;

  Strings result = Strings(static_cast<uint32_t>(buffer.size()));
  result.copy(buffer, static_cast<int>(result.length()));
  return result;
}

/**
 * @brief 
 * 
 * @param src 
 * @param format 
 * @param args 
 * @return int 
 */
int Strings::scanFormat(const char* src, const char* format, va_list args){
  return vsscanf(src, format, args);
}

/**
 * @brief 
 * 
 * @param src 
 * @param format 
 * @param ... 
 * @return int 
 */
int Strings::scanFormat(const char* src, const char* format, ...){
  va_list args;
  va_start(args, format);
  int result = vsscanf(src, format, args);
  va_end(args);
  return result;  
}

/**
 * @brief 
 * 
 * @return Strings 
 */
Strings Strings::empty(void){
  return Strings("\0");
}

/**
 * @brief 
 * 
 * @param src 
 * @return int 
 */
int Strings::stringLength(const char* src){
  return static_cast<int>(strlen(src));
}

/* ****************************************************************************************
 * Public Method <Override> - lang::Memory
 */

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @return int 
 */
int Strings::indexOfData(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfData(destination, destinationLen, start, this->size());
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 取的String原始空間大小
 * 
 * @return int 
 */
int Strings::bufferSize(void){
  return Memory::length();
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int Strings::scanFormat(const char* format, ...){
  va_list args;
  va_start(args, format);
  int result = vsscanf(static_cast<char*>(this->pointer()), format, args);
  va_end(args);
  return result;  
}

/**
 * @brief 
 * 
 * @param format 
 * @param args 
 * @return int 
 */
int Strings::format(const char* format, va_list args){
  if(this->isReadOnly())
    return 0;  
  
  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  return result;
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int Strings::format(const char* format, ...){
  if(this->isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 */
void Strings::convertUpper(void){
  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for(int i=0; i<max; ++i){
    if((ptr[i] >= 'a') && (ptr[i] <= 'z')){
			ptr[i] -= 32;
		}
  }
}

/**
 * @brief 
 * 
 */
void Strings::convertLower(void){
  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for(int i=0; i<max; ++i){
    if((ptr[i] >= 'A') && (ptr[i] <= 'Z')){
			ptr[i] += 32;
		}
  }
}

/**
 * @brief 
 * 
 * @return Strings 
 */
Strings Strings::toUpper(void) const{
  int max = this->size();
  Strings result = Strings(static_cast<uint32_t>(max + 1));

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for(int i=0; i<max; ++i){
    if((src[i] >= 'a') && (src[i] <= 'z'))
			dst[i] -= 32;

		else
      dst[i] = src[i];

  }
  result[max] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @return Strings 
 */
Strings Strings::toLower(void) const{
  int max = this->size();
  Strings result = Strings(static_cast<uint32_t>(max + 1));

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for(int i=0; i<max; ++i){
    if((src[i] >= 'A') && (src[i] <= 'Z'))
			dst[i] -= 32;
      
		else
      dst[i] = src[i];

  }
  result[max] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @return Strings 
 */
Strings Strings::clone(void) const{
  if(this->isReadOnly())
    return Strings(static_cast<const char*>(this->pointer()));
  
  else
    return this->clone(0, this->size());
}

/**
 * @brief 
 * 
 * @param length 
 * @return Strings 
 */
Strings Strings::clone(int length) const{
  return this->clone(0, length);
}

/**
 * @brief 
 * 
 * @param offset 
 * @return Strings 
 */
Strings Strings::clone(int offset, int length) const{
  int size = this->size();
  if(offset >= size)
    return Strings::empty();

  if(length > size)
    length = size;

  Strings result = Strings(static_cast<size_t>(length + 1));
  result.copy(this->pointer(offset), static_cast<int>(length));
  result[length] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
int Strings::size(void) const{
  size_t result = strlen(static_cast<const char*>(this->pointer()));
  
  if(result >= static_cast<uint32_t>(this->length()))
    result = static_cast<uint32_t>(this->length());

  return static_cast<int>(result);
}

/**
 * @brief 
 * 
 * @param oldChar 
 * @param newChar 
 * @return int 
 */
int Strings::replace(char oldChar, char newChar){
  int result abstract;
  if(this->isReadOnly())
    return 0;
  
  int max = this->size();
  char* ptr = static_cast<char*>(this->pointer());
  for(int i=0; i<max; ++i){
    if(ptr[i] == oldChar){
      ptr[i] = newChar;
      ++result;
    }
  }
  
  return result;
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
Strings& Strings::append(const char* str){
  int len = Strings::stringLength(str);
  int entityLen = this->size();
  this->copy(str, entityLen ,0, (len + 1));
  return *this;
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
Strings& Strings::set(const char* str){
  int len = Strings::stringLength(str);
  this->copy(str, 0 ,0, (len + 1));
  return *this;
}

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
