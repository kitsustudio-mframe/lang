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
 * @brief 
 * 
 * @param milliseconds 
 */
void Object::delay(int milliseconds) const{
  System::mKernel->kernelDelay(milliseconds);
  return;
}

/**
 * @brief 
 * 
 * @param object 
 * @return true 
 * @return false 
 */
bool Object::equals(Object* object) const{
  if(object == nullptr)
    return false;
  
  return (this->hashcode() == object->hashcode());
}

/**
 * @brief 
 * 
 * @param object 
 * @return true 
 * @return false 
 */
bool Object::equals(Object& object) const{
  return (this->hashcode() == object.hashcode());
}

/**
 * @brief 
 * 
 */
void Object::wait(void) const{
  System::mKernel->kernelWait(0);
  return;
}

/**
 * @brief 
 * 
 * @param timeout 
 * @return true 
 * @return false 
 */
bool Object::wait(int timeout) const{
  return System::mKernel->kernelWait(timeout);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::yield(void) const{
  return System::mKernel->kenrelYield();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
int Object::systemLock(void) const{
  return System::mKernel->kernelLock();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
int Object::systemUnlock(void) const{
  return System::mKernel->kernelUnlock();
}

/**
 * @brief 返回對象的哈希碼值。支持這種方法是為了散列表，如HashMap提供的那樣。
 * 
 * @return uint32_t 該對象的哈希碼值。
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
