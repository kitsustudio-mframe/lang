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
//-------------------------------------------------------------------------------
#include "./ByteBuffer.h"
#include "./StringFormat.h"

/* ******************************************************************************
 * Using
 */  
using lang::ByteBuffer;
using lang::WriteBuffer;
using lang::ReadBuffer;
using lang::Memory;
using lang::Strings;

/* ******************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Byte Buffer:: Byte Buffer object
 * 
 * @param memory 
 */
ByteBuffer::ByteBuffer(const Memory& memory) : Memory(memory){
  ByteBuffer::flush();
  return;
}

/**
 * @brief Construct a new Byte Buffer:: Byte Buffer object
 * 
 * @param length 
 */
ByteBuffer::ByteBuffer(size_t length) : Memory(length){
  ByteBuffer::flush();
  return;
}

/**
 * @brief Destroy the Byte Buffer:: Byte Buffer object
 * 
 */
ByteBuffer::~ByteBuffer(void){
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */
 
/* ******************************************************************************
 * Public Method <Override> - lang::Memory
 */

/**
 * @brief 
 * 
 * @param ch 
 * @param offset 
 * @return int 
 */
int ByteBuffer::indexOf(char ch, int start) const{
  return Pointer::indexOf(ch, start, ByteBuffer::limit());
}

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @return int 
 */
int ByteBuffer::indexOfData(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfData(destination, destinationLen, start, ByteBuffer::limit());
}

/* ******************************************************************************
 * Public Method <Override> - lang::ReadBufferBuffer
 */

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getByte(char& result){
  if(ByteBuffer::mPosition >= ByteBuffer::mLimit)
    return false;
  
  result = *static_cast<uint8_t*>(ByteBuffer::pointer(ByteBuffer::mPosition));
  ByteBuffer::position(ByteBuffer::position() + 1);
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::get(WriteBuffer& writeBuffer){
  int len = ByteBuffer::avariable();
  len = writeBuffer.put(ByteBuffer::pointer(ByteBuffer::mPosition), len);
  ByteBuffer::position(ByteBuffer::position() + len);

  return len;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::get(lang::WriteBuffer& writeBuffer, int length){
  int max = ByteBuffer::avariable();
  if(length > max)
    length = max;
  
  int result = writeBuffer.put(ByteBuffer::pointer(ByteBuffer::mPosition), length);
  ByteBuffer::position(ByteBuffer::position() + result);

  return result;
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int ByteBuffer::get(void* buffer, int bufferSize){
  int max = ByteBuffer::avariable();
  int pos = ByteBuffer::position();
  if(bufferSize > max)
    bufferSize = max;

  ByteBuffer::copyTo(buffer, pos, bufferSize);
  ByteBuffer::position(pos + bufferSize);
  return bufferSize;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int ByteBuffer::skip(int value){
  int max = ByteBuffer::avariable();
  if(value > max)
    value = max;
  
  ByteBuffer::position(ByteBuffer::position() + value);
  return value;
}

/* ******************************************************************************
 * Public Method <Override> - lang::WriteBuffer
 */

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putByte(const char value){
  if(ByteBuffer::mPosition >= ByteBuffer::mLimit)
    return false;
  
  *static_cast<uint8_t*>(ByteBuffer::pointer(ByteBuffer::mPosition++)) = value;
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::put(ReadBuffer& readBuffer){
  int len = ByteBuffer::remaining();
  len = readBuffer.get(ByteBuffer::pointer(ByteBuffer::mPosition), len);
  ByteBuffer::position(ByteBuffer::position() + len);
  return len;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param length 
 * @return int 
 */
int ByteBuffer::put(ReadBuffer& readBuffer, int length){
  if(length <= 0)
    return 0;
  
  int max = ByteBuffer::remaining();
  if(length > max)
    length = max;
  
  int result = readBuffer.get(ByteBuffer::pointer(ByteBuffer::mPosition), length);
  ByteBuffer::position(ByteBuffer::position() + result);
  return result;
}

/**
 * @brief 
 * 
 * @param ptr 
 * @param size 
 * @return true 
 * @return false 
 */
int ByteBuffer::put(const void* buffer, int bufferSize){
  if(bufferSize <= 0)
    return false;  
  
  int max = ByteBuffer::remaining();
  
  if(bufferSize > max)
    bufferSize = max;
  
  ByteBuffer::copy(buffer, 0, ByteBuffer::mPosition, bufferSize);
  ByteBuffer::position(ByteBuffer::position() + bufferSize);
  
  return bufferSize;
}

/* ******************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param newLimit 
 * @return true 
 * @return false 
 */
bool ByteBuffer::limit(int newLimit){
  if(newLimit < 0)
    return false;
  
  if(newLimit > ByteBuffer::length())
    return false;
  
  ByteBuffer::mLimit = newLimit;
  return true;
}

/**
 * @brief 
 * 
 * @param newPosition 
 * @return true 
 * @return false 
 */
bool ByteBuffer::position(int newPosition){
  if(newPosition < 0)
    return false;
  
  if(newPosition > ByteBuffer::limit())
    return false;
  
  ByteBuffer::mPosition = newPosition;
  return true;
}

/**
 * @brief 
 * 
 */
void ByteBuffer::flip(void){
  ByteBuffer::mLimit = ByteBuffer::mPosition;
  ByteBuffer::mPosition = 0;
  return;
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(char const* string){
  return ByteBuffer::put(string, static_cast<int>(strlen(string)));
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(const Strings& string){
  return ByteBuffer::put(string.pointer(), string.size());
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int ByteBuffer::putFormat(const char* format, ...){
  if(ByteBuffer::isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = StringFormat::pointerVa(ByteBuffer::pointer(ByteBuffer::mPosition), static_cast<size_t>(ByteBuffer::remaining()), format, args);
  
  va_end(args);
  
  ByteBuffer::mPosition += result;
  return result;
}

/**
 * @brief 
 * 
 * @param format 
 * @param args 
 * @return int 
 */
int ByteBuffer::putFormat(const char* format, va_list args){
  int result = StringFormat::pointerVa(ByteBuffer::pointer(ByteBuffer::mPosition), static_cast<size_t>(ByteBuffer::remaining()), format, args);
  ByteBuffer::mPosition += result;
  return result; 
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putShort(short value){
  if((ByteBuffer::mPosition + 1) >= ByteBuffer::mLimit)
    return false;
  
  *static_cast<short*>(ByteBuffer::pointer(ByteBuffer::mPosition)) = value;
  ByteBuffer::mPosition+=2;
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putShortMsb(short value){
  if((ByteBuffer::mPosition + 1) >= ByteBuffer::mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(ByteBuffer::pointer());
  
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value >> 8);
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value);
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putInt(int value){
  if((ByteBuffer::mPosition + 3) >= ByteBuffer::mLimit)
    return false;
  
  *static_cast<int*>(ByteBuffer::pointer(ByteBuffer::mPosition)) = value;
  ByteBuffer::mPosition+=4;
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putIntMsb(int value){
  if((ByteBuffer::mPosition + 3) >= ByteBuffer::mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(ByteBuffer::pointer());
  
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value >> 24);
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value >> 16);
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value >> 8);
  ptr[ByteBuffer::mPosition++] = static_cast<uint8_t>(value);
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putFloat(const float value){
  const int* i = reinterpret_cast<const int*>(&value);
  return ByteBuffer::putInt(*i);
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putFloatMsb(const float value){
  const int* i = reinterpret_cast<const int*>(&value);
  return ByteBuffer::putIntMsb(*i);
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getShort(short& result){
  if((ByteBuffer::mPosition + 1) >= ByteBuffer::mLimit)
    return false;
  
  result = *static_cast<short*>(ByteBuffer::pointer(ByteBuffer::mPosition));
  ByteBuffer::mPosition += 2;
  
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getShortMsb(short& result){
  if((ByteBuffer::mPosition + 1) >= ByteBuffer::mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(ByteBuffer::pointer());
  
  result = 0;
  result |= (static_cast<short>(ptr[ByteBuffer::mPosition++]) << 8);
  result |= (static_cast<short>(ptr[ByteBuffer::mPosition++]));
  
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getInt(int& result){
  if((ByteBuffer::mPosition + 3) >= ByteBuffer::mLimit)
    return false;
  
  result = *static_cast<int*>(ByteBuffer::pointer(ByteBuffer::mPosition));
  ByteBuffer::mPosition+=4;

  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getIntMsb(int& result){
  if((ByteBuffer::mPosition + 3) >= ByteBuffer::mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(ByteBuffer::pointer());
  
  result = 0;
  result |= (static_cast<int>(ptr[ByteBuffer::mPosition++]) << 24);
  result |= (static_cast<int>(ptr[ByteBuffer::mPosition++]) << 16);
  result |= (static_cast<int>(ptr[ByteBuffer::mPosition++]) << 8);
  result |= (static_cast<int>(ptr[ByteBuffer::mPosition++]));
  
  return true;
}

/**
 * @brief Get the Float object
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getFloat(float& result){
  int* r = reinterpret_cast<int*>(&result);
  return ByteBuffer::getInt(*r);
}

/**
 * @brief 
 * 
 */
bool ByteBuffer::getFloatMsb(float& result){
  int* r = reinterpret_cast<int*>(&result);
  return ByteBuffer::getIntMsb(*r);
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
