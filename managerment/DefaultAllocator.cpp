/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./DefaultAllocator.h"

//-----------------------------------------------------------------------------------------
#include <stdlib.h>

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using mframe::lang::managerment::DefaultAllocator;

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> mframe::lang::managerment::Allocator
 */

//-----------------------------------------------------------------------------------------
void* DefaultAllocator::alloc(int size) {
  return ::malloc(static_cast<uint32_t>(size));
}

//-----------------------------------------------------------------------------------------

bool DefaultAllocator::free(void* ptr) {
  ::free(ptr);
  return true;
}

//-----------------------------------------------------------------------------------------

bool DefaultAllocator::free(void* ptr, int size) {
  ::free(ptr);
  return true;
}

//-----------------------------------------------------------------------------------------

void* DefaultAllocator::allocAlignment32(int size) {
  uint32_t sz = static_cast<uint32_t>(size);
  if (sz & 0x00000003)
    sz = ((sz + 0x00000003) & ~0x00000003);

  return malloc(sz);
}

//-----------------------------------------------------------------------------------------

void* DefaultAllocator::allocAlignment64(int size) {
  uint32_t sz = static_cast<uint32_t>(size);
  if (sz & 0x00000007)
    sz = ((sz + 0x00000007) & ~0x00000007);

  return ::malloc(sz);
}

//-----------------------------------------------------------------------------------------

int DefaultAllocator::getFree(void) {
  return 0;
}

/* ****************************************************************************************
 * Public Method
 */

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
