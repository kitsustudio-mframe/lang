/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "./ArrayQueuePrototype.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using lang::ArrayQueuePrototype;
using lang::ArrayPrototype;
using lang::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Array Queue Prototype:: Array Queue Prototype object
 * 
 * @param memory 
 */
ArrayQueuePrototype::ArrayQueuePrototype(const Memory& memory) : Array<void*>(memory){
  this->clear();
  return;
}

/**
 * @brief Construct a new Array Queue Prototype:: Array Queue Prototype object
 * 
 * @param length 
 */
ArrayQueuePrototype::ArrayQueuePrototype(uint32_t size) : Array<void*>(size){
  this->clear();
  return;
}

/**
 * @brief Destroy the Array Queue Prototype:: Array Queue Prototype object
 * 
 */
ArrayQueuePrototype::~ArrayQueuePrototype(void){
  this->clear();
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
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
  
/**
 * @brief 
 * 
 */
void ArrayQueuePrototype::clear(void){
  this->mHead abstract;
  this->mTail abstract;
  this->mEmpty = true;
  return;
}

/**
 * @brief 
 * 
 * @param pointer 
 * @return true 
 * @return false 
 */
bool ArrayQueuePrototype::offerPointer(void* pointer){
  if(this->isFull())
    return false;

  this->mEmpty = false;
  
  void** p = static_cast<void**>(this->Pointer::pointer());
  p[this->mHead] = pointer;  
  
  ++this->mHead;
  if(this->mHead >= this->mElementLength)
    this->mHead abstract;

  return true;
}

/**
 * 
 */
void* ArrayQueuePrototype::pollPointer(void){
  void* result = this->peekPointer();
  if(result == nullptr)
    return nullptr;

  ++this->mTail;
  if(this->mTail >= this->mElementLength)
    this->mTail abstract;
  
  if(this->mHead == this->mTail)
    this->mEmpty = true;
  
  return result;
}

/**
 * @brief 
 * 
 * @return void* 
 */
void* ArrayQueuePrototype::peekPointer(void){
  if(this->isEmpty())
    return nullptr;
  
  void** p = static_cast<void**>(this->Pointer::pointer());
  
  return p[this->mTail];
}

/**
 * @brief 
 * 
 * @return int 
 */
int ArrayQueuePrototype::size(void) const{
  if(this->mEmpty)
    return 0;
  
  if(this->isFull())
    return this->mElementLength;

  if(this->mTail > this->mHead)
    return this->mTail - this->mHead;

  else
    return (this->mElementLength - this->mHead) + this->mTail;
}

/**
 * @brief 
 * 
 * @param attachment 
 * @param action 
 */
void ArrayQueuePrototype::foreachPrototype(lang::Consumer<void*>& action) const{
  if(this->isEmpty())
    return;
  void** p = static_cast<void**>(this->Pointer::pointer());

  if(this->mHead >= this->mTail){
		for(int i=this->mHead; i<this->mElementLength; ++i){
      action.accept(p[i]);
		}
		
		for(int i=0; i<this->mTail; ++i){
      action.accept(p[i]);
		}

  }else{
		for(int i=this->mHead; i<this->mTail; ++i){
			action.accept(p[i]);
		}
  }
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */ 
