/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_7EB43082_1596_43AB_9C6E_93D8D36DE60D
#define LANG_7EB43082_1596_43AB_9C6E_93D8D36DE60D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./ArrayMapPrototype.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang {
  template <class V>
  class ArrayMap;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class V>
class lang::ArrayMap : public lang::ArrayMapPrototype, public lang::Map<V> {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Array Map object
   *
   * @param memory
   */
  ArrayMap(const lang::Memory& memory) : ArrayMapPrototype(memory) {
    return;
  }

  /**
   * @brief Construct a new Array Map object
   *
   * @param size
   */
  ArrayMap(int size) : ArrayMapPrototype(size) {
    return;
  }

  /**
   * @brief Destroy the Array Map object
   *
   */
  virtual ~ArrayMap(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Map
   */
 public:
  virtual bool containsKey(Interface& key) override {
    return this->prototypeContainsKey(key);
  }

  virtual bool containsValue(void* value) override {
    return this->prototypeContainsValue(value);
  }

  virtual V* get(Interface& key) override {
    return static_cast<V*>(this->prototypeGet(key));
  }

  virtual V* put(Interface& key, V* value) override {
    return static_cast<V*>(this->prototypePut(key, value));
  }

  virtual V* remove(Interface& key) override {
    return static_cast<V*>(this->prototypeRemove(key));
  }

  virtual V* replace(Interface& key, V* value) override {
    return static_cast<V*>(this->prototypeReplace(key, value));
  }

  virtual void clear(void) override {
    this->prototypeClear();
  }

  virtual bool isEmpty(void) const override {
    return this->prototypeIsEmpty();
  }

  virtual int size(void) const override {
    return this->prototypeSize();
  }

  /* **************************************************************************************
   * Public Method
   */
 public:
  int length(void) {
    return this->prototypeLength();
  }

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_7EB43082_1596_43AB_9C6E_93D8D36DE60D */
