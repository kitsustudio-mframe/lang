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
#include "./Object.h"
#include "./System.h"

/* ******************************************************************************
 * Using
 */  
using lang::Object;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
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

/* ******************************************************************************
 * Operator Method
 */

/**
 * @brief 
 * 
 * @param n 
 * @return void* 
 */
void* Object::operator new(size_t n){
  void* result = ::operator new(n);
  if(result == nullptr)
    System::error("Object new", ErrorCode::INSUFFICIENT_MEMORY);
  
  return result;
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

/* ******************************************************************************
 * Public Method <Static>
 */
 
/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

/**
 *
 */
void Object::delay(int milliseconds) const{
  System::delay(milliseconds);
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
  System::wait(0);
  return;
}

/**
 *
 */
bool Object::wait(int timeout) const{
  return System::wait(timeout);
}

/**
 *
 */
bool Object::yield(void) const{
  return System::yield();
}

/**
 *
 */
int Object::lock(void) const{
  return System::lock();
}

/**
 *
 */
int Object::unlock(void) const{
  return System::unlock();
}

/**
 *
 */
int Object::hashcode(void) const{
  return reinterpret_cast<int>(this);
}

/**
 *
 */
lang::Thread* Object::currentThread(void) const{
  return System::currentThread();
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
