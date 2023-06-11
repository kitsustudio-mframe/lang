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
int Character::length(const char* src) {
  return static_cast<int>(strlen(src));
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
