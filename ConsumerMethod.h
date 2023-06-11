/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0
#define MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Consumer.h"
#include "./../lang/Object.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class C, class T>
  class ConsumerMethod;
}  // namespace mframe::lang

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C, class T>
class mframe::lang::ConsumerMethod : public mframe::lang::Object,
                                     public mframe::lang::Consumer<T> {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
 private:
  C& mClass;
  void (C::*mMethod)(T);

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
   * @brief Construct a new Consumer Method object
   *
   * @param c
   * @param method
   */
  ConsumerMethod(C& c, void (C::*method)(T)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Consumer Method object
   *
   */
  virtual ~ConsumerMethod(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::lang::Consumer
   */
 public:
  virtual void accept(T t) override {
    (this->mClass.*this->mMethod)(t);
    return;
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

#endif /* MFRAME_032A1167_8B13_49A3_B2ED_13F5C27C0CE0 */
