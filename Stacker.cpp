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
#include "./Stacker.h"

/* ******************************************************************************
 * Using
 */
using lang::Memory;
using lang::Stacker;

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Stacker::Stacker(void* buffer, uint32_t size) : Memory(buffer, size) {
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

/* ******************************************************************************
 * Public Method <Override> lang::Collection<lang::Memory>
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
 * Public Method <Override> lang::Allocator
 */

//-------------------------------------------------------------------------------
void* Stacker::alloc(uint32_t size) {
  if (static_cast<uint32_t>(this->getFree()) < size)
    return nullptr;

  void* result = this->mStackPointer;
  this->mStackPointer += size;

  return result;
}

//-------------------------------------------------------------------------------
bool Stacker::free(void* ptr) {
  return false;
}

//-------------------------------------------------------------------------------
bool Stacker::free(void* ptr, uint32_t size) {
  return false;
}

/* ******************************************************************************
 * Public Method
 */

//-------------------------------------------------------------------------------
uint32_t Stacker::getFree(void) {
  return (static_cast<uint32_t>(this->length() - this->size()));
}

//-------------------------------------------------------------------------------
void* Stacker::allocAlignment32(uint32_t size) {
  uint32_t alignment = (reinterpret_cast<uint32_t>(this->mStackPointer) & 0x00000003);

  if (alignment) {
    if (this->alloc(0x00000004 - alignment) == nullptr)
      return nullptr;
  }

  return this->alloc(size);
}

//-------------------------------------------------------------------------------
void* Stacker::allocAlignment64(uint32_t size) {
  uint32_t alignment = (reinterpret_cast<uint32_t>(this->mStackPointer) & 0x00000007);

  if (alignment) {
    if (this->alloc(0x00000008 - alignment) == nullptr)
      return nullptr;
  }

  return this->alloc(size);
}

//-------------------------------------------------------------------------------
Memory Stacker::allocMemory(uint32_t size) {
  void* result = this->alloc(size);
  if (result == nullptr)
    return Memory::nullMemory();

  return Memory(result, size);
}

//-------------------------------------------------------------------------------
Memory Stacker::allocMemoryAlignment32(uint32_t size) {
  void* result = this->allocAlignment32(size);
  if (result == nullptr)
    return Memory::nullMemory();

  return Memory(result, size);
}

//-------------------------------------------------------------------------------
Memory Stacker::allocMemoryAlignment64(uint32_t size) {
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
