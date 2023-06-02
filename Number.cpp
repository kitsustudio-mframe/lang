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
#include "./Number.h"
#include "./HashGen.h"

/* ******************************************************************************
 * Using
 */  
using lang::Number;

/* ******************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Number:: Number object
 * 
 */
Number::Number(void){
  Number::mValue.u32 = 0;
  return;
}

/**
 * @brief Destroy the Number:: Number object
 * 
 */
Number::~Number(void){
  Number::mValue.u32 = 0;
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> lang::Object
 */

//-------------------------------------------------------------------------------
int Number::hashcode(void) const{
  return lang::HashGen::getHashcode(&this->mValue, 4);
}

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
