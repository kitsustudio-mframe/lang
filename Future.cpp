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
  if(this->mThreadID != 0)
    this->notify(this->mThreadID);
  
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
  if(this->mThreadID != 0)
    this->notify(this->mThreadID);
  
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
  if(this->mThreadID)
    return false;
  
  if(this->mStatus == Status::WAIT){
    
    this->mThreadID = this->getThreadID();
    
    if(this->mThreadID != 0){
   
      while(this->mStatus == Status::WAIT)
        this->wait();
      
      this->mThreadID = 0;
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
  if(this->mThreadID)
    return false;  
  
  if(this->mStatus == Status::WAIT){
    this->mThreadID = this->getThreadID();
    
    if(this->mThreadID != 0){
      this->wait(timeout);
      
      this->mThreadID = 0;
      
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
  this->mThreadID = 0;
  this->mResult = 0;
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
