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
#include "./RunnableEntity.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::RunnableEntity;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Runnable Entity object
 * 
 */
RunnableEntity:: RunnableEntity(void) : RunnableEntity(nullptr){
  return;
}

/**
 * @brief Construct a new Runnable Entity object
 * 
 * @param runnable 
 */
RunnableEntity::RunnableEntity(lang::Runnable& runnable) :
mRunnableEvent(nullptr){
  this->mRunnable = &runnable;
  return;
}

/**
 * @brief Construct a new Runnable Entity object
 * 
 * @param function 
 */
RunnableEntity::RunnableEntity(void (*function)(void)) :
mRunnableEvent(function){
  this->mRunnable = &this->mRunnableEvent;
  return;
}

/**
 * @brief 複製建構子
 * 
 * @param source 
 */
RunnableEntity::RunnableEntity(const RunnableEntity& source) :
mRunnableEvent(source.mRunnableEvent){
  this->mRunnable = source.mRunnable;
  
  if(source.mRunnable == &source.mRunnableEvent){
    RunnableEntity::mRunnable = &(RunnableEntity::mRunnableEvent);
  }
  
  return;
}

/**
 * @brief Destroy the Runnable Entity object
 * 
 */
RunnableEntity::~RunnableEntity(void){
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - lang::Runnable
 */
/**
 * @brief 
 * 
 */
void RunnableEntity::run(void){
  this->mRunnable->run();
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

/* ****************************************************************************************
 * End of file
 */
