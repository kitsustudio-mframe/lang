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
 * Public Method <Override> - lang::Iterable<E>
 */
//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::peekIndex(int index, void*& result){
  if(index < 0)
    return false;

  if(index >= this->size())
    return false;
  
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());
  result = p[index].value;
  return true;
}

/* ****************************************************************************************
 * Public Method <Override> - lang::Collection<E>
 */

//-----------------------------------------------------------------------------------------
void ArrayMapPrototype::clear(void) {
  this->mSize = 0;
  return;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::isEmpty(void) const {
  if (this->mSize)
    return false;

  return true;
}

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::size(void) const {
  return this->mSize;
}

/* ****************************************************************************************
 * Public Method <Override> - lang::Map<V>
 */

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::containsKey(Interface& key) const {
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());
  int hashcode = key.getObject().hashcode();

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key) {
      if (p[i].key == hashcode)
        return true;
    }
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool ArrayMapPrototype::containsValue(void** value) const {
  if (value == nullptr)
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
void** ArrayMapPrototype::get(Interface& key) const {
  int hashcode = key.getObject().hashcode();
  int len = this->size();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < len; ++i) {
    if (p[i].key == hashcode) {
      return static_cast<void**>(p[i].value);
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void** ArrayMapPrototype::put(Interface& key, void** value) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;
      p[i].value = value;

      return static_cast<void**>(result);
    }
  }

  if (this->mSize >= this->length()) {  // over length
    bool status = this->mMemory.resize(8 + static_cast<int>(this->mMemory.length() * 1.5));
    if (!status)
      return value;
  }

  p[this->mSize].key = hashcode;
  p[this->mSize].value = value;

  ++this->mSize;
  return nullptr;
}

//-----------------------------------------------------------------------------------------
void** ArrayMapPrototype::remove(Interface& key) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;

      p[i] = p[this->mSize - 1];
      this->mSize--;

      return static_cast<void**>(result);
    }
  }

  return nullptr;
}

//-----------------------------------------------------------------------------------------
void** ArrayMapPrototype::replace(Interface& key, void** value) {
  int hashcode = key.getObject().hashcode();
  array_map_prototype_t* p = this->mMemory.pointer(Class<array_map_prototype_t>::cast());

  for (int i = 0; i < this->mSize; ++i) {
    if (p[i].key == hashcode) {
      void* result = p[i].value;
      p[i].value = value;

      return static_cast<void**>(result);
    }
  }

  return nullptr;
}

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
int ArrayMapPrototype::length(void) const {
  return (this->mMemory.length() / 8);
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
