/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_A35B63D2_8288_4C2E_ACB8_69DAC9906340
#define MFRAME_A35B63D2_8288_4C2E_ACB8_69DAC9906340

/* ******************************************************************************
 * Include
 */

#include "./../lang/Number.h"
//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Short;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class Short
 */
class mframe::lang::Short final : public mframe::lang::Number {
  /* ****************************************************************************
   * Subclass
   */

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
 public:
  /**
   * @brief Construct a new Short object
   *
   */
  Short(void);

  /**
   * @brief Construct a new Short object
   *
   * @param value
   */
  Short(short value);

  /**
   * @brief Destroy the Short object
   *
   */
  virtual ~Short(void) override;

  /* ****************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief Construct a new operator short object
   *
   */
  inline operator short(void) {
    return Short::mValue.s16[0];
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  inline bool operator==(int v) {
    return (Short::mValue.s16[0] == (v & 0x0000FFFF));
  }

  /**
   * @brief
   *
   * @param v
   * @return true
   * @return false
   */
  inline bool operator==(Short& v) {
    return (Short::mValue.s16[0] == v.mValue.s16[0]);
  }

  /**
   * @brief
   *
   * @param v
   * @return Short
   */
  Short operator=(Short v) {
    Short::mValue.s16[0] = v.mValue.s16[0];
    return Short::mValue.s16[0];
  }

  /**
   * @brief
   *
   * @param v
   * @return Short
   */
  Short operator+=(int v) {
    Short::mValue.s16[0] += v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Short
   */
  Short operator-=(int v) {
    Short::mValue.s16[0] -= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Short
   */
  Short operator*=(int v) {
    Short::mValue.s16[0] *= v;
    return *this;
  }

  /**
   * @brief
   *
   * @param v
   * @return Short
   */
  Short operator/=(int v) {
    Short::mValue.s16[0] /= v;
    return *this;
  }

  /**
   * @brief
   *
   * @return Short
   */
  Short operator++(int) {
    Short tmp = *this;
    ++Short::mValue.s16[0];
    return tmp;
  }

  /**
   * @brief
   *
   * @return Short
   */
  Short operator++(void) {
    ++Short::mValue.s16[0];
    return *this;
  }

  /**
   * @brief
   *
   * @return Short
   */
  Short operator--(int) {
    Short tmp = *this;
    --Short::mValue.s16[0];
    return tmp;
  }

  /**
   * @brief
   *
   * @return Short&
   */
  Short& operator--(void) {
    --Short::mValue.s16[0];
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
 * End of file
 */

#endif /* MFRAME_A35B63D2_8288_4C2E_ACB8_69DAC9906340 */
