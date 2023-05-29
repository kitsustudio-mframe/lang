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
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Maths.h"
#include "./Memory.h"
#include "./Pointer.h"
#include "./Pointers.h"
#include "./System.h"

/* ****************************************************************************************
 * Using
 */  
using lang::Maths;
using lang::Memory;
using lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Memory object
 * 
 * @param data 
 */
Memory::Memory(const Data& data) :
Data(data){
  Memory::mNext = nullptr;
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param pointer 
 * @param length 
 */
Memory::Memory(const void* pointer, size_t length) : 
Data(const_cast<void*>(pointer), length){
 
  Memory::mNext = nullptr;
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param pointer 
 * @param length 
 */
Memory::Memory(void* pointer, size_t length) : 
Data(const_cast<void*>(pointer), length){

  Memory::mNext = nullptr;
  return;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 * @param length 
 */
Memory::Memory(size_t length) : 
Data(new uint8_t[(length & 0x7FFFFFFF)], (length & 0x7FFFFFFF)){

  Memory::mNext = this;
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param other 
 */
Memory::Memory(const Memory& other){
  
  *this = other;
  if(Memory::mNext != nullptr)
    const_cast<Memory&>(other).mNext = this;
  
  return;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 */
Memory::~Memory(void){
  if(Memory::mNext == nullptr)
    return;

  if(Memory::mNext == this){
    delete[] static_cast<uint8_t*>(Memory::pointer());
  }else{
    Memory* next = this;
    
    while(true){
      if(next->mNext == nullptr)
        System::error(this, lang::ErrorCode::NULL_POINTER);
      
      if(next->mNext == this){
        next->mNext = Memory::mNext;
        break;
      }
      
      next = next->mNext;
    }
  }
  
  Memory::mNext = nullptr;
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
 * @return Memory 
 */
Memory Memory::nullMemory(void){
  return Memory(static_cast<const void*>(nullptr), 0);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param beginIndex 
 * @return Memory 
 */
Memory Memory::subMemory(uint32_t beginIndex) const{
  uint32_t max = static_cast<size_t>(Memory::length());
  
  if(beginIndex >= max)
    return Memory::nullMemory();
  
  uint32_t length = max - beginIndex;

  return Memory(Memory::pointer(static_cast<int>(beginIndex)), length);
}

/**
 * @brief 
 * 
 * @param beginIndex 
 * @param length 
 * @return Memory 
 */
Memory Memory::subMemory(uint32_t beginIndex, uint32_t length) const{
  uint32_t max = static_cast<size_t>(Memory::length());
  
  if(beginIndex >= max)
    return Memory::nullMemory();

  uint32_t remainingLength = (max - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Memory(Memory::pointer(static_cast<int>(beginIndex)), length);
}

/**
 * @brief 
 * 
 * @param size 
 * @return true 
 * @return false 
 */
bool Memory::resize(int size){
  if(size <= 0)
    return false;

  if(!Memory::isHeapMemory())
    return false;
  
  char* newMemory = new char[size];
  if(newMemory == nullptr)
    return false;
  
  Pointers::move(newMemory, Memory::pointer(), Maths::min(size, Memory::length()));
  char* oldPointer = static_cast<char*>(Memory::pointer());
  Memory* next = this;
  
  while(true){
    next->mPointer = newMemory;
    next->mLength = static_cast<uint32_t>(size);
    if(next->mNext == this)
      break;
    
    next = next->mNext;
  }
  
  delete[] oldPointer;
  return true;
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
