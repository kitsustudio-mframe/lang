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

//-----------------------------------------------------------------------------------------
#include "./RingBufferOutputStream.h"
#include "./System.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::RingBufferOutputStream;


/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param buffer 
 * @param bufferSize 
 */
RingBufferOutputStream::RingBufferOutputStream(void* buffer, uint32_t bufferSize) :
RingBuffer(buffer, bufferSize){
  this->mReadBuffer = nullptr;
  this->mResult abstract;
  this->mHandling = false;
  return;
}
  
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param memory 
 */
RingBufferOutputStream::RingBufferOutputStream(const lang::Memory& memory) :
RingBuffer(memory){
  this->mReadBuffer = nullptr;
  this->mResult abstract;
  this->mHandling = false;
  return;
}
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param length 
 */
RingBufferOutputStream::RingBufferOutputStream(uint32_t length) :
RingBuffer(length){
  this->mReadBuffer = nullptr;
  this->mResult abstract;
  this->mHandling = false;
  return;
}
/**
 * @brief Destroy the RingBufferInputStream object
 * 
 */
RingBufferOutputStream::~RingBufferOutputStream(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - lang::RingBuffer
 */

/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool RingBufferOutputStream::getByte(char& result){
  bool r = RingBuffer::getByte(result);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return r;   
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int RingBufferOutputStream::get(lang::WriteBuffer& inputBuffer){
  int result = RingBuffer::get(inputBuffer);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result;   
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int RingBufferOutputStream::get(lang::WriteBuffer& inputBuffer, int length){
  int result = RingBuffer::get(inputBuffer, length);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result;   
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int RingBufferOutputStream::get(void* buffer, int bufferSize){
  int result = RingBuffer::get(buffer, bufferSize);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result; 
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int RingBufferOutputStream::skip(int value){
  int result = RingBuffer::skip(value);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result; 
}

/* **************************************************************************************
 * Public Method <Override> - lang::OutputStreamBuffer
 */

/**
 * @brief Get the Input Buffer object
 * 
 * @return lang::WriteBuffer& 
 */
lang::WriteBuffer& RingBufferOutputStream::getWriteBuffer(void){
  return *this;
}

/* ****************************************************************************************
 * Public Method <Override> - lang::OutputStream
 */

/**
 * @brief 
 * 
 * @return true successful.
 * @return false fail.
 */
bool RingBufferOutputStream::abortWrite(void){
  if(!this->writeBusy())
    return false;
  
  this->executeCompletionHandler();
  return true;
}

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool RingBufferOutputStream::writeBusy(void){
  return (this->mReadBuffer != nullptr);
}

/**
 * @brief 
 * 
 * @param outputBuffer
 * @param future 
 * @return true 
 * @return false 
 */
bool RingBufferOutputStream::write(lang::ReadBuffer& outputBuffer, int timeout){
  Future future = Future();
  if(this->write(outputBuffer, future) == false)
    return false;
  
  future.waitDone(timeout);
  if(future.isDone() == false)
    this->abortWrite();
  
  future.waitDone();
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool RingBufferOutputStream::write(ReadBuffer& outputBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->writeBusy())
    return false;
  
  this->mReadBuffer = &outputBuffer;
  this->mHandler = handler;
  this->mAttachment = attachment;
  this->mResult = this->put(*this->mReadBuffer);

  if(this->mReadBuffer->avariable() <= 0){
    this->executeCompletionHandler();

  }else if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
    
  }

  return true;
}
                               
/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param future 
 * @return true 
 * @return false 
 */
bool RingBufferOutputStream::write(ReadBuffer& outputBuffer, Future& future){
  if(!future.isIdle())
    return false;
  
  future.setWait();
  bool result = this->write(outputBuffer, nullptr, &future);
  if(result == false)
    future.clear();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - func::Runnable
 */

/**
 * @brief 
 * 
 */
void RingBufferOutputStream::run(void){
  if(this->mHandling == false)
    return;
  
  this->mHandling = false;
  
  //RingBuffer has data
  if(this->remaining() == 0)
    return;
    
  if(this->mReadBuffer != nullptr){
    this->mResult += this->put(*this->mReadBuffer);
    if(this->mReadBuffer->avariable() <= 0)
      this->executeCompletionHandler();     
  }
  
  return;
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
void RingBufferOutputStream::executeCompletionHandler(void){
  if(!this->writeBusy())
    return;
  
  CompletionHandler<int, void*>* handler = this->mHandler;
  void* attachment = this->mAttachment;
  
  int result = this->mResult;
  this->mResult abstract;
  this->mReadBuffer = nullptr;
  
  if(handler)
    handler->completed(result, attachment);

  return;
}

/* ****************************************************************************************
 * End of file
 */
