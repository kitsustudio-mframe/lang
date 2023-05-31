/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_27CD9666_FD9F_478C_983C_06FC70DDE127
#define LANG_27CD9666_FD9F_478C_983C_06FC70DDE127

/* ******************************************************************************
 * Include
 */  

//-------------------------------------------------------------------------------
#include "./Object.h"
#include "./Pointer.h"

//-------------------------------------------------------------------------------


/* ******************************************************************************
 * Namespace
 */  
namespace lang{
  class Pointers;
}


/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::Pointers {

  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

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
  private: 
    /**
     *
     */
    Pointers(void);
  
  public:
    /**
     *
     */
    virtual ~Pointers(void) = default;

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
   * Public Method <Static Inline>
   */
  public:
    /**
     *
     */
    static inline unsigned int castUnsigned(const void* pointer){
      return reinterpret_cast<unsigned int>(pointer);
    }
    
    /**
     *
     */
    static inline unsigned int castSigned(const void* pointer){
      return reinterpret_cast<unsigned int>(pointer);
    }
  
    /**
     * @brief 
     * 
     * @param point 
     * @param shift 
     * @return void* 
     */
    template<class T> static T* pointShift(T* pointer, int shift){
      return reinterpret_cast<T*>(reinterpret_cast<int>(pointer) + shift);
    }
    
    /**
     * @brief 
     * 
     * @param point 
     * @param shift 
     * @return void* 
     */
    template<class T> static const T* pointShift(const T* pointer, int shift){
      return reinterpret_cast<T*>(reinterpret_cast<int>(pointer) + shift);
    }    

    /**
     *
     */
    template<class T> static inline T* pointCast(void* src, const T* t){
      return static_cast<T*>(src);
    }
    
    /**
     *
     */
    template<class T> static inline T* pointCast(uint32_t address, const T* t){
      return static_cast<T*>(reinterpret_cast<void*>(address));
    }  
  
  /* ****************************************************************************
   * Public Method <Static>
   */
  public: 

    /**
     * @brief 
     * 
     * @return Pointer 
     */
    static lang::Pointer nullPointer(void);

    /**
     * @brief Copies the values of num bytes from the location pointed to by source 
     *        directly to the memory block pointed to by destination.
     * 
     *        he underlying type of the objects pointed to by both the source and 
     *        destination pointers are irrelevant for this function; The result is a 
     *         binary copy of the data.
     *  
     *        The function does not check for any terminating null character in source - 
     *        it always copies exactly num bytes.
     * 
     *        To avoid overflows, the size of the arrays pointed to by both the 
     *        destination and source parameters, shall be at least num bytes, and should 
     *        not overlap(for overlapping memory blocks, move is a safer approach).
     * 
     * @param destination Pointer to the destination array where the content is to be copied, 
     *                    type-casted to a pointer of type void*.
     * 
     * @param source Pointer to the source of data to be copied, type-casted to a pointer of 
     *               type const void*.
     * 
     * @param length Number of bytes to copy.
     */
    static void copy(void* destination, const void* source, int length);

    /**
     * @brief Copies the values of num bytes from the location pointed by source to the memory 
     *        block pointed by destination. Copying takes place as if an intermediate buffer 
     *        were used, allowing the destination and source to overlap.
     *        
     *        The underlying type of the objects pointed by both the source and destination 
     *        pointers are irrelevant for this function; The result is a binary copy of the data.
     * 
     *        The function does not check for any terminating null character in source - it always 
     *        copies exactly num bytes.
     * 
     *        To avoid overflows, the size of the arrays pointed by both the destination and source 
     *        parameters, shall be at least num bytes.
     * 
     * @param destination Pointer to the destination array where the content is to be copied, 
     *                    type-casted to a pointer of type void*.
     * 
     * @param source Pointer to the source of data to be copied, type-casted to a pointer of 
     *               type const void*.
     * 
     * @param length Number of bytes to copy.
     */
    static void move(void* destination, const void* source, int length);

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

  /* ****************************************************************************
   * Protected Method <Static>
   */

  /* ****************************************************************************
   * Protected Method <Override>
   */

  /* ****************************************************************************
   * Protected Method
   */

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

/* ******************************************************************************
 * End of file
 */ 

#endif /* LANG_27CD9666_FD9F_478C_983C_06FC70DDE127 */
