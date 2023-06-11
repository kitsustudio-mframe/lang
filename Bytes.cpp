/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

#include "./Bytes.h"
//-------------------------------------------------------------------------------
#include <stdlib.h>

#include "mframe.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using mframe::lang::Bytes;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Bytes::Bytes(void) {
  return;
}

//-------------------------------------------------------------------------------
Bytes::~Bytes(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
char Bytes::valueOf(const char* str) {
  return static_cast<char>(atoi(str));
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
