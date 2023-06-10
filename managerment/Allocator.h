/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_A640D444_DED9_463A_8F4A_E407A682DBAC
#define MFRAME_A640D444_DED9_463A_8F4A_E407A682DBAC

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../../lang/Interface.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang::managerment {
  struct Allocator;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
struct lang::managerment::Allocator : public virtual lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param size
   */
  virtual void* alloc(uint32_t size) abstract;

  /**
   * @brief
   *
   * @param ptr
   * @return true
   * @return false
   */
  virtual bool free(void* ptr) abstract;

  /**
   * @brief
   *
   * @param ptr
   * @param size
   * @return true
   * @return false
   */
  virtual bool free(void* ptr, uint32_t size) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_A640D444_DED9_463A_8F4A_E407A682DBAC */
