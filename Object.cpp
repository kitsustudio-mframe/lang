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
#include "./Object.h"
#include "./System.h"

/* ****************************************************************************************
 * Using
 */  
using lang::Object;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Object:: Object object
 * 
 */
Object::Object(void){
  return;
}

/**
 * @brief Destroy the Object:: Object object
 * 
 */
Object::~Object(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * @brief 
 * 
 * @param n 
 * @return void* 
 */
void* Object::operator new(size_t n){
  return ::operator new(n);
}

/**
 * @brief 
 * 
 * @param n 
 * @param p 
 * @return void* 
 */
void* Object::operator new(size_t n, void* const p){
  return p;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
void Object::delay(int milliseconds) const{
  System::mKernel->kernelDelay(milliseconds);
  return;
}

/**
 *
 */
bool Object::equals(Object* object) const{
  if(object == nullptr)
    return false;
  
  return (this->hashcode() == object->hashcode());
}

/**
 *
 */
bool Object::equals(Object& object) const{
  return (this->hashcode() == object.hashcode());
}

/**
 *
 */
void Object::wait(void) const{
  System::mKernel->kernelWait(0);
  return;
}

/**
 *
 */
bool Object::wait(int timeout) const{
  return System::mKernel->kernelWait(timeout);
}

/**
 *
 */
bool Object::yield(void) const{
  return System::mKernel->kenrelYield();
}

/**
 *
 */
int Object::systemLock(void) const{
  return System::mKernel->kernelLock();
}

/**
 *
 */
int Object::systemUnlock(void) const{
  return System::mKernel->kernelUnlock();
}

/**
 *
 */
uint32_t Object::hashcode(void) const{
  return reinterpret_cast<uint32_t>(this);
}

/* **************************************************************************************
 * Public Method <Override> - lang::Interface
 */
/**
 * @brief 
 * 
 * @return lang::Object& 
 */
lang::Object& Object::getObject(void){
  return *this;
}

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
