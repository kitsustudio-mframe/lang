/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8
#define LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Buffer.h"
#include "./Memory.h"

/* ******************************************************************************
 * Macro
 */
#ifndef VACCESS
#define VACCESS(type, target) (*static_cast<volatile type*>(&target))
#endif

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class RingBuffer;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */
class lang::RingBuffer : public lang::Memory,
                         public lang::Buffer {
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
  volatile uint32_t mCount;
  volatile uint32_t mHead;
  volatile uint32_t mTail;

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
  RingBuffer(void* buffer, uint32_t bufferSize);

  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param memory
   */
  RingBuffer(const lang::Memory& memory);

  /**
   * @brief Construct a new Ring Buffer object
   *
   * @param length
   */
  RingBuffer(uint32_t length);

  /**
   * @brief Destroy the Ring Buffer object
   *
   */
  virtual ~RingBuffer(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - lang::Buffer
   */
 public:
  /**
   * @brief
   *
   */
  virtual inline void flush(void) override {
    RingBuffer::mHead = RingBuffer::mTail abstract;
  }

  /* ****************************************************************************
   * Public Method <Override> - lang::ReadBuffer
   */
 public:
  virtual inline bool isEmpty(void) const override {
    return (this->mHead == this->mTail);
  }

  virtual inline int avariable(void) const override {
    return static_cast<int>(this->mHead - this->mTail);
  }

  virtual int pollByte(char& result) override;

  virtual int poll(lang::WriteBuffer& writeBuffer) override;

  virtual int poll(lang::WriteBuffer& writeBuffer, int length) override;

  virtual int poll(void* buffer, int bufferSize) override;

  virtual int skip(int value) override;

  /* ****************************************************************************
   * Public Method <Override> - lang::WriteBuffer
   */
 public:
  virtual inline bool isFull(void) const override {
    return (RingBuffer::avariable() >= static_cast<int>(RingBuffer::mCount));
  }

  virtual inline int remaining(void) const override {
    return (static_cast<int>(RingBuffer::mCount) - RingBuffer::avariable());
  }

  virtual int putByte(const char data) override;

  virtual int put(lang::ReadBuffer& readBuffer) override;

  virtual int put(lang::ReadBuffer& readBuffer, int length) override;

  virtual int put(const void* buffer, int length) override;

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief Return size the ring buffer.
   *
   * @return int Size of the ring buffer in bytes.
   */
  inline int getSize(void) {
    return static_cast<int>(RingBuffer::mCount);
  }

  /**
   * @brief Get the Head Position object
   *
   * @return int
   */
  inline int getHeadPosition(void) {
    return static_cast<int>((this->mHead & (RingBuffer::mCount - 1)));
  }

  /**
   * @brief Get the Tail Position object
   *
   * @return int
   */
  inline int getTailPosition(void) {
    return static_cast<int>((this->mTail & (RingBuffer::mCount - 1)));
  }

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

  /**
   *
   */
 private:
  void init(void);
};

/* *******************************************************************************
 * End of file
 */
#undef VACCESS
#endif /* LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8 */
