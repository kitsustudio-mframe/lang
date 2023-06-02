/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_9211D576_B0C2_4C52_93CE_C47BB00192E1
#define LANG_9211D576_B0C2_4C52_93CE_C47BB00192E1

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Object.h"
#include "./ReadBuffer.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class EmptyReadBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::EmptyReadBuffer : public lang::Object, public lang::ReadBuffer {
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
   * @brief Construct a new Empty Read Buffer object
   *
   */
  EmptyReadBuffer(void);

  /**
   * @brief Destroy the Empty Read Buffer object
   *
   */
  virtual ~EmptyReadBuffer(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - lang::ReadBuffer
   */
 public:
  virtual bool isEmpty(void) const override;

  virtual int avariable(void) const override;

  virtual int getByte(char& result) override;

  virtual int get(lang::WriteBuffer& writeBuffer) override;

  virtual int get(lang::WriteBuffer& writeBuffer, int length) override;

  virtual int get(void* buffer, int bufferSize) override;

  virtual int skip(int value) override;
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

#endif /* LANG_9211D576_B0C2_4C52_93CE_C47BB00192E1 */
