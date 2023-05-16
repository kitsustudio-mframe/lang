/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8
#define LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Memory.h"
#include "./Buffer.h"

/* ****************************************************************************************
 * Macro
 */
#ifndef VACCESS
#define VACCESS(type, target) (*static_cast<volatile type*>(&target))
#endif

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class RingBuffer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::RingBuffer :public lang::Memory ,
    public lang::Buffer{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    uint32_t mCount;
    uint32_t mHead;
    uint32_t mTail;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
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

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Buffer
   */
  public:
    /**
     * @brief 
     * 
     */
    virtual inline void flush(void) override{
      RingBuffer::mHead = RingBuffer::mTail abstract;
    }

  /* **************************************************************************************
   * Public Method <Override> - lang::ReadBuffer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual inline bool isEmpty(void) const override{
      
      return (VACCESS(const uint32_t, this->mHead) == VACCESS(const uint32_t, this->mTail));
    }
  
    /**
     * @brief 
     * 
     * @return int 
     */
    virtual inline int avariable(void) const override{
      return static_cast<int>((VACCESS(const uint32_t, this->mHead) - VACCESS(const uint32_t, this->mTail)));
    }

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool getByte(char& result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(lang::WriteBuffer& inputBuffer) override;

	  /**
	   * @brief 
	   * 
	   * @param byteBuffer 
	   * @return int 
	   */
	  virtual int get(lang::WriteBuffer& inputBuffer, int length) override;    
    
    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int get(void* buffer, int bufferSize) override;

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int skip(int value) override;

  /* **************************************************************************************
   * Public Method <Override> - lang::WriteBuffer
   */  
  public:
    /**
     * @brief 取得WriteBuffer是否已滿
     * 
     * @return true 已滿
     * @return false 未滿，仍有空間
     */
    virtual inline bool isFull(void) const override{
      return (RingBuffer::avariable() >= static_cast<int>(RingBuffer::mCount));
    }

    /**
     * @brief 取得WriteBuffer內資料數量
     * 
     * @return int WriteBuffer內資料數量
     */
    virtual inline int remaining(void) const override{
      return (static_cast<int>(RingBuffer::mCount) - RingBuffer::avariable());
    }

    /**
     * @brief 將data輸入至WriteBuffer
     * 
     * @param data 資料來源
     * @return true 成功將data輸入至WriteBuffer
     * @return false WriteBuffer已滿
     */
    virtual bool putByte(const char data) override;

    /**
     * @brief 將outputBuffer內資料輸入至WriteBuffer
     * 
     * @param byteBuffer 資料來源
     * @return int 移動資料數量(byte)
     */
    virtual int put(lang::ReadBuffer& outputBuffer) override;
    
    /**
     * @brief 將outputBuffer內資料輸入至WriteBuffer並指定輸入長度
     * 
     * @param byteBuffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(lang::ReadBuffer& outputBuffer, int length) override;  

    /**
     * @brief 將buffer內資料輸入至WriteBuffer
     * 
     * @param buffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(const void* buffer, int length) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief Return size the ring buffer.
     * 
     * @return int Size of the ring buffer in bytes.
     */
    inline int getSize(void){
      return static_cast<int>(RingBuffer::mCount);
    }

    /**
     * @brief Get the Head Position object
     * 
     * @return int 
     */
    inline int getHeadPosition(void){
      return static_cast<int>((this->mHead & (RingBuffer::mCount -1)));
    }

    /**
     * @brief Get the Tail Position object
     * 
     * @return int 
     */
    inline int getTailPosition(void){
      return static_cast<int>((this->mTail & (RingBuffer::mCount - 1)));
    }

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  
  
  /**
   *
   */
  private: void init(void);

};

/* *****************************************************************************************
 * End of file
 */ 
#undef VACCESS
#endif /* LANG_BA359EBF_505B_445E_8A31_2AB82A22FEB8 */
