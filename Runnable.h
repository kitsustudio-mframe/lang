/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_A54036B2_950E_4F06_9CD4_6FD23597926A
#define LANG_A54036B2_950E_4F06_9CD4_6FD23597926A

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  struct Runnable;
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
struct lang::Runnable : public virtual lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   */
  virtual void run(void) = 0;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_A54036B2_950E_4F06_9CD4_6FD23597926A */
