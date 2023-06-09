/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293
#define MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

#include "./../lang/Object.h"
#include "./../lang/Runnable.h"
#include "./../lang/ThreadPriority.h"
#include "./../lang/ThreadState.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Thread;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::Thread : public mframe::lang::Object {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */

  /* ****************************************************************************
   * Abstract method <Public>
   */

  /* ****************************************************************************
   * Abstract method <Protected>
   */

  /* ****************************************************************************
   * Construct Method
   */
 public:
  /**
   *
   */
  Thread(void);

  /**
   *
   */
  virtual ~Thread(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Abstract>
   */
 public:
  /**
   * @brief Get the Thread Name object
   *
   * @return const char*
   */
  virtual const char* getThreadName(void) const abstract;

  /**
   * @brief Get the Priority object
   *
   * @return mframe::lang::ThreadPriority
   */
  virtual mframe::lang::ThreadPriority getPriority(void) const abstract;

  /**
   * @brief Get the State object
   *
   * @return mframe::lang::ThreadState
   */
  virtual mframe::lang::ThreadState getState(void) const abstract;

  /**
   * @brief Get the Stack Size object
   *
   * @return uint32_t
   */
  virtual int getStackSize(void) const abstract;

  /**
   * @brief
   *
   * @param priority
   * @return true
   * @return false
   */
  virtual bool start(const char* name, mframe::lang::ThreadPriority priority) abstract;

  /**
   * @brief
   *
   */
  virtual void notify(void) abstract;

  /**
   * @brief Set the Priority object
   *
   * @param priority
   * @return true
   * @return false
   */
  virtual bool setPriority(mframe::lang::ThreadPriority priority) abstract;

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool start(const char* name);

  /**
   * @brief
   *
   * @return true
   * @return false
   */
  bool isActive(void);

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */

  /* ****************************************************************************
   * Private Method <Static>
   */

  /* ****************************************************************************
   * Private Method <Override>
   */

  /* ****************************************************************************
   * Private Method
   */
};

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
