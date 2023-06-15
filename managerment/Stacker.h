/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46
#define MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../../lang/Memory.h"
#include "./../../lang/managerment/Allocator.h"
#include "./../../util/Collection.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang::managerment {
  class Stacker;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
class mframe::lang::managerment::Stacker : public mframe::lang::Memory,
                                           public mframe::util::Collection<void*>,
                                           public mframe::lang::managerment::Allocator {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
 protected:
  uint8_t* mStackPointer;

  /* ****************************************************************************
   * Variable <Private>
   */

  /* ****************************************************************************
   * Abstract method <Public>
   */

  /* ****************************************************************************
   * Abstract method <Protected>
   */

  /* ****************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new Stacker object
   *
   * @param buffer
   * @param size
   */
  Stacker(void* buffer, int size);

  /**
   * @brief Construct a new Stacker object
   *
   * @param memory
   */
  Stacker(const mframe::lang::Memory& memory);

  /**
   * @brief Destroy the Stacker object
   *
   */
  virtual ~Stacker(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */
  /* ****************************************************************************
   * Public Method <Override> mframe::util::Iterable<mframe::lang::Data*>
   */
 public:
  virtual bool peekIndex(int index, void*& result) override;

  /* ****************************************************************************
   * Public Method <Override> mframe::util::Collection<mframe::lang::Memory>
   */
 public:
  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

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

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemory(int size);

  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemoryAlignment32(int size);

  /**
   * @brief
   *
   * @param size
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Memory allocMemoryAlignment64(int size);

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */

  /* ****************************************************************************
   * Private Method <Static>
   */

  /* ****************************************************************************
   * Private Method <Override>
   */

  /* ****************************************************************************
   * Private Method
   */
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_C045F3C4_B727_4170_9124_44EFD0DADB46 */
