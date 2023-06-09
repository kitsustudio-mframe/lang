/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6
#define MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Bytes;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::Bytes final : public mframe::lang::Object {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

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
 private:
  /**
   *
   */
  Bytes(void);

 public:
  /**
   *
   */
  virtual ~Bytes(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief
   *
   * @param value
   * @return char
   */
  static inline unsigned char castUnsigned(char value) {
    return static_cast<unsigned char>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return char
   */
  static inline char castSigned(unsigned char value) {
    return static_cast<char>(value);
  }

  /* ****************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief
   *
   * @param str
   * @return char
   */
  static char valueOf(const char* str);

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

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

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_CAD6C6BA_43F2_4CE1_9A81_D130881FE7E6 */
