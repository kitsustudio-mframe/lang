/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_F115800B_0B0A_4795_ABFB_A37BD1DE2055
#define LANG_F115800B_0B0A_4795_ABFB_A37BD1DE2055

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
  class Strings;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class lang::Strings final :public lang::Memory{

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
     * @brief Construct a new Strings object
     * 
     * @param pointer 
     * @param size 
     */
    Strings(void* pointer, unsigned int size);

    /**
     * @brief Construct a new Strings object
     * 
     * @param str 
     */
    Strings(const char* str);
    
    /**
     * @brief Construct a new Strings object
     * 
     * @param memory 
     */
    Strings(const lang::Memory& memory);

    /**
     * @brief Construct a new Strings object
     * 
     * @param length 
     */
    Strings(size_t length);

    /**
     * @brief Destroy the Strings object
     * 
     */
    virtual ~Strings(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:
  
    /**
     * @brief 
     * 
     * @return operator const* 
     */
    inline operator const char*(void) const{
      return static_cast<const char*>(this->pointer());
    }
    
    /**
     * @brief 
     * 
     * @param str 
     * @return Strings& 
     */
    inline Strings& operator+=(const char* str){
      this->append(str);
      return *this;
    }
    
    /**
     * @brief 
     * 
     * @param str 
     * @return Strings& 
     */
    inline Strings& operator=(const char* str){
      this->set(str);
      return *this;
    }

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    /**
     * @brief 
     * 
     * @return Strings 
     */
    static Strings empty(void);

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @param format 
     * @param arg 
     * @return int 
     */
    static int format(void* buffer, size_t bufferSize, const char* format, va_list args);

    /**
     * @brief 
     * 
     * @param memory 
     * @param format 
     * @param arg 
     * @return int 
     */
    static int format(const lang::Memory& memory, const char* format, va_list args);

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int format(void* buffer, unsigned int bufferSize, const char* format, ...);

    /**
     * @brief 
     * 
     * @param memory 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int format(const lang::Memory& memory, const char* format, ...);
    
    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return Strings 
     */
    static Strings format(int bufferSize, const char* format, ...);    
    
    /**
     * @brief 
     * 
     * @param src 
     * @param format 
     * @param args 
     * @return int 
     */
    static int scanFormat(const char* src, const char* format, va_list args);
    
    /**
     * @brief 
     * 
     * @param src 
     * @param format 
     * @param ... 
     * @return int 
     */
    static int scanFormat(const char* src, const char* format, ...);

    /**
     * @brief 
     * 
     * @param src 
     * @return int 
     */
    static int stringLength(const char* src);

  /* **************************************************************************************
   * Public Method <Override> - lang::Memory
   */
  public:
  
    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start) const override;
  
  /* **************************************************************************************
   * Public Method
   */
  public:
    
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    int size(void) const;
  
    /**
     * @brief 取的String原始空間大小
     * 
     * @return int 
     */
    int bufferSize(void);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return int 
     */
    int scanFormat(const char* format, ...);
  
    /**
     * @brief 
     * 
     * @param format 
     * @param arg 
     * @return int 
     */
    int format(const char* format, va_list arg);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return int 
     */
    int format(const char* format, ...);  

    /**
     * @brief 
     * 
     */
    void convertUpper(void);

    /**
     * @brief 
     * 
     */
    void convertLower(void);

    /**
     * @brief 
     * 
     * @return Strings 
     */
    Strings toUpper(void) const;

    /**
     * @brief 
     * 
     * @return Strings 
     */
    Strings toLower(void) const;
    
    /**
     * @brief 
     * 
     * @return Strings 
     */
    Strings clone(void) const;
    
    /**
     * @brief 
     * 
     * @param length 
     * @return Strings 
     */
    Strings clone(int length) const;
    
    /**
     * @brief 
     * 
     * @param offset  
     * @return Strings 
     */
    Strings clone(int offset, int length) const;

    /**
     * @brief 
     * 
     * @param oldChar 
     * @param newChar 
     * @return int 
     */
    int replace(char oldChar, char newChar);
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    Strings& append(const char* str);
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    Strings& set(const char* str);

  /* **************************************************************************************
   * Public Method <Inline>
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
 
#endif /* LANG_F115800B_0B0A_4795_ABFB_A37BD1DE2055 */
