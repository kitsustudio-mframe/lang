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
#include "./ReadBuffer.h"
#include "./InputStream.h"


/* ****************************************************************************************
 * Namespace
 */
namespace lang{
  struct InputStreamBuffer;
}


/* ****************************************************************************************
 * Class/struct/Struct/Enum
 */
struct lang::InputStreamBuffer : public lang::InputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Output Buffer object
   * 
   * @return lang::ReadBuffer& 
   */
  virtual lang::ReadBuffer& getReadBuffer(void) = 0;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* LANG_D4F7F817_17A8_4EC2_8B3B_F96F763689AC */
