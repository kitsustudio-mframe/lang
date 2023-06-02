/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_F628179A_5A6B_4572_99A4_3338D77AED7B
#define LANG_F628179A_5A6B_4572_99A4_3338D77AED7B

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <typename V, typename A>
  struct CompletionHandler;
}

/* ******************************************************************************
 * Class/struct/Struct
 */
template <typename V, typename A>
struct lang::CompletionHandler : public virtual lang::Interface {
  /* ****************************************************************************
   *  Method
   */

  /**
   * @brief
   *
   * @param result
   * @param attachment
   */
  virtual void completed(V result, A attachment) abstract;

  /**
   * @brief
   *
   * @param exc
   * @param attachment
   */
  virtual void failed(void* exc, A attachment) abstract;
};

/* *******************************************************************************
 *    End of file
 */

#endif /* LANG_F628179A_5A6B_4572_99A4_3338D77AED7B */
