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
#include "./Future.h"
#include "./System.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::Future;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
 
/**
 *
 */
Future::Future(void){
  this->clear();
  return;
}

/**
 * @brief Destroy the Future object
 * 
 */
Future::~Future(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 * @brief 
 * 
 * @param result 
 * @param attachment 
 */
void Future::completed(int result, void* attachment){
  if(this->mStatus != Status::WAIT)
    return;
  
  this->mResult = result;
  this->mStatus = Status::DONE_COMPLETED;
  if(this->mThread != nullptr)
    this->mThread->notify();
  
}
    
/**
 * @brief 
 * 
 * @param exc 
 * @param attachment 
 */
void Future::failed(void* exc, void* attachment){
  if(this->mStatus != Status::WAIT)
    return;
  
  this->mResult = -1;
  this->mStatus = Status::DONE_FAILED;
  if(this->mThread != nullptr)
    this->mThread->notify();
  
  return;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::setWait(void){
  if(this->mStatus == Status::IDLE){
    this->mStatus = Status::WAIT;
    return true;
    
  }else{
    return false;
    
  }
}

/**
 * @brief 
 * 
 */
void Future::waitDone(void){
  int result;
  this->get(result);
  return;
}

/**
 * @brief 
 * 
 * @param timeout 
 */
void Future::waitDone(int timeout){
  int result;
  this->get(result, timeout);
  return;
}

/**
 * @brief 
 * 
 * @return int 
 */
bool Future::get(int& result){
  if(this->mThread != nullptr)
    return false;
  
  if(this->mStatus == Status::WAIT){
    
    this->mThread = this->currentThread();
    
    if(this->mThread != nullptr){
   
      while(this->mStatus == Status::WAIT)
        this->wait();
      
      this->mThread = nullptr;
    }
  }
  result = this->mResult;
  return true;
}
  
/**
 * @brief 
 * 
 * @param timeout 
 * @return int 
 */
bool Future::get(int& result, int timeout){
  if(this->mThread != nullptr)
    return false;  
  
  if(this->mStatus == Status::WAIT){
    this->mThread = this->currentThread();
    
    if(this->mThread != nullptr){
      this->wait(timeout);
      
      this->mThread = nullptr;
      
      if(!this->isDone())
        return false;
      
    }
  }
  
  result = this->mResult;
  return true;
}
  
/**
 * @brief 
 * 
 */
void Future::clear(void){
  this->mStatus = Status::IDLE;
  this->mThread = nullptr;
  this->mResult abstract;
  return;
}
  
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isDone(void){
  return ((this->mStatus == Status::DONE_COMPLETED) || (this->mStatus == Status::DONE_FAILED));
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isCompleted(void){
  return (this->mStatus == Status::DONE_COMPLETED);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isFailed(void){
  return (this->mStatus == Status::DONE_FAILED);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isIdle(void){
   return (this->mStatus == Status::IDLE);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Future::isBusy(void){
  return (this->mStatus == Status::WAIT);
}

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

/* ****************************************************************************************
 * End of file
 */
