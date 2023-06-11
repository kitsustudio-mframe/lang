/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./Memory.h"

//-------------------------------------------------------------------------------
#include <string.h>

#include "mframe.h"

/* ******************************************************************************
 * Using
 */
using mframe::lang::Memory;

//-------------------------------------------------------------------------------
using mframe::lang::Maths;
using mframe::lang::Pointer;

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Memory::Memory(const Data& data) : Data(data) {
  Memory::mNext = nullptr;
  return;
}

//-------------------------------------------------------------------------------
Memory::Memory(const void* pointer, size_t length) : Data(const_cast<void*>(pointer), length) {
  Memory::mNext = nullptr;
  return;
}

//-------------------------------------------------------------------------------
Memory::Memory(void* pointer, size_t length) : Data(const_cast<void*>(pointer), length) {
  Memory::mNext = nullptr;
  return;
}

//-------------------------------------------------------------------------------
Memory::Memory(size_t length) : Data(new uint8_t[(length & 0x7FFFFFFF)], (length & 0x7FFFFFFF)) {
  Memory::mNext = this;
  return;
}

//-------------------------------------------------------------------------------
Memory::Memory(const Memory& other) {
  *this = other;
  if (Memory::mNext != nullptr)
    const_cast<Memory&>(other).mNext = this;

  return;
}

//-------------------------------------------------------------------------------
Memory::~Memory(void) {
  if (Memory::mNext == nullptr)
    return;

  if (Memory::mNext == this) {
    delete[] static_cast<uint8_t*>(Memory::pointer());
  } else {
    Memory* next = this;

    while (true) {
      if (next->mNext == nullptr)
        System::error(this, mframe::lang::ErrorCode::NULL_POINTER);

      if (next->mNext == this) {
        next->mNext = Memory::mNext;
        break;
      }

      next = next->mNext;
    }
  }

  Memory::mNext = nullptr;
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
Memory Memory::nullMemory(void) {
  return Memory(static_cast<const void*>(nullptr), 0);
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
bool Memory::resize(int size) {
  if (size <= 0)
    return false;

  if (!Memory::isHeapMemory())
    return false;

  char* newMemory = new char[size];
  if (newMemory == nullptr)
    return false;

  this->lock();
  Pointers::move(newMemory, Memory::pointer(), Maths::min(size, Memory::length()));
  char* oldPointer = static_cast<char*>(Memory::pointer());
  Memory* next = this;

  while (true) {
    next->mPointer = newMemory;
    next->mLength = static_cast<uint32_t>(size);
    if (next->mNext == this)
      break;

    next = next->mNext;
  }

  delete[] oldPointer;

  this->unlock();
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
