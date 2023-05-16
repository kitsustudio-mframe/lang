/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_41FE73A3_C4A1_430A_BDAC_308916D3FDDC
#define LANG_41FE73A3_C4A1_430A_BDAC_308916D3FDDC

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Object.h"
#include "./OutputBuffer.h"
#include "./InputBuffer.h"
#include "./Kernel.h"
#include "./Thread.h"

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  struct SystemConfig;
}


/* ****************************************************************************************
 * Class/struct/Struct/Enum
 */
struct lang::SystemConfig{
  lang::OutputBuffer* out;
  lang::InputBuffer* in;
  lang::Kernel* kernel;
  lang::Thread* userThread;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_41FE73A3_C4A1_430A_BDAC_308916D3FDDC */
