/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629
#define MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./Object.h"

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace lang {
  class Character;
}

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class lang::Character final : public lang::Object {
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
 private:
  /**
   * @brief Construct a new Character object
   *
   */
  Character(void);

 public:
  /**
   * @brief Destroy the Character object
   *
   */
  virtual ~Character(void) override;

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
   * @param c 
   * @return true 
   * @return false 
   */
  static bool inline isNextSymbol(char c) {
    return ((c == '\0') || (c == '\n') || (c == ' ') || (c == '\r') || (c == '\t'));
  }
  
  /**
   * @brief 
   * 
   * @param c 
   * @return true 
   * @return false 
   */
  static bool inline isNextLineSymbol(char c) {
    return ((c == '\0') || (c == '\n') || (c == '\r'));
  }

  /**
   * @brief
   *
   * @param ch
   * @return char
   */
  static char toUpperCase(char ch);

  /**
   * @brief 將字串轉換為大寫，當遇到'\0'時停止。
   *
   * @param src 來源
   * @param dst 目標
   * @return int 經過轉換的字符數量
   */
  static int toUpperCase(const char* src, char* dst);

  /**
   * @brief 將字串轉換為大寫，當遇到'\0'或滿足最大轉換長度時停止。
   *
   * @param src 來源
   * @param dst 目標
   * @param length 最大轉換長度，若為0則將忽略最大轉換長度，直到發現'\0'為止。
   * @return int 經過轉換的字符數量
   */
  static int toUpperCase(const char* src, char* dst, int length);

  /**
   * @brief
   *
   * @param ch
   * @return char
   */
  static char toLowerCase(char ch);

  /**
   * @brief 將字串轉換為小寫，當遇到'\0'時停止。
   *
   * @param src 來源
   * @param dst 目標
   * @return int 經過轉換的字符數量
   */
  static int toLowerCase(const char* src, char* dst);

  /**
   * @brief 將字串轉換為小寫，當遇到'\0'或滿足最大轉換長度時停止。
   *
   * @param src 來源
   * @param dst 目標
   * @param length 最大轉換長度，若為0則將忽略最大轉換長度，直到發現'\0'為止。
   * @return int 經過轉換的字符數量
   */
  static int toLowerCase(const char* src, char* dst, int length);

  /**
   * @brief
   *
   * @param highChar
   * @param lowChar
   * @return char
   */
  static char hexCharToChar(char highChar, char lowChar);

  /**
   * @brief
   *
   * @param ch
   * @return char
   */
  static char hexCharToChar(char ch);

  /**
   * @brief 字元比較
   *
   * @param src1 來源1
   * @param src2 來源2
   * @return true 比較結果相同
   * @return false 比較結果不同
   */
  static bool compare(char src1, char src2);

  /**
   * @brief 字元比較
   *
   * @param src1 來源1
   * @param src2 來源2
   * @return true 比較結果相同
   * @return false 比較結果不同
   */
  static bool compare(const char* str1, const char* str2);

  /**
   * @brief 字元比較
   *
   * @param src1 來源1
   * @param src2 來源2
   * @return true 比較結果相同
   * @return false 比較結果不同
   */
  static bool compare(const char* str1, const char* str2, int length);

  /**
   * @brief 字元比較且忽略大小寫
   *
   * @param src1 來源1
   * @param src2 來源2
   * @return true 比較結果相同
   * @return false 比較結果不同
   */
  static bool compareIgnoreCast(char src1, char src2);

  /**
   * @brief 比較字符串且忽略大小寫
   *
   * @param src1 字符串1
   * @param src2 字符串2
   * @return true 字符串相同
   * @return false 字符串不相同
   */
  static bool compareIgnoreCast(const char* src1, char const* src2);

  /**
   * @brief 比較字符串且忽略大小寫，限定字符串最大長度為length
   *
   * @param src1 字符串1
   * @param src2 字符串2
   * @param length 最大比較長度
   * @return true 字符串相同
   * @return false 字符串不相同
   */
  static bool compareIgnoreCast(const char* src1, char const* src2, int length);

  /**
   * @brief 取得字符串長度，當遇到'/0'時返回計數
   *
   * @param src 來源
   * @return int 字符串長度
   */
  static int length(const char* src);

  /* ****************************************************************************
   * Public Method <Override>
   */

  /* ****************************************************************************
   * Public Method
   */

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

#endif /* MCUF_5098703C_A1D7_4D60_9E2D_E5F648A0C629 */
