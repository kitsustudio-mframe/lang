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

/**
 * @brief 輸入串流 <Protected Class>
 *
 * 此類別無法被直接建構，須被繼承後並實現字節輸入至寫緩衝區
 *
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
   * @brief 阻塞式讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * 當寫緩衝區滿或是超時返回。
   *
   * @param writeBuffer 寫緩衝區。
   * @param timeout 超時，單位毫秒。
   * @return true 操作成功或讀取超時。
   * @return false 操作失敗，輸入串流正在忙碌。
   */
  virtual bool read(lang::WriteBuffer& writeBuffer, int timeout);

  /**
   * @brief 非同步讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * 當寫緩衝區滿時將調用handler進行非同步事件。
   *
   * tips. 此方法調用後不論狀態將立即返回。
   *
   * @param writeBuffer 寫緩衝區。
   * @param attachment 使用者參數，將再調用handler時傳入。
   * @param handler 事件處理器。
   * @return true 建立非同步讀取成功。
   * @return false 建立非同步讀取失敗，輸入串流正在忙碌。
   */
  virtual bool read(lang::WriteBuffer& writeBuffer,
                    void* attachment,
                    lang::CompletionHandler<int, void*>* handler);

  /**
   * @brief 非阻塞讀取。從輸入串流中讀取一些字節數，並將他們存到寫入緩衝區writeBuffer。
   *
   * @param writeBuffer 寫緩衝區。
   * @param future 未來的計算結果。
   * @return true 建立非阻塞讀取成功。
   * @return false 建立非阻塞讀取失敗，輸入串流正在忙碌。
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
   * @brief 處理事件，當讀取串流事件完成時呼叫此方法，完成非同步，非阻塞事件更新。
   *
   * 重寫此方法將改變處理方法。
   */
  virtual void execute(void);

  /**
   * @brief 當read被調用後且成功建立讀取事件，將呼叫此方法。
   *
   * 重寫此方法將改變處理方法。
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
