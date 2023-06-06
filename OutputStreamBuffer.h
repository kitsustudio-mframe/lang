/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_F33833E8_A946_4AD2_B467_0E7FD2EE8911
#define LANG_F33833E8_A946_4AD2_B467_0E7FD2EE8911

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./OutputStream.h"
#include "./ReadBuffer.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class OutputStreamBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::OutputStreamBuffer : public lang::OutputStream,
                                 public lang::ReadBuffer {
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
   * @brief Construct a new Output Stream Buffer object
   *
   */
  OutputStreamBuffer(void);

  /**
   * @brief Destroy the Output Stream Buffer object
   *
   */
  virtual ~OutputStreamBuffer(void) override;

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

  virtual int pollByte(char& result) override;

  virtual int poll(lang::WriteBuffer& writeBuffer) override;

  virtual int poll(lang::WriteBuffer& writeBuffer, int length) override;

  virtual int poll(void* buffer, int bufferSize) override;

  virtual int skip(int value) override;

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

#endif /* LANG_F33833E8_A946_4AD2_B467_0E7FD2EE8911 */
