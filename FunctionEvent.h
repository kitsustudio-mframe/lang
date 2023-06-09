/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D
#define MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Function.h"
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <typename T, typename R>
  class FunctionEvent;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
template <typename T, typename R>
class mframe::lang::FunctionEvent : public mframe::lang::Object,
                                    public mframe::lang::Function<T, R> {
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
  R(*mMethod)
  (T);

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
   * @brief Construct a new Function Event object
   *
   * @param event
   */
  FunctionEvent(R (*method)(T)) {
    this->mMethod = method;
    return;
  }

  /**
   * @brief Destroy the Function Event object
   *
   */
  virtual ~FunctionEvent(void) override {
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
 public:
  /**
   * @brief
   *
   * @param t
   * @return R
   */
  virtual R apply(T t) {
    return this->mMethod(t);
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
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_F730676C_6AFB_43FF_A269_0F8D00511C5D */
