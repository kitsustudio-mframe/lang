/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B
#define MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Object.h"
#include "./../lang/Runnable.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class C>
  class RunnableMethod;
}  // namespace mframe::lang

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C>
class mframe::lang::RunnableMethod : public mframe::lang::Object,
                                     public mframe::lang::Runnable {
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
  void (C::*mMethod)(void);

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
   * @brief Construct a new Runnable Method object
   *
   * @param c
   * @param method
   */
  RunnableMethod(C& c, void (C::*method)(void)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Runnable Method object
   *
   */
  virtual ~RunnableMethod(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mframe::lang::Runnable
   */
 public:
  virtual void run(void) override {
    (this->mClass.*this->mMethod)();
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

#endif /* MFRAME_3B92E2D6_6975_43AB_9A11_1A8EE738C26B */
