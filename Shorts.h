/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6
#define MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Shorts;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::Shorts final : public mframe::lang::Object {
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
  Shorts(void);

 public:
  /**
   *
   */
  virtual ~Shorts(void) override;

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
   * @return short
   */
  static inline unsigned short castUnsigned(short value) {
    return static_cast<unsigned short>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return short
   */
  static inline short castSigned(unsigned short value) {
    return static_cast<short>(value);
  }

  /* ****************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief
   *
   * @param str
   * @return short
   */
  static short valueOf(const char* str);

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

#endif /* MFRAME_6B6AAADD_762E_4D84_956A_0B5030792CA6 */
