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
#include "./Booleans.h"

#include "./Character.h"
#include "./Pointers.h"
#include "./Strings.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::Booleans;

/* ****************************************************************************************
 * Variable <Static>
 */
const char* Booleans::TEXT_TRUE = "true";
const char* Booleans::TEXT_FALSE = "false";

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
bool Booleans::isBoolean(lang::Iterator<char>& iterator) {
  bool result;
  return Booleans::parseBoolean(result, iterator);
}

//-----------------------------------------------------------------------------------------
bool Booleans::parseBoolean(bool& result, const char* str) {
  if (str == nullptr)
    return false;

  if (Character::compareIgnoreCast(str, Booleans::TEXT_TRUE, (sizeof(Booleans::TEXT_TRUE) - 1))) {
    result = true;
    return true;
  }

  if (Character::compareIgnoreCast(str, Booleans::TEXT_FALSE, (sizeof(Booleans::TEXT_FALSE) - 1))) {
    result = false;
    return true;
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool Booleans::parseBoolean(bool& result, lang::Iterator<char>& iterator) {
  char cache[5];
  for (int i = 0; i < 5; ++i) {
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
