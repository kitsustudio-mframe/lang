/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_C045F3C4_B727_4170_9124_44EFD0DADB46
#define LANG_C045F3C4_B727_4170_9124_44EFD0DADB46

/* ****************************************************************************************
 * Include
 */ 

//-----------------------------------------------------------------------------------------
#include "./Allocator.h"
#include "./Collection.h"
#include "./Memory.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class Stacker;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::Stacker :public lang::Memory , 
  public lang::Collection<lang::Memory>,
  public lang::Allocator{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    uint8_t* mStackPointer;

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
     * @brief Construct a new Stacker object
     * 
     * @param buffer 
     * @param size 
     */
    Stacker(void* buffer, uint32_t size);

    /**
     * @brief Construct a new Stacker object
     * 
     * @param memory 
     */
    Stacker(const lang::Memory& memory);

    /**
     * @brief Destroy the Stacker object
     * 
     */
    virtual ~Stacker(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> lang::Collection<lang::Memory>
   */
  public: 
  
    /**
     * @brief Removes all of the elements from this collection. The collection will be 
     *        empty after this method returns.
     * 
     */
    virtual void clear(void) override;

    /**
     * @brief Returns true if this collection contains no elements.
     * 
     * @return true 
     * @return false 
     */
    virtual bool isEmpty(void) const override;

    /**
     * @brief Returns the number of elements in this collection.
     * 
     * @return uint32_t the number of elements in this collection.
     */
    virtual int size(void) const override;

  /* **************************************************************************************
   * Public Method <Override> lang::Allocator
   */
  public: 

    /**
     * @brief 
     * 
     * @param size 
     */
    virtual void* alloc(uint32_t size) override;

    /**
     * @brief 
     * 
     * @param ptr pointer
     * @return true successful
     * @return false fail
     */
    virtual bool free(void* ptr) override;

    /**
     * @brief 
     * 
     * @param ptr pointer
     * @param size pointer size
     * @return true successful
     * @return false fail
     */
    virtual bool free(void* ptr, uint32_t size) override;
  
  /* **************************************************************************************
   * Public Method 
   */
  public: 

    /**
     * @brief Get the Free object
     * 
     * @return uint32_t 
     */
    virtual uint32_t getFree(void);

    /**
     * @brief 
     * 
     * @param size 
     * @return void* 
     */
    virtual void* allocAlignment32(uint32_t size);
      
    /**
     * @brief 
     * 
     * @param size 
     * @return void* 
     */
    virtual void* allocAlignment64(uint32_t size);  

    /**
     * @brief 
     * 
     * @param size 
     * @return lang::Memory 
     */
    virtual lang::Memory allocMemory(uint32_t size);
      
    /**
     * @brief 
     * 
     * @param size 
     * @return lang::Memory 
     */
    virtual lang::Memory allocMemoryAlignment32(uint32_t size);

    /**
     * @brief 
     * 
     * @param size 
     * @return lang::Memory 
     */
    virtual lang::Memory allocMemoryAlignment64(uint32_t size);

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

#endif /* LANG_C045F3C4_B727_4170_9124_44EFD0DADB46 */
