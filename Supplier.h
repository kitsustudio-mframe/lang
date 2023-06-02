/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_A59752C6_6883_4BC0_86C8_5C004260E415
#define LANG_A59752C6_6883_4BC0_86C8_5C004260E415

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
  template <typename T>
  struct Supplier;
}

/* ******************************************************************************
 * Class/struct/Struct
 */
template <typename T>
struct lang::Supplier : public virtual lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @return T
   */
  virtual T get(void) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* LANG_A59752C6_6883_4BC0_86C8_5C004260E415 */
