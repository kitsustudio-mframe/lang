/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D
#define MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../lang/Object.h"
#include "./../util/Iterator.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Booleans;
}  // namespace mframe::lang

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::Booleans : public mframe::lang::Object {
  /* **************************************************************************************
   * Variable <Public>
   */
 public:
  static const char* TEXT_TRUE;
  static const char* TEXT_FALSE;
  static const int TEXT_TRUE_LENGTH;
  static const int TEXT_FALSE_LENGTH;

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
 private:
  Booleans(void) = default;

  virtual ~Booleans(void) override = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  static bool isBoolean(const char* str);

  static bool isBoolean(mframe::util::Iterator<char>& iterator);

  static bool parseBoolean(bool& result, const char* str);

  static bool parseBoolean(bool& result, mframe::util::Iterator<char>& iterable);

  /* **************************************************************************************
   * Public Method <Override>
   */

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

#endif /* MFRAME_90D9B92C_CB56_4072_B34E_C233A3D5684D */
