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
#include "./Character.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::Character;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Character object
 * 
 */
Character::Character(void){
  return;
}

/**
 * @brief Destroy the Character object
 * 
 */
Character::~Character(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @param ch 
 * @return char 
 */
char Character::toUpperCase(char ch){
  if((ch >= 'a') && (ch <= 'z'))
    return (ch - 32);
  
  return ch;
}

/**
 * @brief 
 * 
 * @param ch 
 * @return char 
 */
char Character::toLowerCase(char ch){
  if((ch >= 'A') && (ch <= 'Z'))
    return (ch + 32);
  
  return ch;
}

/**
 * @brief 
 * 
 * @param highChar 
 * @param lowChar 
 * @return char 
 */
char Character::hexCharToChar(char highChar, char lowChar){
  char result = Character::hexCharToChar(lowChar);
  return static_cast<char>(result + (Character::hexCharToChar(highChar) << 4));
}

/**
 * @brief 
 * 
 * @param highChar 
 * @param lowChar 
 * @return char 
 */
char Character::hexCharToChar(char ch){
  ch = Character::toUpperCase(ch);
  
  if((ch >= '0') && (ch <= '9'))
    return (ch - '0');
  
  if((ch >= 'A') && (ch <= 'F'))
    return (ch - 'A' + 10);
  
  return 0;
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
