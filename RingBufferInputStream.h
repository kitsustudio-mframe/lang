/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_A4DC217C_C29F_4947_B36B_0D55F49EB274
#define LANG_A4DC217C_C29F_4947_B36B_0D55F49EB274

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./RingBuffer.h"
#include "./OutputStream.h"
#include "./InputStream.h"
#include "./InputStreamBuffer.h"

//-----------------------------------------------------------------------------------------


/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class RingBufferInputStream;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::RingBufferInputStream :public lang::RingBuffer ,
public lang::InputStreamBuffer,
public lang::Runnable{

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
    lang::WriteBuffer* mWriteBuffer;
    void* mAttachment;
    lang::CompletionHandler<int, void*>* mHandler;
    int mResult;
    int mSkip;
    bool mHandling;
  
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
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param buffer 
     * @param bufferSize 
     */
    RingBufferInputStream(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param memory 
     */
    RingBufferInputStream(const lang::Memory& memory);  

    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param length 
     */
    RingBufferInputStream(uint32_t length);

    /**
     * @brief Destroy the RingBufferInputStream object
     * 
     */
    virtual ~RingBufferInputStream(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::RingBuffer 
   */
   public:
    using RingBuffer::avariable;
    using RingBuffer::skip;
   
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
   * Public Method <Override> - lang::InputStreamBuffer
   */
  public:
    /**
     * @brief Get the Output Buffer object
     * 
     * @return lang::ReadBuffer& 
     */
    virtual lang::ReadBuffer& getReadBuffer(void) override;

  /* **************************************************************************************
   * Public Method <Override> - lang::InputStream 
   */
  public:
  
    /**
     * @brief 
     * 
     * @return true abrot successful.
     * @return false abrot fail.
     */
    virtual bool abortRead(void) override;  
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool readBusy(void) override;
    
    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @return int 
     */
    virtual bool read(lang::WriteBuffer& inputBuffer, int timeout) override;        
    
    /**
     * @brief nonblocking
     * 
     * @param inputBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool read(lang::WriteBuffer& inputBuffer, 
                      void* attachment,
                      lang::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool read(lang::WriteBuffer& inputBuffer, lang::Future& future) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param attachment 
     * @param handler 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, 
                      void* attachment,
                      lang::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, lang::Future& future) override;
    

  /* **************************************************************************************
   * Public Method <Override> - func::Runnable
   */
  public:
    /**
     * @brief 
     * 
     */
    virtual void run(void) override;
                      
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
  private:
  
    /**
     * @brief 
     *
     */
    void executeCompletionHandler(void);
  
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* LANG_A4DC217C_C29F_4947_B36B_0D55F49EB274 */
