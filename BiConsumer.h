/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_CE48C601_AB18_4B36_8C89_8ACA733118B1
#define MFRAME_CE48C601_AB18_4B36_8C89_8ACA733118B1

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <class T, class U>
  struct BiConsumer;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
template <class T, class U>
struct mframe::lang::BiConsumer : public virtual mframe::lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param t
   * @param u
   */
  virtual void accept(T t, U u) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_CE48C601_AB18_4B36_8C89_8ACA733118B1 */
