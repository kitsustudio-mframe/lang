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
    return ArrayMapPrototype::containsKeyHash(key.getObject().hashcode());
  }

  virtual bool containsValue(void* value) override {
    return ArrayMapPrototype::containsValue(value);
  }

  virtual V* get(Interface& key) override {
    return static_cast<V*>(ArrayMapPrototype::getHash(key.getObject().hashcode()));
  }

  virtual V* put(Interface& key, V* value) override {
    return static_cast<V*>(ArrayMapPrototype::putHash(key.getObject().hashcode(), value));
  }

  virtual V* remove(Interface& key) override {
    return static_cast<V*>(ArrayMapPrototype::removeHash(key.getObject().hashcode()));
  }

  virtual V* replace(Interface& key, V* value) override {
    return static_cast<V*>(ArrayMapPrototype::replaceHash(key.getObject().hashcode(), value));
  }

  virtual void clear(void) override{
    ArrayMapPrototype::clear();
  }

  virtual bool isEmpty(void) const override{
    return ArrayMapPrototype::isEmpty();
  }

  virtual int size(void) const override{
    return ArrayMapPrototype::size();
  }
  /* **************************************************************************************
   * Public Method
   */

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
