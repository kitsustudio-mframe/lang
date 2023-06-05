/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_2564A55F_C25D_43D2_ADD6_BE125D634CFB
#define LANG_2564A55F_C25D_43D2_ADD6_BE125D634CFB

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./Map.h"
#include "./Memory.h"
#include "./Object.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace lang {
  class ArrayMapPrototype;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::ArrayMapPrototype : public lang::Object {
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
  lang::Memory mMemory;
  int mSize;

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
   * @brief Construct a new Array Map Prototype object
   *
   * @param memory 緩存來源
   */
  ArrayMapPrototype(const lang::Memory& memory);

  /**
   * @brief Destroy the Array Map Prototype object
   *
   * @param size 元素數量
   */
  ArrayMapPrototype(int size);

  /**
   * @brief Destroy the Array Map Prototype object
   *
   */
  virtual ~ArrayMapPrototype(void) override;

  /* **************************************************************************************
   * Operator Method
   */

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
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */
 public:
  /**
   * @brief  如果此映射將一個或多個鍵映射到指定的值，則返回true。
   *
   * 更正式地，返回true當且僅當此映射包含至少一個映射到值v，
   * 使得(value==null ? v==null : value.equals(v))。
   *
   * 對於Map接口的大多數實現，此操作對於地圖大小可能需要時間線性。
   *
   * @param key 要在此地圖中存在的值要進行測試
   * @return true - 如果該地圖將一個或多個鍵映射到指定的值
   */
  bool containsKeyHash(int hashcode);

  /**
   * @brief 如果此映射包含指定鍵的映射，則返回true。
   *
   * @param value 要在此地圖中存在的值要進行測試
   * @return true 如果該地圖將一個或多個鍵映射到指定的值
   */
  bool containsValue(void* value);

  /**
   * @brief 將指定的值與該映射中的指定鍵相關聯(可選操作)。
   *
   * 如果映射先前包含了密鑰的映射，則舊值將被指定的值替換。
   * (映射m被認為包含關鍵字的映射k當且僅當m.containsKey(k)將返回true)。
   *
   * @param key 指定值與之關聯的鍵
   * @return V 與指定鍵相關聯的值
   */
  void* getHash(int hashcode);

  /**
   * @brief 將指定的值與該映射中的指定鍵相關聯(可選操作)。
   *
   * 如果映射先前包含了密鑰的映射，則舊值將被指定的值替換。
   * (映射m被認為包含關鍵字的映射k當且僅當m.containsKey(k)將返回true)。
   *
   * @param key 哈希碼
   * @param value 與指定鍵相關聯的值
   * @return V* 前一個值與key相關聯，或null，如果沒有key的映射。
   * (A null返回也可以表示該地圖以前關聯的null與key，如果實現支持null的值）
   */
  void* putHash(int hashcode, void* value);

  /**
   * @brief 
   * 
   * @param hashcode 哈希碼
   * @return void* 
   */
  void* removeHash(int hashcode);

  /**
   * @brief
   *
   * @param hashcode 哈希碼
   * @param value
   * @return V
   */
  void* replaceHash(int hashcode, void* value);

  /**
   * @brief 從此集合中刪除所有元素(可選操作)。此方法返回後，集合將為空。
   *
   */
  void clear(void);

  /**
   * @brief 如果此集合不包含元素，則返回true。
   *
   * @return
   *  - true如果此集合不包含元素
   */
  bool isEmpty(void) const;

  /**
   * @brief 返回此集合中的元素數。
   * 
   * 如果此收藏包含超過 Integer.MAX_VALUE個元素，則返回Integer.MAX_VALUE。
   *
   * @return int 此集合中的元素数
   */
  int size(void) const;

  /**
   * @brief 返回此集合的容量
   * 
   * @return int 
   */
  int length(void) const;

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

#endif /* LANG_2564A55F_C25D_43D2_ADD6_BE125D634CFB */
