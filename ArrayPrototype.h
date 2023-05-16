/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EC5AD114_2891_41FA_8DE3_9D5FAD422A07
#define LANG_EC5AD114_2891_41FA_8DE3_9D5FAD422A07

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class ArrayPrototype;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::ArrayPrototype :public lang::Memory{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    int mElementSize;
    int mElementLength;

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
  public:

    /**
     * @brief Construct a new Array Prototype object
     * 
     * @param memory 
     * @param elementSize 
     */
    ArrayPrototype(const lang::Memory& memory, size_t elementSize);
    
    /**
     * @brief Construct a new Array Prototype object
     * 
     * @param length 
     * @param elementSize 
     */
    ArrayPrototype(size_t length, size_t elementSize);

    /**
     * @brief Destroy the Array Prototype object
     * 
     */
    virtual ~ArrayPrototype(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Get the Element Length object
     * 
     * @return int 
     */
    int getElementLength(void) const;

    /**
     * @brief Get the Element Size object
     * 
     * @return uint32_t 
     */
    int getElementSize(void) const;

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */
  protected:
    using Memory::indexOf;
  
    /**
     * @brief 
     * 
     * @param element 
     * @return int 
     */
    int indexOf(const void* element) const;

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

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_EC5AD114_2891_41FA_8DE3_9D5FAD422A07 */
