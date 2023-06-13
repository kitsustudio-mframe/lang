/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./Stacker.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Using
 */
using mframe::lang::managerment::Stacker;

//-------------------------------------------------------------------------------
using mframe::lang::Memory;

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Stacker::Stacker(void* buffer, int size) : Memory(buffer, size) {
  this->clear();
  return;
}

//-------------------------------------------------------------------------------
Stacker::Stacker(const Memory& memory) : Memory(memory) {
  this->clear();
  return;
}

//-------------------------------------------------------------------------------
Stacker::~Stacker(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************
 * Public Method <Override> mframe::util::Iterable<mframe::lang::Data*>
 */
bool Stacker::peekIndex(int index, void*& result){
  return false;
}

/* ******************************************************************************
 * Public Method <Override> mframe::util::Collection<mframe::lang::Memory>
 */

//-------------------------------------------------------------------------------
void Stacker::clear(void) {
  this->mStackPointer = static_cast<uint8_t*>(this->Memory::pointer());
  this->Memory::wipe();
}

//-------------------------------------------------------------------------------
bool Stacker::isEmpty(void) const {
  return (this->mStackPointer == this->Memory::pointer());
}

//-------------------------------------------------------------------------------
int Stacker::size(void) const {
  return static_cast<int>((reinterpret_cast<uint32_t>(this->mStackPointer) -
                           reinterpret_cast<uint32_t>(this->Memory::pointer())));
}

/* ******************************************************************************
 * Public Method <Override> mframe::lang::managerment::Allocator
 */

//-------------------------------------------------------------------------------
void* Stacker::alloc(int size) {
  if (this->getFree() < size)
    return nullptr;

  void* result = this->mStackPointer;
  this->mStackPointer += size;

  return result;
}

//-------------------------------------------------------------------------------
void* Stacker::allocAlignment32(int size) {
  int alignment = (reinterpret_cast<int>(this->mStackPointer) & 0x00000003);

  if (alignment) {
    if (this->alloc(0x00000004 - alignment) == nullptr)
      return nullptr;
  }

  return this->alloc(size);
}

//-------------------------------------------------------------------------------
void* Stacker::allocAlignment64(int size) {
  int alignment = (reinterpret_cast<int>(this->mStackPointer) & 0x00000007);

  if (alignment) {
    if (this->alloc(0x00000008 - alignment) == nullptr)
      return nullptr;
  }

  return this->alloc(size);
}

//-------------------------------------------------------------------------------
bool Stacker::free(void* ptr) {
  return false;
}

//-------------------------------------------------------------------------------
bool Stacker::free(void* ptr, int size) {
  return false;
}

//-------------------------------------------------------------------------------
int Stacker::getFree(void) {
  return (this->length() - this->size());
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
Memory Stacker::allocMemory(int size) {
  void* result = this->alloc(size);
  if (result == nullptr)
    return Memory::nullMemory();

  return Memory(result, size);
}

//-------------------------------------------------------------------------------
Memory Stacker::allocMemoryAlignment32(int size) {
  void* result = this->allocAlignment32(size);
  if (result == nullptr)
    return Memory::nullMemory();

  return Memory(result, size);
}

//-------------------------------------------------------------------------------
Memory Stacker::allocMemoryAlignment64(int size) {
  void* result = this->allocAlignment64(size);
  if (result == nullptr)
    return Memory::nullMemory();

  return Memory(result, size);
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
