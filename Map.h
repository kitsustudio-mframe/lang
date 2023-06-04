/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38
#define LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Collection.h"

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  template <class V>
  struct Map;
}

/* ******************************************************************************
 * Class/Interface/Struct
 */

/**
 * @brief 將鍵映射到值的對象。地圖不能包含重複的鍵; 每個鍵可以映射到最多一個值。
 *
 * @tparam V Value
 */
template <class V>
struct lang::Map : public virtual lang::Interface {
  /* ****************************************************************************
   * Method
   */

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
  virtual bool containsKey(Interface& key) abstract;

  /**
   * @brief 如果此映射包含指定鍵的映射，則返回true。
   *
   * @param value 要在此地圖中存在的值要進行測試
   * @return true 如果該地圖將一個或多個鍵映射到指定的值
   */
  virtual bool containsValue(void* value) abstract;

  /**
   * @brief 將指定的值與該映射中的指定鍵相關聯(可選操作)。
   *
   * 如果映射先前包含了密鑰的映射，則舊值將被指定的值替換。
   * (映射m被認為包含關鍵字的映射k當且僅當m.containsKey(k)將返回true)。
   *
   * @param key 指定值與之關聯的鍵
   * @return V 與指定鍵相關聯的值
   */
  virtual V* get(Interface& key) abstract;

  /**
   * @brief 將指定的值與該映射中的指定鍵相關聯(可選操作)。
   *
   * 如果映射先前包含了密鑰的映射，則舊值將被指定的值替換。
   * (映射m被認為包含關鍵字的映射k當且僅當m.containsKey(k)將返回true)。
   *
   * @param key 指定值與之關聯的鍵
   * @param value 與指定鍵相關聯的值
   * @return V* 前一個值與key相關聯，或null，如果沒有key的映射。
   * (A null返回也可以表示該地圖以前關聯的null與key，如果實現支持null的值）
   */
  virtual V* put(Interface& key, V* value) abstract;

  /**
   * @brief
   *
   * @param key
   * @return V
   */
  virtual V* remove(Interface& key) abstract;

  /**
   * @brief
   *
   * @param key
   * @param value
   * @return V
   */
  virtual V* replace(Interface& key, V* value) abstract;

  /**
   * @brief
   * 從此集合中刪除所有元素(可選操作)。此方法返回後，集合將為空。
   *
   */
  virtual void clear(void) abstract;

  /**
   * @brief
   * 如果此集合不包含元素，則返回true。
   *
   * @return
   * true如果此集合不包含元素
   */
  virtual bool isEmpty(void) const abstract;

  /**
   * @brief
   * 返回此集合中的元素數。
   * 如果此收藏包含超過 Integer.MAX_VALUE個元素，則返回Integer.MAX_VALUE。
   *
   * @return uint32_t - 此集合中的元素数
   */
  virtual int size(void) const abstract;
};

/* *******************************************************************************
 * End of file
 */

#endif /* LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38 */
