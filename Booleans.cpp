/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./Booleans.h"

//-----------------------------------------------------------------------------------------
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */
#define MACRO_TEXT_TRUE "true"
#define MACRO_TEXT_FALSE "false"
/* ****************************************************************************************
 * Using
 */
using mframe::lang::Booleans;

//-----------------------------------------------------------------------------------------
using mframe::util::Iterator;

/* ****************************************************************************************
 * Variable <Static>
 */
const char* Booleans::TEXT_TRUE = MACRO_TEXT_TRUE;
const char* Booleans::TEXT_FALSE = MACRO_TEXT_FALSE;
const int Booleans::TEXT_TRUE_LENGTH = sizeof(MACRO_TEXT_TRUE) - 1;
const int Booleans::TEXT_FALSE_LENGTH = sizeof(MACRO_TEXT_FALSE) - 1;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
bool Booleans::isBoolean(const char* str) {
  bool result;
  return Booleans::parseBoolean(result, str);
}

//-----------------------------------------------------------------------------------------
bool Booleans::isBoolean(mframe::util::Iterator<char>& iterator) {
  bool result;
  return Booleans::parseBoolean(result, iterator);
}

//-----------------------------------------------------------------------------------------
bool Booleans::parseBoolean(bool& result, const char* str) {
  if (str == nullptr)
    return false;

  if (Character::compareIgnoreCast(str, Booleans::TEXT_TRUE, Booleans::TEXT_TRUE_LENGTH)) {
    if (Character::isNextSymbol(str[Booleans::TEXT_TRUE_LENGTH])) {
      result = true;
      return true;
    }
    return false;
  }

  if (Character::compareIgnoreCast(str, Booleans::TEXT_FALSE, Booleans::TEXT_FALSE_LENGTH)) {
    if (Character::isNextSymbol(str[Booleans::TEXT_FALSE_LENGTH])) {
      result = false;
      return true;
    }
    return false;
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool Booleans::parseBoolean(bool& result, mframe::util::Iterator<char>& iterator) {
  char cache[Booleans::TEXT_FALSE_LENGTH + 1];
  for (int i = 0; i < (Booleans::TEXT_FALSE_LENGTH + 1); ++i) {
    if (!iterator.next(cache[i]))
      break;
  }

  return Booleans::parseBoolean(result, cache);
}

/* ****************************************************************************************
 * Public Method <Override>
 */

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
