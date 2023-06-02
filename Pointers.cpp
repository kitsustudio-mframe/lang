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
#include "./Pointers.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::Pointers;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
lang::Pointer Pointers::nullPointer(void){
  return lang::Pointer();
}

//-------------------------------------------------------------------------------
void Pointers::copy(void* destination, const void* source, int length){
  memcpy(destination, source, static_cast<size_t>(length));
}

//-------------------------------------------------------------------------------
void Pointers::move(void* destination, const void* source, int length){
  memmove(destination, source, static_cast<size_t>(length));
}

/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

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
