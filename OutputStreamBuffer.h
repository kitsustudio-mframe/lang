/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_33288B9C_6095_4B26_9F88_332BF138D71A
#define LANG_33288B9C_6095_4B26_9F88_332BF138D71A

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./InputBuffer.h"
#include "./OutputStream.h"

/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  interface OutputStreamBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface lang::OutputStreamBuffer extends lang::OutputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Input Buffer object
   * 
   * @return lang::InputBuffer& 
   */
  virtual lang::InputBuffer& getInputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_33288B9C_6095_4B26_9F88_332BF138D71A */
