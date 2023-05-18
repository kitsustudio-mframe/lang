/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_773B1369_98E1_4A0E_BE62_135FA19FF875
#define LANG_773B1369_98E1_4A0E_BE62_135FA19FF875

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./RingBuffer.h"
#include "./OutputStream.h"
#include "./OutputStreamBuffer.h"
#include "./InputStream.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class RingBufferOutputStream;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::RingBufferOutputStream :public lang::RingBuffer ,
public lang::OutputStreamBuffer,
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
    lang::ReadBuffer* mReadBuffer;
    void* mAttachment;
    lang::CompletionHandler<int, void*>* mHandler;
    int mResult;
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
    RingBufferOutputStream(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param memory 
     */
    RingBufferOutputStream(const lang::Memory& memory);  

    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param length 
     */
    RingBufferOutputStream(uint32_t length);

    /**
     * @brief Destroy the Output Stream Buffer object
     * 
     */
    virtual ~RingBufferOutputStream(void) override;

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
    virtual int get(lang::WriteBuffer& writeBuffer) override;
  
	  /**
	   * @brief 
	   * 
	   * @param byteBuffer 
	   * @return int 
	   */
	  virtual int get(lang::WriteBuffer& writeBuffer, int length) override;

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
   * Public Method <Override> - lang::OutputStreamBuffer
   */
  public:
    /**
     * @brief Get the Input Buffer object
     * 
     * @return lang::WriteBuffer& 
     */
    virtual lang::WriteBuffer& getWriteBuffer(void) override;

  /* **************************************************************************************
   * Public Method <Override> - lang::OutputStream
   */
  public:

    /**
     * @brief 
     * 
     * @return true successful.
     * @return false fail.
     */
    virtual bool abortWrite(void) override;
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool writeBusy(void) override;

    /**
     * @brief 
     * 
     * @param readBuffer
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(lang::ReadBuffer& readBuffer, int timeout) override;
  
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(lang::ReadBuffer& byteBuffer, 
                       void* attachment,
                       lang::CompletionHandler<int, void*>* handler) override;
                       
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(lang::ReadBuffer& byteBuffer, lang::Future& future) override;

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

#endif /* LANG_773B1369_98E1_4A0E_BE62_135FA19FF875 */
