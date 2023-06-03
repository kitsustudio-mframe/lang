/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05
#define MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05

/* ******************************************************************************
 * Include
 */

#include <stdarg.h>

//-------------------------------------------------------------------------------
#include "./Memory.h"
#include "./RingBuffer.h"
#include "./Strings.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class PrintBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::PrintBuffer final : public lang::RingBuffer {
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
   * @brief Construct a new Ring Buffer object
   *
   * @param buffer
   * @param bufferSize
   */
  PrintBuffer(void* buffer, uint32_t bufferSize);

  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param memory
   */
  PrintBuffer(const lang::Memory& memory);

  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param length
   */
  PrintBuffer(uint32_t length);

  /**
   * @brief Destroy the Print Stream object
   *
   */
  virtual ~PrintBuffer(void) override;

  /* ****************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @param b
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(bool b) {
    return this->print(b);
  }

  /**
   * @brief 
   * 
   * @param c 
   * @return PrintBuffer& 
   */
  inline PrintBuffer& operator<<(char c){
    return this->print(c);
  }

  /**
   * @brief
   *
   * @param i
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(int i) {
    return this->print(i);
  }

  /**
   * @brief
   *
   * @param d
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(double d) {
    return this->print(d);
  }

  /**
   * @brief
   *
   * @param str
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(const char* str) {
    return this->print(str);
  }

  /**
   * @brief
   *
   * @param str
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(lang::Strings& str) {
    return this->print(str);
  }

  /**
   * @brief
   *
   * @param r
   * @return PrintBuffer&
   */
  inline PrintBuffer& operator<<(lang::ReadBuffer& r) {
    return this->print(r);
  }

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   *
   * @param b
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(bool b) {
    return this->print(b, false);
  }

  /**
   * @brief
   *
   * @param c
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(char c) {
    return this->print(c, false);
  }

  /**
   * @brief
   *
   * @param d
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(double d) {
    return this->print(d, false);
  }

  /**
   * @brief
   *
   * @param f
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(float f) {
    return this->print(f, false);
  }

  /**
   * @brief
   *
   * @param i
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(int i) {
    return this->print(i, false, false);
  }

  /**
   * @brief
   *
   * @param i
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(unsigned int i) {
    return this->print(static_cast<int>(i), false, true);
  }

  /**
   * @brief
   *
   * @param string
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(const lang::Strings& string) {
    return this->print(string, false);
  }

  /**
   * @brief
   *
   * @param string
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(const char* string) {
    return this->print(string, false);
  }

  /**
   * @brief
   *
   * @param readBuffer
   * @return PrintBuffer&
   */
  inline PrintBuffer& print(lang::ReadBuffer& readBuffer) {
    return this->print(readBuffer, false);
  }

  /**
   * @brief
   *
   * @param b
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(bool b) {
    return this->print(b, true);
  }

  /**
   * @brief
   *
   * @param c
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(char c) {
    return this->print(c, true);
  }

  /**
   * @brief
   *
   * @param d
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(double d) {
    return this->print(d, true);
  }

  /**
   * @brief
   *
   * @param f
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(float f) {
    return this->print(f, true);
  }

  /**
   * @brief
   *
   * @param i
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(int i) {
    return this->print(i, true, false);
  }

  /**
   * @brief
   *
   * @param i
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(unsigned int i) {
    return this->print(static_cast<int>(i), true, true);
  }

  /**
   * @brief
   *
   * @param string
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(const lang::Strings& string) {
    return this->print(string, true);
  }

  /**
   * @brief
   *
   * @param string
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(const char* string) {
    return this->print(string, true);
  }

  /**
   * @brief
   *
   * @param readBuffer
   * @return PrintBuffer&
   */
  inline PrintBuffer& println(lang::ReadBuffer& readBuffer) {
    return this->print(readBuffer, true);
  }

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param b
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(bool b, bool newLine);

  /**
   * @brief
   *
   * @param c
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(char c, bool newLine);

  /**
   * @brief
   *
   * @param d
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(double d, bool newLine);

  /**
   * @brief
   *
   * @param f
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(float f, bool newLine);

  /**
   * @brief
   *
   * @param i
   * @param newLine
   * @param unsign
   * @return PrintBuffer&
   */
  PrintBuffer& print(int i, bool newLine, bool unsign);

  /**
   * @brief
   *
   * @param string
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(const lang::Strings& string, bool newLine);

  /**
   * @brief
   *
   * @param string
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(const char* string, bool newLine);

  /**
   * @brief
   *
   * @param readBuffer
   * @param newLine
   * @return PrintBuffer&
   */
  PrintBuffer& print(lang::ReadBuffer& readBuffer, bool newLine);

  /**
   * @brief
   *
   * @return PrintBuffer&
   */
  PrintBuffer& println(void);

  /**
   * @brief
   *
   * @param format
   * @param ...
   * @return PrintBuffer&
   */
  PrintBuffer& format(const char* format, ...);

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

#endif /* MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05 */
