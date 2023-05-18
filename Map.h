/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38
#define LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  template<typename K, typename V> interface Map;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename K, typename V>
interface lang::Map extends virtual lang::Interface{
  
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief  如果此映射包含指定键的映射，则返回true 。 更正式地，返回true当且仅当该地图包含
   *         关键字k的映射，使得(key==null ? k==null : key.equals(k)) 。 （最多可以有一个这样的映射。） 
   * 
   * @param key 要在此地图中存在的密钥要进行测试 
   * @return true 如果此映射包含指定键的映射  
   * @return false 
   */
  virtual bool containsKey(Interface& key) abstract;

  /**
   * @brief 如果此映射包含指定键的映射，则返回 true 。 
   * 
   * @param value 要在此地图中存在的值要进行测试 
   * @return true 如果该地图将一个或多个键映射到指定的值 
   * @return false 
   */
  virtual bool containsValue(Interface& value) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @return V 
   */
  virtual V get(K key) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @param value 
   * @return V 
   */
  virtual V put(K key, V value) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @return V 
   */
  virtual V remove(K key) abstract;

  /**
   * @brief 
   * 
   * @param key 
   * @param value 
   * @return V 
   */
  virtual V replace(K key, V value) abstract;

  /**
   * @brief 
   * 
   */
  virtual void clear(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isEmpty(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual int size(void) abstract;

};



/* *****************************************************************************************
 * End of file
 */ 


#endif /* LANG_EC6FEC6D_9D9D_4888_A683_6B2477CEEC38 */
