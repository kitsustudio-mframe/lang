/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_CFACAB80_FA08_4FEB_892B_1F875AB7C64F
#define MFRAME_CFACAB80_FA08_4FEB_892B_1F875AB7C64F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../../lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang::managerment {
  struct HardwareInfo;

}  // namespace mframe::lang::managerment

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::lang::managerment::HardwareInfo : public virtual mframe::lang::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 取得硬體核心頻率
   * 
   * @return int Hertz
   */
  virtual int systemClock(void) abstract;

  /**
   * @brief 取得供應商名稱
   * 
   * @return const char* 供應商名稱
   */
  virtual const char* manufacturer(void) abstract;

  /**
   * @brief 取得硬體型號
   * 
   * @return const char* 硬體型號 
   */
  virtual const char* model(void) abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_CFACAB80_FA08_4FEB_892B_1F875AB7C64F */
