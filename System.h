/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_DB2618AE_F498_4792_900C_A4BD1DC2E35C
#define MFRAME_DB2618AE_F498_4792_900C_A4BD1DC2E35C

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../io/PrintBuffer.h"
#include "./../io/RingBuffer.h"
#include "./../lang/ErrorCode.h"
#include "./../lang/Object.h"
#include "./../lang/Runnable.h"
#include "./../lang/Thread.h"
#include "./../lang/managerment/Kernel.h"
#include "./../lang/managerment/Svchost.h"
#include "./../lang/managerment/SystemConfig.h"

/* ******************************************************************************
 * Macro
 */
#ifdef MFRAME_DEBUG
#define MFRAME_THROW(message, code) mframe::lang::System::throwError(message, __PRETTY_FUNCTION__, code)
#else
#define MFRAME_THROW(message, code) mframe::lang::System::throwError("", "", code)
#endif
/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class System;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::System final : public mframe::lang::Object {
  friend Object;

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
 private:
  /**
   * @brief Construct a new System object
   *
   */
  System(void);

  /**
   * @brief Destroy the System object
   *
   */
  virtual ~System(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief 
   * 
   * @return mframe::io::PrintBuffer& 
   */
  static mframe::io::PrintBuffer& out(void);

  /**
   * @brief 
   * 
   * @return mframe::io::ReadBuffer& 
   */
  static mframe::io::ReadBuffer& in(void);

  /**
   * @brief 設備重新啟動
   *
   */
  static void reboot(void);

  /**
   * @brief 
   * 
   * @param systemConfig 
   */
  static void setup(mframe::lang::managerment::SystemConfig& systemConfig);

  /**
   * @brief 系統初始化核心
   *
   * @param kernel 核心方法，建議使用CMSIS-RTOS2
   */
  static void start(mframe::lang::Runnable& task, int stackSize);

  /**
   * @brief 錯誤拋出
   *
   * @param address
   * @param code
   */
  static void error(const void* address, ErrorCode code);

  /**
   * @brief 拋出錯誤
   * 
   * @param message 錯誤訊息
   * @param path 方法路徑
   * @param code 異常碼
   */
  static void throwError(const char* message, const char* path, ErrorCode code);

  /**
   * @brief Get the Core Clock object
   *
   * @return uint32_t
   */
  static int getCoreClock(void);

  /**
   * @brief
   *
   * @param times
   */
  static void lowerDelay(uint32_t times);

  /**
   * @brief
   * 函數 delay 等待內核滴答中指定的時間段。 對於1的值，系統等待直到下一個計時器滴答發生。
   * 實際時間延遲最多可能比指定時間少一個計時器滴答聲，即在下一個系統滴答聲發生之前立即調用
   * osDelay(1)，線程會立即重新安排。
   *
   *
   * @param milliseconds - time ticks value
   */
  static bool delay(int milliseconds);

  /**
   * @brief
   * 導致當前線程等待，直到另一個線程調用此對象的 notify()方法或 notifyAll()方法，或其他一些線程中斷當前線程，或一定量的實時時間。
   *
   * 這種方法類似於一個參數的 wait方法，但它允許對放棄之前等待通知的時間進行更精細的控制。 以納秒為單位的實時數量由下式給出：
   *
   * 1000000*超時+納米
   *
   * 在所有其他方面，該方法與一個參數的方法 wait(long)相同。 特別是， wait(0, 0)意味著同樣的事情 wait(0) 。
   *
   * 當前的線程必須擁有該對象的顯示器。 線程釋放此監視器的所有權，並等待直到發生以下兩種情況之一：
   *
   *
   * - 另一個線程通知等待該對象的監視器的線程通過調用 notify方法或 notifyAll方法來喚醒。
   * - timeout毫秒加 nanos納秒參數指定的超時時間已過。
   *
   *
   * 然後線程等待，直到它可以重新獲得監視器的所有權並恢復執行。
   *
   * 像在一個參數版本中，中斷和虛假喚醒是可能的，並且該方法應該始終在循環中使用：
   *
   *
   * ```CPP
   * while(<condition does not hold>){
   *   this->wait(timeout);
   *   ... // Perform action appropriate to condition
   * }
   * ```
   *
   * @param timeout - 以毫秒為單位等待的最長時間。
   *
   *
   * @return true
   *  - 執行含式成功並且已被notify
   *  - 已經到達timeout時間
   *
   * @return false
   *  - 如果超時值為負值或是值不在0-999999範圍內。
   *  - 無法在中斷時被呼叫。
   */
  static void wait(void);

  /**
   * @brief
   * 導致當前線程等待，直到另一個線程調用此對象的notify()方法或notifyAll()方法，或指定的時間已過。
   *
   *
   * 當前的線程必須擁有該對象的顯示器。
   *
   *
   * 此方法使當前線程（稱為T ）將其放置在該對象的等待集中，然後放棄對該對象的任何和所有同步聲明。
   * 線程T變得禁用線程調度目的，並且休眠，直到發生四件事情之一：
   *
   *
   *   - 一些其他線程調用該對象的notify方法，並且線程T恰好被任意選擇為被喚醒的線程。
   *   - 某些其他線程調用此對象的notifyAll方法。
   *   - 一些其他線程interrupts線程T。
   *
   *
   * 然後從該對象的等待集中刪除線程T ，並重新啟用線程調度。然後它以通常的方式與其他線程競爭在對像上進行同步的權限;
   * 一旦獲得了對象的控制，其對對象的所有同步聲明就恢復到現狀 - 也就是在調用wait方法之後的情況。
   * 線程T然後從調用wait方法返回。因此，從返回wait方法，對象和線程的同步狀態T正是因為它是當wait被調用的方法。
   *
   *
   * 線程也可以喚醒，而不會被通知，中斷或超時，即所謂的虛假喚醒 。雖然這在實踐中很少會發生，
   * 但應用程序必須通過測試應該使線程被喚醒的條件來防範，並且如果條件不滿足則繼續等待。
   * 換句話說，等待應該總是出現在循環中，就像這樣：
   *
   *
   * ```CPP
   * while(<condition does not hold>){
   *   this->wait();
   *   ... // Perform action appropriate to condition
   * }
   * ```
   *
   *
   * @return true:
   *  - 執行含式成功並且已被notify
   *
   *
   * @return false:
   *  - 無法在中斷時被呼叫。
   */
  static bool wait(int timeout);

  /**
   * @brief
   * 函數yield()將控制權傳遞給處於READY狀態且具有相同優先級的下一個線程。
   * 如果在READY狀態下沒有其他優先級相同的線程，則當前線程繼續執行，不會發生線程切換。
   *
   *
   * 函數yield()不會將線程設置為BLOCKED狀態。 因此，即使處於READY狀態的線程可用，也不會調度優先級較低的線程。
   *
   *
   * @return true
   *  - 成功發生線程切換
   *
   *
   * @return false
   *  - 無發生現程切換，可能無相同優先級需求
   *  - 無法在中斷時被呼叫。
   */
  static bool yield(void);

  /**
   * @brief 核心鎖定，在調用systemUnlock以前將不會進行執行緒切換
   *
   * @return int lock調用層數
   */
  static int lock(void);

  /**
   * @brief
   *
   * @return int lock調用剩餘層數，當值為0時核心解鎖，開始執行緒切換
   */
  static int unlock(void);

  /**
   * @brief 取得當前的執行緒
   *
   * @return null 執行緒取得失敗，可能正在執行中斷事件或是系統並未啟動
   * @return Thread 當前執行緒
   */
  static mframe::lang::Thread* currentThread(void);

  /**
   * @brief
   *
   * @param runnable
   * @return true
   * @return false
   */
  static void execute(mframe::lang::Runnable& runnable);

  /**
   * @brief 
   * 
   * @param runnable 
   * @param stackSize 
   * @return mframe::lang::Thread& 
   */
  static mframe::lang::Thread& allocThread(mframe::lang::Runnable& runnable, int stackSize);

  /**
   * @brief 
   * 
   * @param runnable 
   * @param stackMemory 
   * @return mframe::lang::Thread& 
   */
  static mframe::lang::Thread& allocThread(mframe::lang::Runnable& runnable, mframe::lang::Data& stackMemory);
  
  /**
   * @brief Get the Allocator object
   * 
   * @return mframe::lang::managerment::Allocator& 
   */
  static mframe::lang::managerment::Allocator* getAllocator(void);

  /* ****************************************************************************
   * Public Method <Inline Static>
   */

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

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

#endif /* MFRAME_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
