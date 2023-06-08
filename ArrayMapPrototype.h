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
class lang::ArrayMapPrototype : public lang::Object,
                                public lang::Map<lang::Interface, void*> {
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
   * Public Method <Override> - lang::Iterable<void*>
   */
 public:
  virtual bool peekIndex(int index, void*& result) override;

  /* **************************************************************************************
   * Public Method <Override> - lang::Collection<void*>
   */
 public:
  virtual void clear(void) override;

  virtual bool isEmpty(void) const override;

  virtual int size(void) const override;

  /* **************************************************************************************
   * Public Method - lang::Map<void*>
   */
 public:
  virtual bool containsKey(Interface& key) const override;

  virtual bool containsValue(void** value) const override;

  virtual void** get(Interface& key) const override;

  virtual void** put(Interface& key, void** value) override;

  virtual void** remove(Interface& key) override;

  virtual void** replace(Interface& key, void** value) override;

  /* **************************************************************************************
   * Public Method
   */
 public:
  /**
   * @brief 返回此集合的容量
   *
   * @return int
   */
  int length(void) const;
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

#endif /* LANG_2564A55F_C25D_43D2_ADD6_BE125D634CFB */
