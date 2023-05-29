/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_21696933_3B6B_4512_922C_4B04E4B28F72
#define LANG_21696933_3B6B_4512_922C_4B04E4B28F72

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./Object.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class HashGen;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::HashGen :public lang::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private: 
    /**
     *
     */
    HashGen(void);
  
  public:
    /**
     *
     */
    virtual ~HashGen(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    /**
     *
     */
    static int getHashcode(const void* src, int len);
    
   /**
     *
     */
    static int getHashcode(const char* src);

  /* **************************************************************************************
   * Public Method <Override>
   */

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

#endif /* LANG_21696933_3B6B_4512_922C_4B04E4B28F72 */
