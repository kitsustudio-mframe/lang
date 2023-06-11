/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263
#define MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/BiConsumer.h"
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  template <typename T, typename U>
  class BiConsumerEvent;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct
 */
template <class T, class U>
class mframe::lang::BiConsumerEvent : public mframe::lang::Object,
                                      public mframe::lang::BiConsumer<T, U> {
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
  void (*mEvent)(T, U);

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
   * @brief Construct a new Bi Consumer Event object
   *
   * @param event
   */
  BiConsumerEvent(void (*event)(T, U)) {
    this->mEvent = event;
    return;
  }

  /**
   * @brief Destroy the Bi Consumer Event object
   *
   */
  ~BiConsumerEvent() = default;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::BiConsumer<T, U>
   */
 public:
  /**
   * @brief
   *
   * @param t
   * @param u
   */
  virtual void accept(T t, U u) {
    this->mEvent(t, u);
  }

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

#endif /* MFRAME_FC6FA4E2_E818_4894_866D_38F6B2541263 */
