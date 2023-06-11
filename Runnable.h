/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A
#define MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  struct Runnable;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
struct mframe::lang::Runnable : public virtual mframe::lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   */
  virtual void run(void) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_A54036B2_950E_4F06_9CD4_6FD23597926A */
