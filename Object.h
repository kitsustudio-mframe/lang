/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE
#define MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE

/* ****************************************************************************************
 * Include
 */  

#include <stdint.h>
#include <string.h>

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class Object;
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::Object : virtual public lang::Interface{
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
  public:

    /**
     * @brief Construct a new Object object
     * 
     */
    Object(void);

    /**
     * @brief Destroy the Object object
     * 
     */
    virtual ~Object(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     * @param n 
     * @return void* 
     */
    void* operator new(size_t n);

    /**
     * @brief 
     * 
     * @param n 
     * @param p 
     * @return void* 
     */
    void* operator new(size_t n, void* p);  

  /* **************************************************************************************
   * Public Method
   */
  public:
    /**
     * @brief 
     * 
     * @param milliseconds 
     */
    void delay(int milliseconds) const;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    bool equal(Object* object) const;

    /**
     * @brief 
     * 
     * @param object 
     * @return true 
     * @return false 
     */
    bool equal(Object& object) const;

    /**
     * @brief 
     * 
     */
    void finalize(void);

    /**
     * @brief 
     * 
     */
    void wait(void) const;
    
    /**
     * @brief 
     * 
     * @param timeout 
     * @return true 
     * @return false 
     */
    bool wait(int timeout) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool yield(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool systemLock(void) const;
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool systemUnlock(void) const;
   
    bool notify(uint32_t id);
    
    uint32_t getThreadID(void);
  /* **************************************************************************************
   * Public Method <Override> - lang::Interface
   */
  public:
    /**
     *
     */
    virtual lang::Object& getObject(void) override;

  /* **************************************************************************************
   * Public Method <Inline>
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

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MFRAME_E0630DAA_6AA0_44AB_8E3D_C89ABCA310DE */
