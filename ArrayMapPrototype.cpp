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
#include "./ArrayMapPrototype.h"

#include "./Class.h"

/* ****************************************************************************************
 * Namespace
 */
typedef struct {
  int key;
  void* value;
} array_map_prototype_t;
/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::ArrayMapPrototype;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
ArrayMapPrototype::ArrayMapPrototype(const lang::Memory& memory) : mMemory(memory) {
  this->mMemory.wipe();
  this->mSize = 0;
  return;
}

ArrayMapPrototype::ArrayMapPrototype(int size) : mMemory(static_cast<size_t>(size * 8)) {
  this->mMemory.wipe();
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------------------
ArrayMapPrototype::~ArrayMapPrototype(void) {
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

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::containsKeyHash(int hashcode) {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key) {
      if (p[i].key == hashcode)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::containsValue(void* value) {
  if(value == nullptr)
    return false;

  int len = this->size();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key) {
      if (p[i].value == value)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::getHash(int hashcode) {
  int len = this->size();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key == hashcode) {
      return p[i].value;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::putHash(int hashcode, void* value) {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;
      p[i].value = value;

      return result;
    }
  }
  
  if(this->mSize >= this->length()){// over length
    bool status = this->mMemory.resize(8 + static_cast<int>(this->mMemory.length() * 1.5));
    if(!status)
      return value;
  }

  p[this->mSize].key = hashcode;
  p[this->mSize].value = value;
  
  ++this->mSize;
  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::removeHash(int hashcode) {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {

      void* result = p[i].value;

      p[i] = p[this->mSize -1];
      this->mSize--;
      
      return result;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::replaceHash(int hashcode, void* value) {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {

      void* result = p[i].value;
      p[i].value = value;

      return result;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void ArrayMapPrototype::clear(void) {
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::isEmpty(void) const {
  if(this->mSize)
    return false;

  return true;
}

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::size(void) const {
  return this->mSize;
}

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::length(void) const {
  return (this->mMemory.length() / 8);
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
