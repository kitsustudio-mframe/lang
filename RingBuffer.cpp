/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./RingBuffer.h"

#include "./Class.h"
#include "./Pointers.h"
#include "./Integers.h"

/* ******************************************************************************
 * Macro
 */
#define INDH() (static_cast<int>(RingBuffer::mHead & (RingBuffer::mCount - 1)))
#define INDT() (static_cast<int>(RingBuffer::mTail & (RingBuffer::mCount - 1)))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* ******************************************************************************
 * Using
 */
using lang::Memory;
using lang::ReadBuffer;
using lang::RingBuffer;
using lang::WriteBuffer;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
RingBuffer::RingBuffer(void* buffer, uint32_t bufferSize) : Memory(buffer, bufferSize) {
  RingBuffer::init();
  return;
}

//-------------------------------------------------------------------------------
RingBuffer::RingBuffer(const Memory& memory) : Memory(memory) {
  RingBuffer::init();
  return;
}

//-------------------------------------------------------------------------------
RingBuffer::RingBuffer(uint32_t length) : Memory(length) {
  RingBuffer::init();
  return;
}

//-------------------------------------------------------------------------------
RingBuffer::~RingBuffer(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 *  Public Method <Override> - lang::Iterable<char>
 */
bool RingBuffer::peek(int index, char& result) {
  if (index >= this->avariable())
    return false;

  int ptrIndex = static_cast<int>((this->mTail + Integers::castUnsigned(index)) & (this->mCount - 1));
  result = *this->pointer(ptrIndex, Class<char>::cast());

  return true;
}

/* ******************************************************************************
 * Public Method <Override> - lang::ReadBuffer
 */

//-------------------------------------------------------------------------------
int RingBuffer::putByte(const char result) {
  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());

  /* We cannot insert when queue is full */
  if (RingBuffer::isFull())
    return -1;

  ptr += INDH();
  *(static_cast<uint8_t*>(ptr)) = (static_cast<const uint8_t>(result));
  RingBuffer::mHead++;

  return this->remaining();
}

//-------------------------------------------------------------------------------
int RingBuffer::put(ReadBuffer& outputBuffer) {
  return RingBuffer::put(outputBuffer, outputBuffer.avariable());
}

//-------------------------------------------------------------------------------
int RingBuffer::put(ReadBuffer& outputBuffer, int length) {
  if (length <= 0)
    return 0;

  int num = outputBuffer.avariable();
  if (num > length)
    num = length;

  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (RingBuffer::isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::remaining();
  if (INDH() + cnt1 >= static_cast<int>(RingBuffer::mCount))
    cnt1 = static_cast<int>(RingBuffer::mCount) - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  outputBuffer.poll(ptr, cnt1);
  RingBuffer::mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDH();
  outputBuffer.poll(ptr, cnt2);
  RingBuffer::mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

//-------------------------------------------------------------------------------
int RingBuffer::put(const void* data, int num) {
  if (num <= 0)
    return 0;

  if (data == nullptr) {
    uint32_t max = static_cast<uint32_t>(RingBuffer::remaining());

    if (static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    RingBuffer::mHead += static_cast<uint32_t>(num);
    return static_cast<int>(num);
  }

  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (RingBuffer::isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::remaining();
  if (INDH() + cnt1 >= static_cast<int>(RingBuffer::mCount))
    cnt1 = static_cast<int>(RingBuffer::mCount) - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  Pointers::copy(ptr, data, cnt1);
  RingBuffer::mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDH();
  data = static_cast<const uint8_t*>(data) + cnt1;
  Pointers::copy(ptr, data, cnt2);
  RingBuffer::mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

/* ******************************************************************************
 * Public Method <Override> - lang::WriteBuffer
 */

//-------------------------------------------------------------------------------
int RingBuffer::pollByte(char& data) {
  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());

  /* We cannot pop when queue is empty */
  if (RingBuffer::isEmpty())
    return -1;

  ptr += INDT();
  data = static_cast<char>(*ptr);
  ++RingBuffer::mTail;

  return this->avariable();
}

//-------------------------------------------------------------------------------
int RingBuffer::poll(WriteBuffer& inputBuffer) {
  return RingBuffer::poll(inputBuffer, inputBuffer.remaining());
}

//-------------------------------------------------------------------------------
int RingBuffer::poll(lang::WriteBuffer& inputBuffer, int length) {
  if (length <= 0)
    return 0;

  int num = inputBuffer.remaining();
  if (num > length)
    num = length;

  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (RingBuffer::isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::avariable();
  if (INDT() + cnt1 >= static_cast<int>(RingBuffer::mCount))
    cnt1 = static_cast<int>(RingBuffer::mCount) - INDT();

  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  inputBuffer.put(ptr, cnt1);
  RingBuffer::mTail += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDT();
  inputBuffer.put(ptr, cnt2);
  RingBuffer::mTail += static_cast<uint32_t>(cnt2);

  return cnt1 + cnt2;
}

//-------------------------------------------------------------------------------
int RingBuffer::poll(void* data, int num) {
  if (num <= 0)
    return 0;

  if (data == nullptr) {
    uint32_t max = static_cast<uint32_t>(RingBuffer::avariable());

    if (static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    RingBuffer::mTail += static_cast<uint32_t>(num);
    return num;
  }

  uint8_t* ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is empty */
  if (RingBuffer::isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::avariable();
  if (INDT() + cnt1 >= static_cast<int>(RingBuffer::mCount))
    cnt1 = static_cast<int>(RingBuffer::mCount) - INDT();

  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  Pointers::copy(data, ptr, cnt1);
  RingBuffer::mTail += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDT();
  data = static_cast<uint8_t*>(data) + cnt1;
  Pointers::copy(data, ptr, cnt2);
  RingBuffer::mTail += static_cast<uint32_t>(cnt2);

  return cnt1 + cnt2;
}

//-------------------------------------------------------------------------------
int RingBuffer::skip(int value) {
  int max = RingBuffer::avariable();

  if (value > max)
    value = max;

  RingBuffer::mTail += static_cast<uint32_t>(value);
  return value;
}

/* ******************************************************************************
 * Public Method
 */

/* ******************************************************************************
 * Protected Method <Static>
 */

/* ******************************************************************************
 * Protected Method <Override>
 */

/* ******************************************************************************
 * Protected Method
 */

/* ******************************************************************************
 * Private Method
 */

/**
 * @brief
 *
 */
void RingBuffer::init(void) {
  uint32_t bufferSize = static_cast<uint32_t>(RingBuffer::length());
  RingBuffer::mHead abstract;
  RingBuffer::mTail abstract;

  for (int i = 0; i < 32; i++) {
    bufferSize &= ~(1 << i);
    if (!bufferSize) {
      bufferSize = (1 << i);
      break;
    }
  }

  RingBuffer::mCount = bufferSize;
}

/* ******************************************************************************
 * End of file
 */
