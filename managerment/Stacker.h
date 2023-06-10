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
namespace lang::managerment {
  class Stacker;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
class lang::managerment::Stacker : public lang::Memory,
                                   public util::Collection<lang::Memory>,
                                   public lang::managerment::Allocator {
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
  Stacker(void* buffer, uint32_t size);

  /**
   * @brief Construct a new Stacker object
   *
   * @param memory
   */
  Stacker(const lang::Memory& memory);

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
   * Public Method <Override> util::Collection<lang::Memory>
   */
 public:

  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

  /* ****************************************************************************
   * Public Method <Override> lang::managerment::Allocator
   */
 public:

  virtual void* alloc(uint32_t size) override;

  virtual bool free(void* ptr) override;

  virtual bool free(void* ptr, uint32_t size) override;

  /* ****************************************************************************
   * Public Method
   */
 public:
 
  /**
   * @brief Get the Free object
   *
   * @return uint32_t
   */
  virtual uint32_t getFree(void);

  /**
   * @brief
   *
   * @param size
   * @return void*
   */
  virtual void* allocAlignment32(uint32_t size);

  /**
   * @brief
   *
   * @param size
   * @return void*
   */
  virtual void* allocAlignment64(uint32_t size);

  /**
   * @brief
   *
   * @param size
   * @return lang::Memory
   */
  virtual lang::Memory allocMemory(uint32_t size);

  /**
   * @brief
   *
   * @param size
   * @return lang::Memory
   */
  virtual lang::Memory allocMemoryAlignment32(uint32_t size);

  /**
   * @brief
   *
   * @param size
   * @return lang::Memory
   */
  virtual lang::Memory allocMemoryAlignment64(uint32_t size);

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
