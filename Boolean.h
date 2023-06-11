/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A
#define MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Number.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Boolean;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class Boolean
 */
class mframe::lang::Boolean final : public mframe::lang::Number {
  /* ****************************************************************************
   * Subclass
   */

  /* ****************************************************************************
   * valueariable <Public>
   */
 public:
  static const bool VALUE_TRUE = true;
  static const bool VALUE_FALSE = false;

  /* ****************************************************************************
   * valueariable <Protected>
   */

  /* ****************************************************************************
   * valueariable <Private>
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
   * @brief Construct a new Boolean object
   *
   */
  Boolean(void);

  /**
   * @brief Construct a new Boolean object
   *
   * @param valuealue
   */
  Boolean(bool valuealue);

  /**
   * @brief Destroy the Boolean object
   *
   */
  virtual ~Boolean(void) override;

  /* ****************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief Construct a new operator bool object
   *
   */
  operator bool(void) {
    return Boolean::mValue.b;
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(bool v) {
    return (static_cast<bool>(Boolean::mValue.b) == v);
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator==(Boolean& v) {
    return (Boolean::mValue.b == v.mValue.b);
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  bool operator=(bool v) {
    Boolean::mValue.b = v;
    return Boolean::mValue.b;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator+=(int v) {
    if (v > 0)
      Boolean::mValue.b = true;

    else if (v < 0)
      Boolean::mValue.b = false;

    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator-=(int v) {
    if (v < 0)
      Boolean::mValue.b = true;

    else if (v > 0)
      Boolean::mValue.b = false;

    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator*=(int v) {
    Boolean::mValue.b *= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Boolean
   */
  Boolean operator/=(int v) {
    Boolean::mValue.b /= v;
    return *this;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator++(int) {
    Boolean tmp = *this;
    Boolean::mValue.b = true;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator++() {
    Boolean::mValue.b = true;
    return *this;
  }

  /**
   * @brief
   *
   * @return Boolean
   */
  Boolean operator--(int) {
    Boolean tmp = *this;
    Boolean::mValue.b = false;
    return tmp;
  }

  /**
   * @brief
   *
   * @return Boolean&
   */
  Boolean& operator--() {
    Boolean::mValue.b = false;
    return *this;
  }

  /* ****************************************************************************
   * Public Method <Static>
   */

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

/* *******************************************************************************
 *  End of file
 */

#endif /* MFRAME_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A */
