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
#include "./Interface.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <class T, class U>
  struct BiConsumer;
}

/* ******************************************************************************
 * Class/struct/Struct
 */
template <class T, class U>
struct lang::BiConsumer : public virtual lang::Interface {
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
