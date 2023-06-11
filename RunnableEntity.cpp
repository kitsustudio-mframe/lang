/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */
#include "./RunnableEntity.h"

//-------------------------------------------------------------------------------
#include "mframe.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using mframe::lang::RunnableEntity;

/* ******************************************************************************
 * Variable <Static>
 */

/* ******************************************************************************
 * Construct Method
 */

//-------------------------------------------------------------------------------
RunnableEntity::RunnableEntity(void) : RunnableEntity(nullptr) {
  return;
}

//-------------------------------------------------------------------------------
RunnableEntity::RunnableEntity(mframe::lang::Runnable& runnable) : mRunnableEvent(nullptr) {
  this->mRunnable = &runnable;
  return;
}

//-------------------------------------------------------------------------------
RunnableEntity::RunnableEntity(void (*function)(void)) : mRunnableEvent(function) {
  this->mRunnable = &this->mRunnableEvent;
  return;
}

//-------------------------------------------------------------------------------
RunnableEntity::RunnableEntity(const RunnableEntity& source) : mRunnableEvent(source.mRunnableEvent) {
  this->mRunnable = source.mRunnable;

  if (source.mRunnable == &source.mRunnableEvent) {
    RunnableEntity::mRunnable = &(RunnableEntity::mRunnableEvent);
  }

  return;
}

//-------------------------------------------------------------------------------
RunnableEntity::~RunnableEntity(void) {
  return;
}

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

/* ******************************************************************************
 * Public Method <Override> - mframe::lang::Runnable
 */

//-------------------------------------------------------------------------------
void RunnableEntity::run(void) {
  this->mRunnable->run();
  return;
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

/* ******************************************************************************
 * End of file
 */
