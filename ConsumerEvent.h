/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977
#define MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Consumer.h"
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <typename T>
  class ConsumerEvent;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
template <typename T>
class mframe::lang::ConsumerEvent : public mframe::lang::Object,
                                    public mframe::lang::Consumer<T> {
  typedef void (*Method)(T);
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  Method mMethod;

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
   * @brief Construct a new Consumer Event object
   *
   * @param event
   */
  ConsumerEvent(Method method) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Consumer Event object
   *
   */
  virtual ~ConsumerEvent(void) override {
    return;
  }

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */
 public:
  /**
   * @brief
   *
   * @param t
   */
  virtual void accept(T t) {
    this->mMethod(t);
  }

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
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_D2D64DF4_37AF_4608_A7A7_C551E3231977 */
