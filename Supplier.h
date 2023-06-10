/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_A59752C6_6883_4BC0_86C8_5C004260E415
#define MFRAME_A59752C6_6883_4BC0_86C8_5C004260E415

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Interface.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <class R>
  struct Supplier;
}

/* ******************************************************************************
 * Class/struct/Struct
 */
template <class R>
struct lang::Supplier : public virtual lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @return R
   */
  virtual R get(void) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_A59752C6_6883_4BC0_86C8_5C004260E415 */
