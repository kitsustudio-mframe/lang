/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_FCCC3E6F_E524_4464_BA6F_FF9492970DA8
#define LANG_FCCC3E6F_E524_4464_BA6F_FF9492970DA8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./ArrayPrototype.h"
#include "./Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  template<typename E> class Array;
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename E>
  class lang::Array :public lang::ArrayPrototype{

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
     * @brief Construct a new Array object
     * 
     * @param memory 
     */
    Array(const lang::Memory& memory) : lang::ArrayPrototype(memory, sizeof(E)){
      return;
    }

    /**
     * @brief Construct a new Array object
     * 
     * @param e 
     * @param length 
     */
    Array(E* e, size_t length) : lang::ArrayPrototype(lang::Memory(e, sizeof(E) * length), sizeof(E)){
      return;
    }
    
    /**
     * @brief Construct a new Array object
     * 
     * @param e 
     * @param length 
     */
    Array(const E* e, size_t length) : lang::ArrayPrototype(lang::Memory(e, sizeof(E) * length), sizeof(E)){
      return;
    }

    /**
     * @brief Construct a new Array object
     * 
     * @param length 
     */
    Array(size_t length) : lang::ArrayPrototype(length, sizeof(E)){
      return;
    }

    /**
     * @brief Destroy the Array object
     * 
     */
    virtual ~Array(void) override {
      return;
    }
  
  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     * @param index 
     * @return E 
     */
    E operator[](int index) const{
      return static_cast<E*>(this->pointer())[index];
    }

    /**
     * @brief 
     * 
     * @param index 
     * @return E& 
     */
    E& operator[](int index){
      return static_cast<E*>(this->pointer())[index];
    }
  
  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

    /* **************************************************************************************
   * Public Method
   */
  
  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline int length(void) const{
      return this->mElementLength;
    }
    
    /**
     * @brief 
     * 
     * @param e 
     * @return int 
     */
    inline int indexOf(const E& e) const{
      return this->ArrayPrototype::indexOf(&e);
    }
    
    /**
     * @brief 
     * 
     * @param e 
     * @return true 
     * @return false 
     */
    inline bool contains(const E& e) const{
      return (this->ArrayPrototype::indexOf(&e) != -1);
    }
  
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


#endif /* LANG_FCCC3E6F_E524_4464_BA6F_FF9492970DA8 */
