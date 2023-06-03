/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_574AD0C2_CCFB_47E3_8947_EF72B95F966B
#define LANG_574AD0C2_CCFB_47E3_8947_EF72B95F966B

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./ReadBuffer.h"
#include "./WriteBuffer.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  struct Buffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
struct lang::Buffer : public lang::WriteBuffer, lang::ReadBuffer {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief
   *
   */
  virtual void flush(void) abstract;
};

/* ******************************************************************************
 * End of file
 */

#endif /* LANG_574AD0C2_CCFB_47E3_8947_EF72B95F966B */
