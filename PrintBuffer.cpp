/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./PrintBuffer.h"
#include "./StringFormat.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::PrintBuffer;
using lang::RingBuffer;
using lang::StringFormat;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */


PrintBuffer::PrintBuffer(void* buffer, uint32_t bufferSize) :RingBuffer(buffer, bufferSize){
  return;
}
      

PrintBuffer::PrintBuffer(const lang::Memory& memory) :RingBuffer(memory){
  return;
}


PrintBuffer::PrintBuffer(uint32_t length) :RingBuffer(length){
  return;
}

/**
 * @brief Destroy the Print Stream object
 * 
 */
PrintBuffer::~PrintBuffer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param b 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(bool b, bool newLine){
  if(b)
    this->put("True", 4);
  
  else
    this->put("False", 5);
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param c 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(char c, bool newLine){
  this->putByte(c);
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param d 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(double d, bool newLine){
  lang::StringFormat::writeBuffer(*this, "%f", d);
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param f 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(float f, bool newLine){
  lang::StringFormat::writeBuffer(*this, "%f", static_cast<double>(f));
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param i 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(int i, bool newLine, bool unsign){
  if(unsign)
    lang::StringFormat::writeBuffer(*this, "%d", static_cast<unsigned int>(i));
  
  else
    lang::StringFormat::writeBuffer(*this, "%d", i);
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param string 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(const lang::Strings& string, bool newLine){
  this->put(string, string.size());
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param string 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(const char* string, bool newLine){
  this->put(string, Strings::getLength(string));
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param OutputBuffer 
 * @param newLine 
 * @return true 
 * @return false 
 */
void PrintBuffer::print(ReadBuffer& readBuffer, bool newLine){
  this->put(readBuffer);
  
  if(newLine)
    this->putByte('\n');
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
void PrintBuffer::println(void){
  this->putByte('\n');
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return true 
 * @return false 
 */
void PrintBuffer::format(const char* format, ...){
  va_list args;
  va_start(args, format);
  StringFormat::writeBufferVa(*this, format, args);
  va_end(args);
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
