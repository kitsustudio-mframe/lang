/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef MFRAME_F115800B_0B0A_4795_ABFB_A37BD1DE2055
#define MFRAME_F115800B_0B0A_4795_ABFB_A37BD1DE2055

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../io/ReadBuffer.h"
#include "./../io/WriteBuffer.h"
#include "./../lang/Memory.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Strings;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct
 */
class mframe::lang::Strings final : public mframe::lang::Memory {
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
  Strings(const mframe::lang::Memory& memory);

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

  /* ****************************************************************************
   * Operator Method
   */
 public:
  /**
   * @brief
   *
   * @return operator const*
   */
  inline operator const char*(void) const {
    return static_cast<const char*>(this->pointer());
  }

  /**
   * @brief 插入字元至尾端
   *
   * @param ch 字元
   * @return Strings&
   */
  inline Strings& operator+=(const char ch) {
    return this->append(ch);
  }

  /**
   * @brief 插入字串至尾端
   *
   * @param str 字串
   * @return Strings&
   */
  inline Strings& operator+=(const char* str) {
    return this->append(str);
  }

  /**
   * @brief
   *
   * @param WriteBuffer
   * @return Strings&
   */
  inline Strings& operator+=(mframe::io::ReadBuffer& readBuffer) {
    return this->append(readBuffer);
  }

  /**
   * @brief
   *
   * @param value
   * @return Strings&
   */
  inline Strings& operator+=(int i) {
    return this->append(i);
  }

  /**
   * @brief
   *
   * @param value
   * @return Strings&
   */
  inline Strings& operator+=(double d) {
    return this->append(d);
  }

  /**
   * @brief
   *
   * @param str
   * @return Strings&
   */
  inline Strings& operator=(const char* str) {
    this->set(str);
    return *this;
  }

  /* ****************************************************************************
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
   * @param format
   * @param ...
   * @return Strings
   */
  static Strings format(int bufferSize, const char* format, ...);

  /**
   * @brief
   *
   * @param src
   * @return int
   */
  static int getLength(const char* src);

  /**
   *
   */
  static int getHashcode(const char* src);

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::Memory
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

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::Object
   */
 public:
  virtual int hashcode(void) const override;

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::Data
   */
 public:
  virtual int hashdata(void) const override;

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 清除字串空間
   *
   */
  void clear(void);

  /**
   * @brief 取得字串長度
   *
   * @return int 字串有效長度
   */
  int size(void) const;

  /**
   * @brief 取的字串原始空間大小
   *
   * 來自於Memory::size
   *
   * @return int 空間大小
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
   * @brief 串接字元
   *
   * @param c 字元
   * @return Strings&
   */
  Strings& append(const char c);

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
   * @param readBuffer
   * @return String&
   */
  Strings& append(mframe::io::ReadBuffer& readBuffer);

  /**
   * @brief
   *
   * @param value
   * @return String&
   */
  Strings& append(int value);

  /**
   * @brief
   *
   * @param value
   * @return Strings&
   */
  Strings& append(double value);

  /**
   * @brief
   *
   * @param boolena
   * @return Strings&
   */
  Strings& append(bool boolena);

  /**
   * @brief
   *
   * @param str
   * @return int
   */
  Strings& set(const char* str);

  /**
   * @brief 以全小寫的形式取得哈希碼
   *
   * @return int 哈希碼
   */
  int hashcodeLowerCast(void);

  /**
   * @brief 以全大寫的形式取得哈希碼
   *
   * @return int 哈希碼
   */
  int hashcodeUpperCast(void);

  /* ****************************************************************************
   * Public Method <Inline>
   */
 public:
  /**
   * @brief 如果字串內為空
   *
   * 若pointer[0] == 0x00 則返還true
   *
   * @return true 空字串
   * @return false 非空字串
   */
  inline bool isEmpty(void) const {
    return (this->size() == 0);
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

#endif /* MFRAME_F115800B_0B0A_4795_ABFB_A37BD1DE2055 */
