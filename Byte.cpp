/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */  

#include <stdlib.h>

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Byte.h"

/* ******************************************************************************
 * Using
 */  
using lang::Byte;

/* ******************************************************************************
 * Construct Method
 */

/* ******************************************************************************
 * Byte::operator Method
 */

/**
 * @brief Construct a new Byte:: Byte object
 * 
 */
Byte::Byte(void){
  return;
}

/**
 * @brief Construct a new Byte:: Byte object
 * 
 * @param value 
 */
Byte::Byte(char value){
  this->mValue.u8[0] = value;
  return;
}

/**
 * @brief Destroy the Byte:: Byte object
 * 
 */
Byte::~Byte(void){
  return;
}

/* ******************************************************************************
 * Public Method <Static>
 */

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
