/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_D6412968_F88E_43C3_9B72_FA8611376187
#define LANG_D6412968_F88E_43C3_9B72_FA8611376187

/* ******************************************************************************
 * Include
 */  

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./Object.h"

/* ******************************************************************************
 * Namespace
 */  
namespace lang{
  class Pointer;
  class Memory;
}

/* ******************************************************************************
 * Class/struct/Struct
 */  
class lang::Pointer : public lang::Object{
  
  friend Memory;
  /* ****************************************************************************
   * Subclass
   */
   
  /* ****************************************************************************
   * Variable <Public>
   */

  /* ****************************************************************************
   * Variable <Protected>
   */

  /* ****************************************************************************
   * Variable <Private>
   */
  private: 
    void* mPointer;  
  
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
     * @brief Construct a new Pointer object
     * 
     */
    Pointer(void);

    /**
     * @brief Construct a new Pointer object
     * 
     * @param pointer 
     */
    Pointer(const void* pointer);  
  
    /**
     * @brief Construct a new Pointer object
     * 
     * @param pointer 
     */
    Pointer(void* pointer);

    /**
     * @brief Construct a new Pointer object
     * 
     * @param pointer 
     */
    Pointer(uint32_t pointer);
    
    /**
     * @brief Construct a new Pointer object
     * 
     * @param other 
     */
    Pointer(const Pointer& other);
    
    /**
     * @brief Destroy the Pointer object
     * 
     */
    virtual ~Pointer(void) override;

  /* ****************************************************************************
   * Operator Method
   */
  public:

    /**
     * @brief 
     * 
     */
    inline operator void*(void){
      return Pointer::mPointer;
    }

    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    inline bool operator==(const void* pointer){
      return (Pointer::mPointer == pointer);
    }
    
    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    inline bool operator==(const Pointer& pointer){
      return (Pointer::mPointer == pointer.mPointer);
    }
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char
     */
    inline char operator[](int index) const{
      return static_cast<char*>(Pointer::mPointer)[index];
    }
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char
     */
    inline char operator[](unsigned int index) const{
      return static_cast<char*>(Pointer::mPointer)[index];
    }    

    /**
     * @brief 
     * 
     * @param index 
     * @return char&
     */
    char& operator[](int index){
      return static_cast<char*>(Pointer::mPointer)[index];
    }
    
    /**
     * @brief 
     * 
     * @param index 
     * @return char&
     */
    char& operator[](unsigned int index){
      return static_cast<char*>(Pointer::mPointer)[index];
    }

  /* ****************************************************************************
   * Public Method <Static Inline>
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
  public: 
  
    /**
     * @brief 
     * 
     * @param source 
     * @param length 
     * @return int 
     */
    int copy(const void* source, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int 
     */
    int copy(const void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 來源目標
     * @param offset 儲存目標起始偏移
     * @param start 來源目標起始偏移
     * @param length 來源目標長度
     * @return int 
     */
    virtual int copy(const void* source, int offset, int start, int length);

    /**
     * @brief 
     * 
     * @param destination 
     * @param length 
     * @return int 
     */
    int copyTo(void* destination, int length) const;

    /**
     * @brief 
     * 
     * @param destination 
     * @param start 
     * @param length 
     * @return int 
     */
    int copyTo(void* destination, int start, int length) const;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copyTo(void* destination, int shift, int start, int length) const; 
    
    /**
     * @brief 
     * 
     * @param str string
     * @return true equal
     * @return false not equal
     */
    bool compairStrings(const char* str) const;    
    
    /**
     * @brief 
     * 
     * @param str string
     * @param start 
     * @return true equal
     * @return false not equal
     */
    virtual bool compairStrings(const char* str, int start) const;
    
    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    bool compair(const void* source, int length) const;    
    
    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    bool compair(const void* source, int start, int length) const;
    
    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return true equal
     * @return false not equal
     */
    virtual bool compair(const void* source, int shift, int start, int length) const;
    
    /**
     * @brief 
     * 
     * @param ch 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOf(char ch, int start, int limit) const;

    /**
     * @brief 
     * 
     * @param str 
     * @param start 
     * @param limit 
     * @return int 
     */
    int indexOfStrings(const char* str, int limit) const;

    /**
     * @brief 
     * 
     * @param str 
     * @param start 
     * @param limit 
     * @return int 
     */
    int indexOfStrings(const char* str, int start, int limit) const;

    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start, int limit) const;

  /* ****************************************************************************
   * Public Method <inline>
   */
  public:

    /**
     * @brief Get the Byte object
     * 
     * @param shift 
     * @return char 
     */
    inline char getByte(int shift) const{
      return *static_cast<char*>(Pointer::pointer(shift));
    }

    /**
     * @brief Get the Integer object
     * 
     * @param shift 
     * @return int 
     */
    inline int getInteger(int shift) const{
      return *static_cast<int*>(Pointer::pointer(shift));
    }

    /**
     * @brief Get the Short object
     * 
     * @param shift 
     * @return short 
     */
    inline short getShort(int shift) const{
      return *static_cast<short*>(Pointer::pointer(shift));
    }

    /**
     * @brief Get the Pointer object
     * 
     * @param offset 
     * @return Pointer 
     */
    inline Pointer getPointer(uint32_t offset) const{
      return Pointer(&(static_cast<char*>(Pointer::mPointer))[offset]);
    }

    /**
     * @brief Get the Address object
     * 
     * @return uint32_t 
     */
    inline uint32_t getAddress(void) const{
      return reinterpret_cast<uint32_t>(Pointer::mPointer);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isAlignment32Bit(void){
      if((Pointer::getAddress() & 0x00000003) != 0)
        return false;
      
      return true;
    }
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isAlignment64Bit(void){
      if((Pointer::getAddress() & 0x00000007) != 0)
        return false;
      
      return true;
    }
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isNull(void) const{
      return (Pointer::mPointer == nullptr);
    }

    /**
     * @brief 
     * 
     * @return void* 
     */
    inline void* pointer(void) const{
      return Pointer::mPointer;
    }
    
    /**
     *
     */
    template<class T> inline T* pointer(const T *cast) const{
      return static_cast<T*>(Pointer::mPointer);
    }    
    
    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    inline void* pointer(uint32_t offset) const{
      return static_cast<char*>(Pointer::mPointer) + offset;
    }
    
    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    template<class T> inline T* pointer(uint32_t offset, const T *a) const{
      return static_cast<T*>(pointer(offset));
    }
    
    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    inline void* pointer(int offset) const{
      return static_cast<char*>(Pointer::mPointer) + offset;
    }
    
    /**
     * @brief 
     * 
     * @param offset 
     * @return void* 
     */
    template<class T> inline T* pointer(int offset, const T *a) const{
      return static_cast<T*>(pointer(offset));
    }

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

/* *******************************************************************************
 * End of file
 */ 

#endif /* LANG_D6412968_F88E_43C3_9B72_FA8611376187 */
