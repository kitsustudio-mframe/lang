/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE
#define MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Object.h"
#include "./../lang/Runnable.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class RunnableEvent;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
class mframe::lang::RunnableEvent final : public mframe::lang::Object,
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
  void (*mFunction)(void);

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
   * @brief Construct a new Runnable Event object
   *
   */
  RunnableEvent(void);

  /**
   * @brief Construct a new Runnable Event object
   *
   * @param function
   */
  RunnableEvent(void (*function)(void));

  /**
   * @brief Destroy the Runnable Event object
   *
   */
  virtual ~RunnableEvent(void) override;

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

/* *******************************************************************************
 * End of file
 */

#endif /* MFRAME_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE */
