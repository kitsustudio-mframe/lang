/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_49192D91_B2E2_4241_93F9_E0873CE7DF81
#define LANG_49192D91_B2E2_4241_93F9_E0873CE7DF81

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Object.h"

/* ****************************************************************************************
 * Namespace
 */
namespace lang {
  class Hashcode;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::Hashcode : public lang::Object {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    int mHahscode;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  Hashcode(lang::Interface& interface);
  
  Hashcode(int hashcode);

  virtual ~Hashcode(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - lang::Object
   */
  public:
    virtual int hashcode(void) const override;

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_49192D91_B2E2_4241_93F9_E0873CE7DF81 */
