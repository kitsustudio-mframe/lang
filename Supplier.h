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
#include "./../lang/Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class R>
  struct Supplier;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
template <class R>
struct mframe::lang::Supplier : public virtual mframe::lang::Interface {
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
