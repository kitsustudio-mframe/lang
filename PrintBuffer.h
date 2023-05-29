/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05
#define MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05

/* ****************************************************************************************
 * Include
 */  

#include <stdarg.h>

//-----------------------------------------------------------------------------------------
#include "./Memory.h"
#include "./Strings.h"
#include "./RingBuffer.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  class PrintBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class lang::PrintBuffer :public lang::RingBuffer{

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
     * @brief Construct a new Ring Buffer object
     * 
     * @param buffer 
     * @param bufferSize 
     */
    PrintBuffer(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new Ring Buffer object
     * 
     * @param memory 
     */
    PrintBuffer(const lang::Memory& memory);  

    /**
     * @brief Construct a new Ring Buffer object
     * 
     * @param length 
     */
    PrintBuffer(uint32_t length);
  
    /**
     * @brief Destroy the Print Stream object
     * 
     */
    virtual ~PrintBuffer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
    
  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    inline void print(bool b){
      this->print(b, false);
    }

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    inline void print(char c){
      this->print(c, false);
    }

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    inline void print(double d){
      this->print(d, false);
    }

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    inline void print(float f){
      this->print(f, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline void print(int i){
      this->print(i, false, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline void print(unsigned int i){
      this->print(static_cast<int>(i), false, true);
    }    
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline void print(const lang::Strings& string){
      this->print(string, false);
    }

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline void print(const char* string){
      this->print(string, false);
    }

    /**
     * @brief 
     * 
     * @param outputBuffer 
     * @return true 
     * @return false 
     */
    inline void print(lang::ReadBuffer& readBuffer){
      this->print(readBuffer, false);
    }    
    
    /**
     * @brief 
     * 
     * @param b 
     * @return true 
     * @return false 
     */
    inline void println(bool b){
      this->print(b, true);
    }

    /**
     * @brief 
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    inline void println(char c){
      this->print(c, true);
    }

    /**
     * @brief 
     * 
     * @param d 
     * @return true 
     * @return false 
     */
    inline void println(double d){
      this->print(d, true);
    }

    /**
     * @brief 
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    inline void println(float f){
      this->print(f, true);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline void println(int i){
      this->print(i, true, false);
    }

    /**
     * @brief 
     * 
     * @param i 
     * @return true 
     * @return false 
     */
    inline void println(unsigned int i){
      this->print(static_cast<int>(i), true, true);
    }    
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline void println(const lang::Strings& string){
      this->print(string, true);
    }

    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    inline void println(const char* string){
      this->print(string, true);
    }
    
    /**
     * @brief 
     * 
     * @param outputBuffer 
     * @return true 
     * @return false 
     */
    inline void println(lang::ReadBuffer& readBuffer){
      this->print(readBuffer, true);
    }
    
  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief 
     * 
     * @param b 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(bool b, bool newLine);

    /**
     * @brief 
     * 
     * @param c 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(char c, bool newLine);

    /**
     * @brief 
     * 
     * @param d 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(double d, bool newLine);

    /**
     * @brief 
     * 
     * @param f 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(float f, bool newLine);

    /**
     * @brief 
     * 
     * @param i 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(int i, bool newLine, bool unsign);

    /**
     * @brief 
     * 
     * @param string 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(const lang::Strings& string, bool newLine);

    /**
     * @brief 
     * 
     * @param string 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(const char* string, bool newLine);

    /**
     * @brief 
     * 
     * @param OutputBuffer 
     * @param newLine 
     * @return true 
     * @return false 
     */
    void print(lang::ReadBuffer& readBuffer, bool newLine);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    void println(void);

    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return true 
     * @return false 
     */
    void format(const char* format, ...);

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

#endif /* MCUF_0105D590_C0D6_4307_AB0E_0988007EEC05 */
