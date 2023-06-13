/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B
#define MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../../io/InputStream.h"
#include "./../../io/OutputStream.h"
#include "./../../lang/Interface.h"
#include "./../../lang/managerment/Allocator.h"
#include "./../../lang/managerment/HardwareInfo.h"
#include "./../../lang/managerment/Kernel.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mframe::lang::managerment {
  struct SystemConfig;
}  // namespace mframe::lang::managerment

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mframe::lang::managerment::SystemConfig {
  struct {
    int stackSize;
    int taskQuantity;
  } svchost;

  struct {
    mframe::io::InputStream* inputStream;    ///< Console輸入串流
    mframe::io::OutputStream* outputStream;  ///< Console輸出串流
    int sizeScanner;                         ///< Scanner buffer size
    int sizePrintBiffer;                     ///< PrintBuffer buffer size
  } console;

  struct {
    mframe::lang::managerment::Kernel* kernel;              ///< operator system
    mframe::lang::managerment::Allocator* allocator;        ///< memory pool
    mframe::lang::managerment::HardwareInfo* hardwareInfo;  ///< 硬體資訊
  } system;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MFRAME_93E34D78_B9CC_4603_803D_FA2874859F7B */
