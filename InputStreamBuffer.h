/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_D4F7F817_17A8_4EC2_8B3B_F96F763689AC
#define LANG_D4F7F817_17A8_4EC2_8B3B_F96F763689AC

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------
#include "./OutputBuffer.h"
#include "./InputStream.h"


/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  interface InputStreamBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface lang::InputStreamBuffer extends lang::InputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Output Buffer object
   * 
   * @return lang::OutputBuffer& 
   */
  virtual lang::OutputBuffer& getOutputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_D4F7F817_17A8_4EC2_8B3B_F96F763689AC */
