/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_FF6FBB65_4795_467C_8D77_53255923274A
#define MFRAME_FF6FBB65_4795_467C_8D77_53255923274A

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Interface.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  enum struct ThreadState : char;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
enum struct mframe::lang::ThreadState : char {
  /**
   * @brief Inactive.
   *        The thread is created but not actively used, or has been terminated
   *
   */
  INACTIVE,

  /**
   * @brief Ready.
   *        The thread is ready for execution but not currently running.
   *
   */
  READY,

  /**
   * @brief Running.
   *        The thread is currently running.
   *
   */
  RUNNING,

  /**
   * @brief Blocked.
   *        The thread is currently blocked (delayed, waiting for an event or suspended).
   *
   */
  BLOCKED,

  /**
   * @brief Terminated.
   *        The thread is terminated and all its resources are not yet freed
   *
   */
  TERMINATED,

  /**
   * @brief Error.
   *        The thread does not exist
   *
   */
  ERROR
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_FF6FBB65_4795_467C_8D77_53255923274A */
