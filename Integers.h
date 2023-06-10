/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9
#define MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Integer.h"
#include "./../lang/Object.h"
#include "./../util/Iterator.h"
//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class Integers;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::Integers final : public lang::Object {
  /* ****************************************************************************
   * Variable <Public>
   */
  public:
    static const char* TEXT_MAX_VALUE;
    static const char* TEXT_MIN_VALUE;
    static const int MAX_ASCII_VALUE;

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
  Integers(void) = default;

  /**
   *
   */
  virtual ~Integers(void) override = default;

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
   * @return Integer
   */
  static inline unsigned int castUnsigned(int value) {
    return static_cast<unsigned int>(value);
  }

  /**
   * @brief
   *
   * @param value
   * @return Integer
   */
  static inline int castSigned(unsigned int value) {
    return static_cast<int>(value);
  }

  /* ****************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief 
   * 
   * @param iterator 
   * @return true 
   * @return false 
   */
  static bool isInteger(util::Iterator<char>& iterator);

  /**
   * @brief 
   * 
   * @param str 
   * @return true 
   * @return false 
   */
  static bool isInteger(const char* str);

  /**
   * @brief 
   * 
   * @param result 
   * @param iterator 
   * @return true 
   * @return false 
   */
  static bool parseInteger(int& result, util::Iterator<char>& iterator);

  /**
   * @brief 
   * 
   * @param result 
   * @param str 
   * @return true 
   * @return false 
   */
  static bool parseInteger(int& result, const char* str);

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

#endif /* MFRAME_E2DC1ED1_7C31_4A99_AF60_2B859E6190C9 */
