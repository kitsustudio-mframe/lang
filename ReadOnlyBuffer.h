/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_58C89839_4FBA_4C6E_BDF8_4387141D879B
#define LANG_58C89839_4FBA_4C6E_BDF8_4387141D879B

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Data.h"
#include "./ReadBuffer.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class ReadOnlyBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::ReadOnlyBuffer : public lang::Data,
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
 private:
  int mPosition;

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
   * @brief Construct a new Readonly Output Buffer object
   *
   * @param str
   */
  ReadOnlyBuffer(const char* str);

  /**
   * @brief Construct a new Readonly Output Buffer object
   *
   * @param pointer
   * @param length
   */
  ReadOnlyBuffer(const void* pointer, size_t length);

  /**
   * @brief Destroy the Readonly Output Buffer object
   *
   */
  virtual ~ReadOnlyBuffer(void) override;

  /* ****************************************************************************
   * Operator Method
   */
 public:
  inline int operator=(int v) {
    this->position(v);
    return this->position();
  }

  inline void operator+=(int shift) {
    this->position(this->position() + shift);
  }

  inline void operator-=(int shift) {
    this->position(this->position() - shift);
  }

  inline unsigned int operator++(void) {
    this->position(this->position() + 1);
    return static_cast<unsigned int>(this->position());
  }

  inline unsigned int operator--(void) {
    this->position(this->position() - 1);
    return static_cast<unsigned int>(this->position());
  }

  inline unsigned int operator++(int) {
    unsigned int result = static_cast<unsigned int>(this->position());
    this->position(this->position() + 1);
    return result;
  }

  inline unsigned int operator--(int) {
    unsigned int result = static_cast<unsigned int>(this->position());
    this->position(this->position() - 1);
    return result;
  }
  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   *  Public Method <Override> - lang::Iterable<char>
   */
 public:
  virtual bool peek(int index, char& result) override;

  /* ****************************************************************************
   * Public Method <Override> - lang::ReadBuffer
   */
 public:
  inline virtual bool isEmpty(void) const override {
    return (this->mPosition >= this->length());
  }

  inline virtual int avariable(void) const override {
    return (this->length() - this->mPosition);
  }

  virtual int pollByte(char& result) override;

  virtual int poll(lang::WriteBuffer& writeBuffer) override;

  virtual int poll(lang::WriteBuffer& writeBuffer, int length) override;

  virtual int poll(void* buffer, int bufferSize) override;

  virtual int skip(int value) override;

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief
   *
   * @return unsigned int
   */
  inline int capacity(void) const {
    return this->length();
  }

  /**
   * @brief
   *
   * @return unsigned int
   */
  inline int position(void) const {
    return this->mPosition;
  }

  /**
   * @brief
   *
   */
  virtual void rewind(void) {
    this->mPosition = 0;
  }

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param newPosition
   * @return true
   * @return false
   */
  bool position(int newPosition);

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

#endif /* LANG_58C89839_4FBA_4C6E_BDF8_4387141D879B */
