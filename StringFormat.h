/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311
#define MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../io/WriteBuffer.h"
#include "./../lang/Memory.h"
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class StringFormat;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::StringFormat final : public mframe::lang::Object {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  static char mFormatBuffer[];
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
  StringFormat(void);

 public:
  virtual ~StringFormat(void) override;

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
   * @param buffer
   * @param bufferSize
   * @param format
   * @param arg
   * @return int
   */
  static int pointerVa(void* buffer, size_t bufferSize, const char* format, va_list args);

  /**
   * @brief
   *
   * @param memory
   * @param format
   * @param arg
   * @return int
   */
  static int memoryVa(const mframe::lang::Memory& memory, const char* format, va_list args);

  /**
   * @brief
   *
   * @param writeBuffer
   * @param format
   * @param arg
   * @return int
   */
  static int writeBufferVa(mframe::io::WriteBuffer& writeBuffer, const char* format, va_list args);

  /**
   * @brief
   *
   * @param buffer
   * @param bufferSize
   * @param format
   * @param ...
   * @return int
   */
  static int pointer(void* buffer, unsigned int bufferSize, const char* format, ...);

  /**
   * @brief
   *
   * @param memory
   * @param format
   * @param ...
   * @return int
   */
  static int memory(const mframe::lang::Memory& memory, const char* format, ...);

  /**
   * @brief
   *
   * @param writeBuffer
   * @param format
   * @param ...
   * @return int
   */
  static int writeBuffer(mframe::io::WriteBuffer& writeBuffer, const char* format, ...);

  /**
   * @brief
   *
   * @param src
   * @param format
   * @param args
   * @return int
   */
  static int scanVa(const char* src, const char* format, va_list args);

  /**
   * @brief
   *
   * @param src
   * @param format
   * @param ...
   * @return int
   */
  static int scan(const char* src, const char* format, ...);
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

#endif /* MFRAME_5F596881_5E43_4F42_97D0_4B6E1F7ED311 */
