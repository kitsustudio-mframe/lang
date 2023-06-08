/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EABFB0E9_4CE7_4009_A990_B20F60799B41
#define LANG_EABFB0E9_4CE7_4009_A990_B20F60799B41

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./ArrayQueuePrototype.h"
#include "./Collection.h"
#include "./Queue.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <class E>
  class ArrayQueue;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
template <class E>
class lang::ArrayQueue : public lang::ArrayQueuePrototype,
                         public lang::Queue<E> {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */

  /* ****************************************************************************
   * Abstract method <Public>
   */

  /* ****************************************************************************
   * Abstract method <Protected>
   */

  /* ****************************************************************************
   * Construct Method
   */

 public:
  /**
   * @brief Construct a new Array Queue object
   *
   * @param memory
   */
  ArrayQueue(const Memory& memory) : lang::ArrayQueuePrototype(memory) {
    return;
  }

  /**
   * @brief Construct a new Array Queue object
   *
   * @param length
   */
  ArrayQueue(uint32_t length) : lang::ArrayQueuePrototype(length) {
    return;
  }

  /**
   * @brief Destroy the Array Queue object
   *
   */
  virtual ~ArrayQueue(void) override {
    return;
  }

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - lang::Queue<E>
   */
 public:
  virtual bool offer(E* e) override {
    return this->ArrayQueuePrototype::offerPointer(e);
  }

  virtual E* poll(void) override {
    return static_cast<E*>(this->ArrayQueuePrototype::pollPointer());
  }

  virtual E* peek(void) override {
    return static_cast<E*>(this->ArrayQueuePrototype::peekPointer());
  }

  /* ****************************************************************************
   * Public Method <Override> - lang::Collection<E>
   */
 public:
  virtual void clear(void) override {
    return this->ArrayQueuePrototype::clear();
  }

  virtual bool isEmpty(void) const override {
    return this->ArrayQueuePrototype::isEmpty();
  }

  virtual int size(void) const override {
    return this->ArrayQueuePrototype::size();
  }

  /* ****************************************************************************
   * Public Method <Override> - lang::Iteraable<E>
   */
 public:
  virtual bool peekIndex(int index, E*& result) override {
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wundefined-reinterpret-cast"
    
    return ArrayQueuePrototype::peekIndex(index, reinterpret_cast<void*&>(result));
    
    #pragma clang diagnostic pop
  }

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */

  /* ****************************************************************************
   * Private Method <Static>
   */

  /* ****************************************************************************
   * Private Method <Override>
   */

  /* ****************************************************************************
   * Private Method
   */
 private:
  using ArrayQueuePrototype::clear;
  using ArrayQueuePrototype::isEmpty;
  using ArrayQueuePrototype::size;
  using ArrayQueuePrototype::peekIndex;
  
};

/* *******************************************************************************
 * End of file
 */

#endif /* LANG_EABFB0E9_4CE7_4009_A990_B20F60799B41 */
