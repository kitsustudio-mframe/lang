/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CORE_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B
#define CORE_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B
#ifndef MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB
#define MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Object.h"
#include "./../lang/Runnable.h"
#include "./../lang/RunnableEvent.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class RunnableEntity;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::lang::RunnableEntity final : public mframe::lang::Object,
                                           public mframe::lang::Runnable {
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
 private:
  mframe::lang::RunnableEvent mRunnableEvent;
  mframe::lang::Runnable* mRunnable;

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
   * @brief Construct a new Runnable Entity object
   *
   */
  RunnableEntity(void);

  /**
   * @brief Construct a new Runnable Entity object
   *
   * @param runnable
   */
  RunnableEntity(mframe::lang::Runnable& runnable);

  /**
   * @brief Construct a new Runnable Entity object
   *
   * @param function
   */
  RunnableEntity(void (*function)(void));

  /**
   * @brief 複製建構子
   *
   * @param source
   */
  RunnableEntity(const RunnableEntity& source);

  /**
   * @brief Destroy the Runnable Entity object
   *
   */
  virtual ~RunnableEntity(void) override;

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
  /**
   * @brief
   *
   */
  virtual void run(void) override;

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

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_03ECECB0_EFC6_464A_A4FB_833247AF27AB */

#endif /* CORE_B21E95F1_A4B3_4BBD_96AA_E98F66338E8B */
