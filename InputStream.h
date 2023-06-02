/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_1A551970_54AE_4519_9794_2271AD01B24B
#define LANG_1A551970_54AE_4519_9794_2271AD01B24B

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./CompletionHandler.h"
#include "./Future.h"
#include "./Interface.h"
#include "./Object.h"
#include "./WriteBuffer.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class InputStream;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::InputStream : public lang::Object,
                          public lang::Runnable {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
 protected:
  lang::WriteBuffer* mWriteBuffer;
  lang::CompletionHandler<int, void*>* mCompletionHandler;
  void* mAttachment;
  int mResult;
  bool mHandling;

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
 protected:
  /**
   * @brief Construct a new Input Stream object
   *
   */
  InputStream(void);

 public:
  /**
   * @brief Destroy the Input Stream object
   *
   */
  virtual ~InputStream(void) override;

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
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @return true
   * @return false
   */
  virtual bool abortRead(void);

  /**
   * @brief
   *
   * @return true is busy.
   * @return false isn't busy.
   */
  virtual bool readBusy(void);

  /**
   * @brief
   *
   * @param readBuffer
   * @return int
   */
  virtual bool read(lang::WriteBuffer& writeBuffer, int timeout);

  /**
   * @brief nonblocking
   *
   * @param writeBuffer
   * @param attachment
   * @param handler
   * @return true successful.
   * @return false fail.
   */
  virtual bool read(lang::WriteBuffer& writeBuffer,
                    void* attachment,
                    lang::CompletionHandler<int, void*>* handler);

  /**
   * @brief
   *
   * @param writeBuffer
   * @param future
   * @return true
   * @return false
   */
  virtual bool read(lang::WriteBuffer& writeBuffer, lang::Future& future);

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */
 protected:
  /**
   * @brief
   *
   */
  virtual void execute(void);

  /**
   * @brief 讀取事件
   *
   * 當成功建立讀取時呼叫此
   */
  virtual void onReadEvent(void);

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

/* ******************************************************************************
 * End of file
 */

#endif /* LANG_1A551970_54AE_4519_9794_2271AD01B24B */
