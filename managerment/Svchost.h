/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324
#define MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../../io/PrintBuffer.h"
#include "./../../io/RingBuffer.h"
#include "./../../lang/Data.h"
#include "./../../util/Future.h"
#include "./../../lang/Object.h"
#include "./../../lang/Runnable.h"
#include "./../../lang/Thread.h"
#include "./../../lang/managerment/Kernel.h"
#include "./../../util/ArrayQueue.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang::managerment {
  class Svchost;
}

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
class lang::managerment::Svchost : public lang::Object,
                                   public lang::Runnable,
                                   public io::CompletionHandler<int, void*> {
  /* ****************************************************************************
   * Variable <Public>
   */
 public:
  lang::managerment::Kernel& mKernel;
  io::PrintBuffer mPrintBuffer;
  io::RingBuffer mRingBuffer;
  util::ArrayQueue<lang::Runnable> mArrayQueue;

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  lang::Thread* mThread;
  lang::Thread* mUserThread;
  bool mStart;
  bool mAction;
  bool mStream;

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
   * @brief Construct a new Svchost object
   * 
   * @param kernel 
   * @param outSize 
   * @param inSize 
   * @param taskQuanity 
   */
  Svchost(lang::managerment::Kernel& kernel, uint32_t outSize, uint32_t inSize, uint32_t taskQuanity);

  /**
   *
   */
  virtual ~Svchost(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - lang::Runnable
   */
 public:
  virtual void run(void) override;

  /* ****************************************************************************
   * Public Method <Override> - lang::CompletionHandler<int, void*>
   */
 public:
  virtual void completed(int result, void* attachment) override;
  virtual void failed(void* exc, void* attachment) override;

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   *
   */
  bool start(lang::Runnable& task, uint32_t stackSize);

  /**
   * @brief 停止執行svchost
   *
   */
  void stop(void);

  /**
   * @brief 執行使用者事件
   *
   * @param task 使用者指定事件
   * @return true 只用者事件排定成功
   * @return false 使用者事件排定失敗
   */
  bool execute(lang::Runnable& task);

  /**
   *
   */
  bool action(void);

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
 private:
  bool checkOutputStream(void);
  bool checkInputStream(void);
};

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_90F75476_6982_4BDD_B9ED_0A250FE9C324 */
