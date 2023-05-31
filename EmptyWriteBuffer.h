/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_53B50485_918E_4B71_A576_99D31C076375
#define LANG_53B50485_918E_4B71_A576_99D31C076375

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Object.h"
#include "./WriteBuffer.h"
/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class EmptyWriteBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::EmptyWriteBuffer : public lang::Object, public lang::WriteBuffer {
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
   * @brief Construct a new Empty Write Buffer object
   *
   */
  EmptyWriteBuffer(void);

  /**
   * @brief Destroy the Empty Write Buffer object
   *
   */
  virtual ~EmptyWriteBuffer(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - lang::WriteBuffer
   */
 public:
  virtual bool isFull(void) const override;

  virtual int remaining(void) const override;

  virtual bool putByte(const char data) override;

  virtual int put(lang::ReadBuffer& readBuffer) override;

  virtual int put(lang::ReadBuffer& readBuffer, int length) override;

  virtual int put(const void* buffer, int length) override;

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

#endif /* LANG_53B50485_918E_4B71_A576_99D31C076375 */
