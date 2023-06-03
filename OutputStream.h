/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_70D3F441_6A18_4924_BBD9_227663933296
#define LANG_70D3F441_6A18_4924_BBD9_227663933296

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./CompletionHandler.h"
#include "./Future.h"
#include "./ReadBuffer.h"
#include "./Runnable.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class OutputStream;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::OutputStream : public lang::Object,
                           public lang::Runnable {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
 protected:
  lang::ReadBuffer* mReadBuffer;
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
   * @brief Construct a new Output Stream object
   *
   */
  OutputStream(void);

 public:
  /**
   * @brief Destroy the Output Stream object
   *
   */
  virtual ~OutputStream(void) override;

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
   * @brief 取消當前的輸出串流寫入
   *
   * @return
   *  - true : 為成功終止當前的輸出至OutputStream
   *  - false : 終止失敗，有可能當前輸出串流並未忙碌
   */
  bool abortWrite(void);

  /**
   * @brief 取得輸出串流是否為寫入忙碌
   *
   * @return
   *  - true: 輸出串流忙碌中，無法接受新的寫入
   *  - false: 輸出串流閒置中
   */
  bool writeBusy(void);

  /**
   * @brief IO 寫入模式
   *
   * @param readBuffer
   * @param timeout
   * @return
   *  - true: 建立寫入成功
   *  - false: 建立寫入失敗，串流可能正在忙碌中
   */
  bool write(lang::ReadBuffer& readBuffer, int timeout);

  /**
   * @brief NIO 寫入模式
   *
   * 從給定的緩衝區向該通道寫入一個字節序列。
   * 該方法啟動異步寫入操作，以從給定的緩衝區向該通道寫入字節序列。
   *
   * 該方法的行為方式與 write(ReadBuffer,void*,CompletionHandler)方法完全相同，不同的是，
   * 該方法不是指定完成處理程序，
   * 而是返回一個Future待處理結果的Future。Future的get方法返回寫入的字節數。
   *
   *
   * @param readBuffer - 要檢索字節的緩衝區
   * @param future - 代表操作結果的未來
   *
   * @return
   *  - true : 建立寫入成功
   *  - false : 建立寫入失敗，串流可能正在忙碌中
   */
  bool write(lang::ReadBuffer& readBuffer, lang::Future& future);

  /* ****************************************************************************
   * Public Method <Virtual>
   */
 public:
  /**
   * @brief AIO 寫入模式
   *
   * @param readBuffer
   * @param attachment
   * @param handler
   * @return
   *  - true : 建立寫入成功
   *  - false : 建立寫入失敗，串流可能正在忙碌中
   */
  virtual bool write(lang::ReadBuffer& readBuffer,
                     void* attachment,
                     lang::CompletionHandler<int, void*>* handler);
                     
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
   * @brief
   *
   */
  virtual void onWriteEvent(void);
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

#endif /* LANG_70D3F441_6A18_4924_BBD9_227663933296 */
