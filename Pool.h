/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F
#define LANG_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./../func/Consumer.h"

//-----------------------------------------------------------------------------------------
#include "./Array.h"
#include "./Memory.h"
#include "./Collection.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  struct Pool;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct lang::Pool :public lang::Collection<lang::Memory>{

  /* **************************************************************************************
   * Method 
   */

  /**
   * @brief Returns this pool element size of byte
   * 
   * @return uint32_t element size of byte.
   */
  virtual uint32_t elementSize(void) const = 0;
  
  /**
   * @brief Returns this pool's capacity.
   * 
   * @return uint32_t The capacity of this pool.
   */
  virtual uint32_t capacity(void) const = 0;
  
  /**
   * @brief Alloc memory from pool.
   * 
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* alloc(void) = 0;

  /**
   * @brief 
   * 
   * @return mcuf::Memory 
   */
  virtual mcuf::Memory allocMemory(void) = 0;

  /**
   * @brief Alloc memory from pool and copy element.
   * 
   * @param elenemt Element pointer.
   * @return void* element pointer if pool not full, otherwise null pointer.
   */
  virtual void* add(const void* elenemt) = 0;

  /**
   * @brief Free this element memory.  
   * 
   * @param element Element pointer.
   * @return true this poll found element and remove.
   * @return false element not found in this pool.
   */
  virtual bool remove(void* element) = 0;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_B4F9BAD4_2126_4397_B252_0E3E47A7DA8F */
