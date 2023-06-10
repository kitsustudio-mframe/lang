/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655
#define MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./Object.h"
#include "./Supplier.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang {
  template <class C, class R>
  class SupplierMethod;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
template <class C, class R>
class lang::SupplierMethod : public lang::Object,
                             public lang::Supplier<R> {
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
  R (C::*mMethod)
  (void);

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
  SupplierMethod(C& c, R (C::*method)(void)) : mClass(c) {
    this->mMethod = method;
    return;
  }

  virtual ~SupplierMethod(void) override {
    return;
  }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Supplier
   */
 public:
  virtual R get(void) override {
    return (this->mClass.*this->mMethod)();
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

#endif /* MFRAME_D21F5BD6_B86D_4F00_9B75_6C49DC808655 */
