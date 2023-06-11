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
#include "./../../lang/Object.h"
#include "./../../lang/Runnable.h"
#include "./../../lang/Thread.h"
#include "./../../lang/managerment/Kernel.h"
#include "./../../util/ArrayQueue.h"
#include "./../../util/Future.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang::managerment {
  class Svchost;
}

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::lang::managerment::Svchost : public mframe::lang::Object,
                                           public mframe::lang::Runnable,
                                           public mframe::io::CompletionHandler<int, void*> {
  /* ****************************************************************************
   * Variable <Public>
   */
 public:
  mframe::lang::managerment::Kernel& mKernel;
  mframe::io::PrintBuffer mPrintBuffer;
  mframe::io::RingBuffer mRingBuffer;
  mframe::util::ArrayQueue<mframe::lang::Runnable> mArrayQueue;

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  mframe::lang::Thread* mThread;
  mframe::lang::Thread* mUserThread;
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
  Svchost(mframe::lang::managerment::Kernel& kernel, uint32_t outSize, uint32_t inSize, uint32_t taskQuanity);

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
   * Public Method <Override> - mframe::lang::Runnable
   */
 public:
  virtual void run(void) override;

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::CompletionHandler<int, void*>
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
  bool start(mframe::lang::Runnable& task, uint32_t stackSize);

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
  bool execute(mframe::lang::Runnable& task);

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
