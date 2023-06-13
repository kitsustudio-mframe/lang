/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_031134DB_6B71_465A_A2FE_2CC0EF880BA0
#define MFRAME_031134DB_6B71_465A_A2FE_2CC0EF880BA0

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Pointer.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Data;
  class Memory;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
class mframe::lang::Data : public mframe::lang::Pointer {
  friend Memory;
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
  uint32_t mLength;

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
  Data(const void* pointer, int length);

  /**
   * @brief Construct a new Memory object
   *
   * @param pointer
   * @param length
   */
  Data(void* pointer, int length);

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

  /* ****************************************************************************
   * Operator Method
   */

  /* ****************************************************************************
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

  /* ****************************************************************************
   * Public Method <Override> - mframe::lang::Pointer
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
  inline bool isReadOnly(void) const {
    return (static_cast<uint32_t>(this->mLength) & 0x80000000);
  }

  /**
   * @brief
   *
   * @return int
   */
  inline int length(void) const {
    return static_cast<int>(this->mLength & 0x7FFFFFFF);
  }

  /**
   * @brief
   *
   * @return int
   */
  inline unsigned int lengthUnsigned(void) const {
    return (this->mLength & 0x7FFFFFFF);
  }

  /**
   * @brief
   *
   * @return int
   */
  inline int wipe(void) {
    return Data::wipe(0x00, 0, 0);
  }

  /**
   * @brief
   *
   * @param value
   * @return int
   */
  inline int wipe(uint8_t value) {
    return Data::wipe(value, 0, 0);
  }

  /**
   * @brief
   *
   * @param value
   * @param length
   * @return int
   */
  inline int wipe(uint8_t value, int length) {
    return Data::wipe(value, 0, length);
  }

  /**
   * @brief
   *
   * @param start
   * @param length
   * @return int32_t
   */
  inline int popArray(int start, int length) {
    return Data::popArray(nullptr, 0, start, length);
  }

  /**
   * @brief
   *
   * @param source
   * @param start
   * @param length
   * @return int32_t
   */
  inline int popArray(void* source, int start, int length) {
    return Data::popArray(source, 0, start, length);
  }

  /**
   * @brief 插入陣列至Data
   *
   * @param source 來源
   * @param start
   * @param length
   * @return int
   */
  inline int insertArray(const void* source, int start, int length) {
    return Data::insertArray(source, 0, start, length);
  }
  /* ****************************************************************************
   * Public Method
   */
 public:
  using Pointer::copy;
  using Pointer::indexOf;
  using Pointer::indexOfData;
  using Pointer::indexOfStrings;

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
   * @param value
   * @param start
   * @param length
   * @return int
   */
  int wipe(uint8_t value, int start, int length);

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

  /* ****************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief
   *
   * @param beginIndex
   * @param length
   * @return mframe::lang::Memory
   */
  virtual mframe::lang::Data subData(int beginIndex, int length) const;

  /**
   * @brief 複製陣列至Data
   *
   * @param source 來源
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

  /**
   * @brief
   *
   * @return int
   */
  virtual int hashdata(void) const;

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

#endif /* MFRAME_031134DB_6B71_465A_A2FE_2CC0EF880BA0 */
