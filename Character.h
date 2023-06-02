/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629
#define MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Object.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class Character;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::Character final : public lang::Object {
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
   * @brief Construct a new Character object
   *
   */
  Character(void);

 public:
  /**
   * @brief Destroy the Character object
   *
   */
  virtual ~Character(void) override;

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
   * @param ch
   * @return char
   */
  static char toUpperCase(char ch);

  /**
   * @brief
   *
   * @param ch
   * @return char
   */
  static char toLowerCase(char ch);

  /**
   * @brief
   *
   * @param highChar
   * @param lowChar
   * @return char
   */
  static char hexCharToChar(char highChar, char lowChar);

  /**
   * @brief
   *
   * @param ch
   * @return char
   */
  static char hexCharToChar(char ch);

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

#endif /* MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629 */
