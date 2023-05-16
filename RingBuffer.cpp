/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./RingBuffer.h"

/* ****************************************************************************************
 * Macro
 */  
#define INDH()    (static_cast<int>(RingBuffer::mHead & (RingBuffer::mCount - 1)))
#define INDT()    (static_cast<int>(RingBuffer::mTail & (RingBuffer::mCount - 1)))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* ****************************************************************************************
 * Using
 */  
using lang::RingBuffer;
using lang::Memory;
using lang::WriteBuffer;
using lang::ReadBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Ring Buffer:: Ring Buffer object
 * 
 * @param buffer 
 * @param bufferSize 
 */
RingBuffer::RingBuffer(void* buffer, uint32_t bufferSize) : Memory(buffer, bufferSize){
  RingBuffer::init();
  return;
}

/**
 * @brief Construct a new Ring Buffer:: Ring Buffer object
 * 
 * @param memory 
 */
RingBuffer::RingBuffer(const Memory& memory) : Memory(memory){
  RingBuffer::init();
  return;
}

/**
 * @brief Construct a new Ring Buffer object
 * 
 * @param length 
 */
RingBuffer::RingBuffer(uint32_t length) : Memory(length){
  RingBuffer::init();
  return;
}

/**
 * @brief Destroy the Ring Buffer object
 * 
 */
RingBuffer::~RingBuffer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - lang::ReadBuffer
 */

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBuffer::putByte(const char result){
  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());

  /* We cannot insert when queue is full */
  if (RingBuffer::isFull())
    return false;

  ptr += INDH();
  *(static_cast<uint8_t*>(ptr)) = (static_cast<const uint8_t>(result));
  RingBuffer::mHead++;

  return true;
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBuffer::put(ReadBuffer& outputBuffer){
  return RingBuffer::put(outputBuffer, outputBuffer.avariable());
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param length 
 * @return int 
 */
int RingBuffer::put(ReadBuffer& outputBuffer, int length){
  if(length <= 0)
    return 0;  
  
  int num = outputBuffer.avariable();
  if(num > length)
    num = length;

  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());
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
  outputBuffer.get(ptr, cnt1);
  RingBuffer::mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDH();
  outputBuffer.get(ptr, cnt2);
  RingBuffer::mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBuffer::put(const void *data, int num){
  if(num <= 0)
    return 0;
  
  if(data == nullptr){
    uint32_t max = static_cast<uint32_t>(RingBuffer::remaining());

    if(static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    RingBuffer::mHead += static_cast<uint32_t>(num);
    return static_cast<int>(num);
  }

  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());
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
  memcpy(ptr, data, static_cast<uint32_t>(cnt1));
  RingBuffer::mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDH();
  data = static_cast<const uint8_t*>(data) + cnt1;
  memcpy(ptr, data, static_cast<uint32_t>(cnt2));
  RingBuffer::mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

/* ****************************************************************************************
 * Public Method <Override> - lang::WriteBuffer
 */

/**
 * @brief 將data輸入至WriteBuffer
 * 
 * @param data 資料來源
 * @return true 成功將data輸入至WriteBuffer
 * @return false WriteBuffer已滿
 */
bool RingBuffer::getByte(char& data){
  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());

  /* We cannot pop when queue is empty */
  if (RingBuffer::isEmpty())
    return false;

  ptr += INDT();
  data = static_cast<char>(*ptr);
  ++RingBuffer::mTail;

  return true;
}

/**
 * @brief 將outputBuffer內資料輸入至WriteBuffer
 * 
 * @param byteBuffer 資料來源
 * @return int 移動資料數量(byte)
 */
int RingBuffer::get(WriteBuffer& inputBuffer){
  return RingBuffer::get(inputBuffer, inputBuffer.remaining());
}

/**
 * @brief 將outputBuffer內資料輸入至WriteBuffer並指定輸入長度
 * 
 * @param byteBuffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int RingBuffer::get(lang::WriteBuffer& inputBuffer, int length){
  if(length <= 0)
    return 0;  
  
  int num = inputBuffer.remaining();
  if(num > length)
    num = length;
  
  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (RingBuffer::isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::avariable();
  if(INDT() + cnt1 >= static_cast<int>(RingBuffer::mCount))
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

/**
 * @brief 將buffer內資料輸入至WriteBuffer
 * 
 * @param buffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int RingBuffer::get(void* data, int num){
  if(num <= 0)
    return 0;
  
  if(data == nullptr){
    uint32_t max = static_cast<uint32_t>(RingBuffer::avariable());

    if(static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    RingBuffer::mTail += static_cast<uint32_t>(num);
    return num;
  }

  uint8_t *ptr = static_cast<uint8_t*>(RingBuffer::pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is empty */
  if (RingBuffer::isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = RingBuffer::avariable();
  if(INDT() + cnt1 >= static_cast<int>(RingBuffer::mCount))
    cnt1 = static_cast<int>(RingBuffer::mCount) - INDT();
  
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  memcpy(data, ptr, static_cast<uint32_t>(cnt1));
  RingBuffer::mTail += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(RingBuffer::pointer()) + INDT();
  data = static_cast<uint8_t*>(data) + cnt1;
  memcpy(data, ptr, static_cast<uint32_t>(cnt2));
  RingBuffer::mTail += static_cast<uint32_t>(cnt2);

  return cnt1 + cnt2;
}

/**
 * @brief 將data內資料輸入至WriteBuffer
 * 
 * @param data 資料來源
 * @return int 移動資料數量(byte)
 */
int RingBuffer::skip(int value){
  int max = RingBuffer::avariable();
  
  if(value > max)
    value = max;

  RingBuffer::mTail += static_cast<uint32_t>(value);
  return value;
}

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/**
 * @brief 
 * 
 */
void RingBuffer::init(void){
  uint32_t bufferSize = static_cast<uint32_t>(RingBuffer::length());
  RingBuffer::mHead = 0;
  RingBuffer::mTail = 0;
  
  for(int i=0; i<32; i++){
    bufferSize &= ~(1<<i);
    if(!bufferSize){
      bufferSize = (1<<i);
      break;
    }
  }
  
  RingBuffer::mCount = bufferSize;
}
 
/* ****************************************************************************************
 * End of file
 */ 
