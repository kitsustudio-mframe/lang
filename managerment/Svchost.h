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
#include "./../../lang/managerment/Allocator.h"
#include "./../../lang/managerment/Kernel.h"
#include "./../../lang/managerment/SystemConfig.h"
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
  mframe::io::OutputStream& mOutputStream;
  mframe::io::InputStream& mInputStream;
  mframe::io::PrintBuffer mPrintBuffer;
  mframe::io::RingBuffer mRingBuffer;

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  mframe::util::ArrayQueue<mframe::lang::Runnable> mArrayQueue;
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
   * @param systemConfig
   */
  Svchost(mframe::lang::managerment::SystemConfig& systemConfig);

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
  bool start(mframe::lang::Runnable& task, int stackSize);

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
   * @brief
   *
   * @return true
   * @return false
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
