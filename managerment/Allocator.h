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
namespace mframe::lang::managerment {
  struct Allocator;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
struct mframe::lang::managerment::Allocator : public virtual mframe::lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   * @param size
   */
  virtual void* alloc(int size) abstract;
  
  /**
   * @brief
   *
   * @param size
   * @return void*
   */
  virtual void* allocAlignment32(int size) abstract;

  /**
   * @brief
   *
   * @param size
   * @return void*
   */
  virtual void* allocAlignment64(int size) abstract;

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
  virtual bool free(void* ptr, int size) abstract;
  
  /**
   * @brief Get the Free object
   *
   * @return int
   */
  virtual int getFree(void) abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_A640D444_DED9_463A_8F4A_E407A682DBAC */
