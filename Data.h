/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_031134DB_6B71_465A_A2FE_2CC0EF880BA0
#define LANG_031134DB_6B71_465A_A2FE_2CC0EF880BA0

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Pointer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class Data;
  class Memory;
}


/* ****************************************************************************************
 * Class/struct/Struct/Enum
 */  
class lang::Data : public lang::Pointer{

  friend Memory;
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    uint32_t mLength;

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
     * @brief Construct a new Data object
     * 
     */
    Data(void);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Data(const void* pointer, size_t length);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Data(void* pointer, size_t length);

    /**
     * @brief Construct a new Data object
     * 
     * @param other 
     */
    Data(const Data& other);

    /**
     * @brief Destroy the Data object
     * 
     */
    virtual ~Data(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    /**
     * @brief 
     * 
     * @param pointer 
     * @param value 
     * @param length 
     */
    static void wipe(void* pointer, uint8_t value, int length);

    /**
     * @brief 
     * 
     * @param pointer 
     * @param length 
     */
    static void wipe(void* pointer, int length);

  /* **************************************************************************************
   * Public Method <Override> - lang::Pointer
   */
  public:

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int copy(const void* source, int shift, int start, int length) override;
  
  /* **************************************************************************************
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isReadOnly(void) const{
      return (Data::mLength & 0x80000000);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isEmpty(void) const{
      return (Data::isNull()) || (Data::length() == 0);
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline int length(void) const{
      return static_cast<int>(Data::mLength & 0x7FFFFFFF);
    }
    
  /* **************************************************************************************
   * Public Method
   */
  public:
    using Pointer::copy;
    using Pointer::indexOf;
    using Pointer::indexOfStrings;
    using Pointer::indexOfData;
  
    /**
     * @brief 
     * 
     * @param address 
     * @return true in range.
     * @return false isn't range.
     */
    bool inRange(void* address) const;

    /**
     * @brief 
     * 
     * @return int 
     */
    int wipe(void);

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    int wipe(uint8_t value);
  
    /**
     * @brief 
     * 
     * @param value 
     * @param length 
     * @return int 
     */
    int wipe(uint8_t value, int length);

    /**
     * @brief 
     * 
     * @param value 
     * @param start 
     * @param length 
     * @return int 
     */
    int wipe(uint8_t value, int start, int length);

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @return lang::Memory 
     */
    lang::Data subData(uint32_t beginIndex) const;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    int insertArray(const void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    int popArray(int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    int popArray(void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param ch 
     * @return int 
     */
    int indexOf(char ch) const;
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    int indexOfStrings(const char* str) const;
    
  /* **************************************************************************************
   * Public Method <Vitrual>
   */
  public:

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @param length 
     * @return lang::Memory 
     */
    virtual lang::Data subData(uint32_t beginIndex, uint32_t length) const;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int insertArray(const void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return true 
     * @return false 
     */
    virtual int popArray(void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param ch 
     * @param offset 
     * @return int 
     */
    virtual int indexOf(char ch, int offset) const;

    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start) const;

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

#endif /* LANG_031134DB_6B71_465A_A2FE_2CC0EF880BA0 */
