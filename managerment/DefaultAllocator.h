/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1
#define MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../../lang/Object.h"
#include "./../../lang/managerment/Allocator.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang::managerment {
  class DefaultAllocator;

}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::managerment::DefaultAllocator : public mframe::lang::Object,
                                                    public mframe::lang::managerment::Allocator {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  DefaultAllocator(void);

  virtual ~DefaultAllocator(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> mframe::lang::managerment::Allocator
   */
 public:
  virtual void* alloc(int size) override;

  virtual bool free(void* ptr) override;

  virtual bool free(void* ptr, int size) override;

  virtual void* allocAlignment32(int size) override;

  virtual void* allocAlignment64(int size) override;

  virtual int getFree(void) override;

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_0F21FC8D_526B_44F7_979F_3BE0419947B1 */
