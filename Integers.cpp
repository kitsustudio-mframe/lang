/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./Integers.h"

//-------------------------------------------------------------------------------
#include <stdlib.h>

#include "mframe.h"

/* ******************************************************************************
 * Macro
 */
#define MACRO_IS_NUMB(c) ((c >= '0') && (c <= '9'))

/* ******************************************************************************
 * Using
 */
using mframe::lang::Integers;

//-------------------------------------------------------------------------------
using mframe::util::Iterator;

/* ******************************************************************************
 * Variable <Static>
 */
const char* Integers::TEXT_MAX_VALUE = "2147483647";
const char* Integers::TEXT_MIN_VALUE = "-2147483648";
const int Integers::MAX_ASCII_VALUE = static_cast<int>(sizeof("-2147483648"));
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
bool Integers::isInteger(mframe::util::Iterator<char>& iterator) {
  char cache[Integers::MAX_ASCII_VALUE];
  for (int i = 0; i < Integers::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Integers::isInteger(cache);
}

//-------------------------------------------------------------------------------
bool Integers::isInteger(const char* str) {
  if (str == nullptr)
    return false;

  if (!(MACRO_IS_NUMB(str[0]) || (str[0] == '-')))
    return false;

  int i = 1;

  for (; i < Integers::MAX_ASCII_VALUE; ++i) {
    if (!MACRO_IS_NUMB(str[i]))
      break;
  }

  return Character::isNextSymbol(str[i]);
}

//-------------------------------------------------------------------------------
bool Integers::parseInteger(int& result, mframe::util::Iterator<char>& iterator) {
  char cache[Integers::MAX_ASCII_VALUE];
  for (int i = 0; i < Integers::MAX_ASCII_VALUE; ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Integers::parseInteger(result, cache);
}

//-------------------------------------------------------------------------------
bool Integers::parseInteger(int& result, const char* str) {
  if (!Integers::isInteger(str))
    return false;

  result = strtol(str, nullptr, 0);
  return true;
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
