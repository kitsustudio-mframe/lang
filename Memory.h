/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21
#define MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Data.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Memory;
  class String;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::Memory : public mframe::lang::Data {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  Memory* mNext;

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
   * @brief Construct a new Memory object
   *
   * @param data
   */
  Memory(const Data& data);

  /**
   * @brief Construct a new Memory object
   *
   * @param pointer
   * @param length
   */
  Memory(const void* pointer, size_t length);

  /**
   * @brief Construct a new Memory object
   *
   * @param pointer
   * @param length
   */
  Memory(void* pointer, size_t length);

  /**
   * @brief Construct a new Memory object
   *
   * @param length
   */
  Memory(size_t length);

  /**
   * @brief 淺層克隆建構子
   *
   * @param other
   */
  Memory(const Memory& other);

  /**
   * @brief Destroy the Memory object
   *
   */
  virtual ~Memory(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief
   *
   * @return mframe::lang::Memory
   */
  static mframe::lang::Memory nullMemory(void);

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  inline bool isHeapMemory(void) const {
    return (this->mNext != nullptr);
  }

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param size
   * @return true
   * @return false
   */
  bool resize(int size);

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
 *  End of file
 */

#endif /* MFRAME_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21 */
