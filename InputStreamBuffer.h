/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_24732F21_BBC1_4AB0_8238_ACE2005FF0DF
#define LANG_24732F21_BBC1_4AB0_8238_ACE2005FF0DF

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./InputStream.h"
#include "./Runnable.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class InputStreamBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::InputStreamBuffer : public lang::InputStream,
                                public lang::WriteBuffer {
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
   * @brief Construct a new Input Stream Buffer object
   *
   */
  InputStreamBuffer(void);

  /**
   * @brief Destroy the Input Stream Buffer object
   *
   */
  virtual ~InputStreamBuffer(void) override;

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

  virtual int putByte(const char data) override;

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

#endif /* LANG_24732F21_BBC1_4AB0_8238_ACE2005FF0DF */
