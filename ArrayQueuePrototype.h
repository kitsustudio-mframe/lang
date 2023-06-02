/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_BBEA45DB_2443_4AD0_8532_619E2BDE4831
#define LANG_BBEA45DB_2443_4AD0_8532_619E2BDE4831

/* ******************************************************************************
 * Include
 */  

//-------------------------------------------------------------------------------
#include "./Consumer.h"

//-------------------------------------------------------------------------------
#include "./Array.h"


/* ******************************************************************************
 * Namespace
 */  
namespace lang{
  class ArrayQueuePrototype;
}

/* ******************************************************************************
 * Class Object
 */  
class lang::ArrayQueuePrototype :public lang::Array<void*>{

  /* ****************************************************************************
   * Subclass
   */

  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */
  protected: 
    uint16_t mHead;
    uint16_t mTail;
    bool mEmpty;
  
  /* ****************************************************************************
   * Variable <Private>
   */

  /* ****************************************************************************
   * Abstract method <Public>
   */

  /* ****************************************************************************
   * Abstract method <Protected>
   */

  /* ****************************************************************************
   * Construct Method
   */
  public:
    
    /**
     * @brief Construct a new Array Queue Prototype object
     * 
     * @param memory 
     */
    ArrayQueuePrototype(const lang::Memory& memory);
  
    /**
     * @brief Construct a new Array Queue Prototype object
     * 
     * @param size
     */
    ArrayQueuePrototype(uint32_t size);

    /**
     * @brief Destroy the Array Queue Prototype object
     * 
     */
    virtual ~ArrayQueuePrototype(void) override;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static>
   */

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Public Method <Inline>
   */
  public: 
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isEmpty(void) const{
      return this->mEmpty;
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isFull(void) const{
      return ((this->mHead == this->mTail) && (!this->mEmpty));
    }
   
  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override> - lang::Memroy
   */
  
  /* ****************************************************************************
   * Protected Method
   */
  protected:
    
    /**
     * @brief 
     * 
     */
    void clear(void);
  
    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    bool offerPointer(void* pointer);

    /**
     * @brief 
     * 
     * @return void* 
     */
    void* pollPointer(void);  
    
    /**
     * @brief 
     * 
     * @return void* 
     */
    void* peekPointer(void);    
    
    /**
     * @brief 
     * 
     * @return int 
     */
    int size(void) const;

    /**
     * @brief 
     * 
     * @param attachment 
     * @param action 
     */
    void foreachPrototype(lang::Consumer<void*>& action) const;

  /* ****************************************************************************
   * Private Method <Static>
   */

  /* ****************************************************************************
   * Private Method <Override>
   */
   
  /* ****************************************************************************
   * Private Method
   */  

};

/* *******************************************************************************
 * End of file
 */ 

#endif /* LANG_BBEA45DB_2443_4AD0_8532_619E2BDE4831 */
