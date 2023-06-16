/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

#include "./Character.h"
//-------------------------------------------------------------------------------
#include <string.h>

#include "mframe.h"

/* ******************************************************************************
 * Macro
 */
#define MACRO_TO_UPPER_CAST(src) (((src >= 'a') && (src <= 'z')) ? (src - ('a' - 'A')) : src)
#define MACRO_TO_LOWER_CAST(src) (((src >= 'A') && (src <= 'Z')) ? (src + ('a' - 'A')) : src)

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using mframe::lang::Character;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
Character::Character(void) {
  return;
}

//-------------------------------------------------------------------------------
Character::~Character(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
char Character::toUpperCase(char ch) {
  return MACRO_TO_UPPER_CAST(ch);
}

//-------------------------------------------------------------------------------
int Character::toUpperCase(const char* src, char* dst) {
  return Character::toUpperCase(src, dst, 0);
}

//-------------------------------------------------------------------------------
int Character::toUpperCase(const char* src, char* dst, int length) {
  if ((src == nullptr) || (dst = nullptr))
    return 0;

  if (length <= 0)
    length = Integer::MAX_VALUE;
  int i = 0;
  for (; i < length; ++i) {
    dst[i] = MACRO_TO_UPPER_CAST(src[i]);

    if (src[i] == '\0')
      break;
  }

  return i;
}

//-------------------------------------------------------------------------------
char Character::toLowerCase(char ch) {
  return MACRO_TO_LOWER_CAST(ch);
}

//-------------------------------------------------------------------------------
int Character::toLowerCase(const char* src, char* dst) {
  return Character::toLowerCase(src, dst, 0);
}

//-------------------------------------------------------------------------------
int Character::toLowerCase(const char* src, char* dst, int length) {
  if ((src == nullptr) || (dst = nullptr))
    return 0;

  if (length <= 0)
    length = Integer::MAX_VALUE;
  int i = 0;
  for (; i < length; ++i) {
    dst[i] = MACRO_TO_LOWER_CAST(src[i]);

    if (src[i] == '\0')
      break;
  }

  return i;
}

//-------------------------------------------------------------------------------
char Character::hexCharToChar(char highChar, char lowChar) {
  char result = Character::hexCharToChar(lowChar);
  return static_cast<char>(result + (Character::hexCharToChar(highChar) << 4));
}

//-------------------------------------------------------------------------------
char Character::hexCharToChar(char ch) {
  ch = Character::toUpperCase(ch);

  if ((ch >= '0') && (ch <= '9'))
    return (ch - '0');

  if ((ch >= 'A') && (ch <= 'F'))
    return (ch - 'A' + 10);

  return 0;
}

//-------------------------------------------------------------------------------
bool Character::compare(char src, char dst) {
  return (src == dst);
}

//-------------------------------------------------------------------------------
bool Character::compare(const char* str1, const char* str2) {
  return (strcmp(str1, str2) == 0);
}

//-------------------------------------------------------------------------------
bool Character::compare(const char* str1, const char* str2, int length) {
  return (strncmp(str1, str2, static_cast<size_t>(length)) == 0);
}

//-------------------------------------------------------------------------------
bool Character::compareIgnoreCast(char src, char dst) {
  src = MACRO_TO_LOWER_CAST(src);
  dst = MACRO_TO_LOWER_CAST(dst);
  return (src == dst);
}

//-------------------------------------------------------------------------------
bool Character::compareIgnoreCast(const char* src1, char const* src2) {
  return (strcasecmp(src1, src2) == 0);
}

//-------------------------------------------------------------------------------
bool Character::compareIgnoreCast(const char* src1, char const* src2, int length) {
  return (strncasecmp(src1, src2, static_cast<size_t>(length)) == 0);
}

//-------------------------------------------------------------------------------
int Character::length(const void* src) {
  return static_cast<int>(strlen(static_cast<const char*>(src)));
}

//-------------------------------------------------------------------------------
bool Character::isHexString(const void* src) {
  mframe::io::ReadOnlyBuffer readOnlyBuffer = mframe::io::ReadOnlyBuffer(static_cast<const char*>(src));
  mframe::util::Iterator<char> iterator = mframe::util::Iterator<char>(readOnlyBuffer);
  return Character::isHexString(iterator);
}

//-------------------------------------------------------------------------------
bool Character::isHexString(mframe::util::Iterator<char>& iterator) {
  bool result = false;
  char cache;
  if (iterator.next(cache))
    return false;

  if (Character::isHexChar(cache))
    result = true;

  while (result) {
    if (iterator.next(cache))
      break;

    if (Character::isNextLineSymbol(cache))
      break;

    result = Character::isHexChar(cache);
  }

  return result;
}

//-------------------------------------------------------------------------------
bool Character::parseHexString(void* result, const void* src) {
  mframe::io::ReadOnlyBuffer readOnlyBuffer = mframe::io::ReadOnlyBuffer(static_cast<const char*>(src));
  mframe::util::Iterator<char> iterator = mframe::util::Iterator<char>(readOnlyBuffer);
  return Character::parseHexString(result, iterator);
}

//-------------------------------------------------------------------------------
bool Character::parseHexString(void* result, mframe::util::Iterator<char>& iterator) {
  if(!Character::isHexString(iterator))
    return false;
  
  int shift = 0;
  char* str = static_cast<char*>(result);
  while(true){
    char chHigh = '0';
    iterator.next(chHigh);
    char chLow = '0';
    iterator.next(chLow);
    str[shift] = Character::hexCharToChar(chHigh, chLow);
    if(!iterator.hasNext())
      break;
  }

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
