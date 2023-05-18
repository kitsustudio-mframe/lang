/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_191BC7E7_9B06_42F9_A2A6_564525AECDC8
#define LANG_191BC7E7_9B06_42F9_A2A6_564525AECDC8

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./WriteBuffer.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class StreamSkipper;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::StreamSkipper :public lang::Object ,
public lang::WriteBuffer{

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
    int mPosition;
    int mCapacity;

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
     * @brief Construct a new Stream Skipper object
     * 
     */
    StreamSkipper(void);

    /**
     * @brief Destroy the Stream Skipper object
     * 
     */
    virtual ~StreamSkipper(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:
    /**
     *
     */
    inline int operator=(int v){
      this->position(v);
      return this->position();
    }
    
    /**
     *
     */
    inline void operator+=(int shift){
      this->position(this->position() + shift);
    }
    
    /**
     *
     */
    inline void operator-=(int shift){
      this->position(this->position() - shift);
    }
    
    /**
     *
     */
    inline unsigned int operator++(void){
      this->position(this->position() + 1);
      return static_cast<unsigned int>(this->position());
    }
    
    /**
     *
     */
    inline unsigned int operator--(void){
      this->position(this->position() - 1);
      return static_cast<unsigned int>(this->position());
    }

        /**
     *
     */
    inline unsigned int operator++(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() + 1);
      return result;
    }
    
    /**
     *
     */
    inline unsigned int operator--(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() - 1);
      return result;
    }  
  
  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::InputBuffer
   */
  public:
    /**
     * @brief 取得InputBuffer是否已滿
     * 
     * @return true 已滿
     * @return false 未滿，仍有空間
     */
    inline virtual bool isFull(void) const override{
      return (this->mPosition >= this->mCapacity);
    }

    /**
     * @brief 取得InputBuffer內資料數量
     * 
     * @return int InputBuffer內資料數量
     */
    inline virtual int remaining(void) const override{
      return (this->mCapacity - this->mPosition);
    }

    /**
     * @brief 將data輸入至InputBuffer
     * 
     * @param data 資料來源
     * @return true 成功將data輸入至InputBuffer
     * @return false InputBuffer已滿
     */
    virtual bool putByte(const char data) override;

    /**
     * @brief 將readBuffer內資料輸入至InputBuffer
     * 
     * @param byteBuffer 資料來源
     * @return int 移動資料數量(byte)
     */
    virtual int put(lang::ReadBuffer& readBuffer) override;

    /**
     * @brief 將buffer內資料輸入至InputBuffer
     * 
     * @param buffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(lang::ReadBuffer& readBuffer, int length) override;      
    
    /**
     * @brief 將buffer內資料輸入至InputBuffer
     * 
     * @param buffer 資料來源
     * @param bufferSize 目標最大尺寸
     * @return int 移動資料數量(byte)
     */
    virtual int put(const void* buffer, int length) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @param v 
     */
    inline void position(int v){
      if(v < 0)
        v abstract;

      if(v > this->mCapacity)
        v = this->mCapacity;

      this->mPosition = v;
      return;
    }
    
    /**
     * @brief 
     * 
     * @return int 
     */
    inline int position(void){
      return this->mPosition;
    }

    /**
     * @brief 
     * 
     * @param v 
     */
    inline void capacity(int v){
      if(v < 0)
        v abstract;

      if(this->mPosition > v)
        this->mPosition = v;

      this->mCapacity = v;
      return;
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline int capacity(void){
      return this->mCapacity;
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

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* LANG_191BC7E7_9B06_42F9_A2A6_564525AECDC8 */
