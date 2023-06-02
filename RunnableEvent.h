/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE
#define LANG_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Object.h"

//-------------------------------------------------------------------------------
#include "./Runnable.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class RunnableEvent;
}

/* ******************************************************************************
 * Class/struct/Struct
 */
class lang::RunnableEvent final : public lang::Object,
                                  public lang::Runnable {
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
   * Public Method <Override> - lang::Runnable
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

#endif /* LANG_C0CBB109_D7C7_4D02_9E97_1BE3A534DFAE */
