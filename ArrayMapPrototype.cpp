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
bool ArrayMapPrototype::prototypeContainsKey(Interface& key) {
  int hash = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key) {
      if (p[i].key == hash)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::prototypeContainsValue(void* value) {
  int len = this->prototypeSize();
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
void* ArrayMapPrototype::prototypeGet(Interface& key) {
  int hash = key.getObject().hashcode();
  int len = this->prototypeSize();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key == hash) {
      return p[i].value;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::prototypePut(Interface& key, void* value) {
  int hash = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hash) {
      void* result = p[i].value;
      p[i].value = value;

      return result;
    }
  }
  
  if(this->mSize >= this->prototypeLength()){// over length
    bool status = this->mMemory.resize(8 + static_cast<int>(this->mMemory.length() * 1.5));
    if(!status)
      return value;
  }

  p[this->mSize].key = hash;
  p[this->mSize].value = value;
  
  ++this->mSize;
  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::prototypeRemove(Interface& key) {
  int hash = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hash) {

      void* result = p[i].value;

      p[i] = p[this->mSize -1];
      this->mSize--;
      
      return result;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void* ArrayMapPrototype::prototypeReplace(Interface& key, void* value) {
  int hash = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hash) {

      void* result = p[i].value;
      p[i].value = value;

      return result;
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void ArrayMapPrototype::prototypeClear(void) {
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::prototypeIsEmpty(void) const {
  if(this->mSize)
    return false;

  return true;
}

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::prototypeSize(void) const {
  return this->mSize;
}

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::prototypeLength(void) const {
  return (this->mMemory.length() / 8);
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
