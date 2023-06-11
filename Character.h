/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_5098703C_A1D7_4D60_9E2D_E5F648A0C629
#define MFRAME_5098703C_A1D7_4D60_9E2D_E5F648A0C629

/* ******************************************************************************
 * Include
 */

//-------------------------------------------------------------------------------
#include "./../lang/Object.h"

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  class Character;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/Interface/Struct/Enum
 */
class mframe::lang::Character final : public mframe::lang::Object {
  /* ****************************************************************************
   * Variable <Public>
   */
 public:
  static const char CHAR_NUL = 0x00;  ///< 空字元（Null）
  static const char CHAR_SOH = 0x01;  ///< 標題開始
  static const char CHAR_STX = 0x02;  ///< 本文開始
  static const char CHAR_ETX = 0x03;  ///< 本文結束
  static const char CHAR_EOT = 0x04;  ///< 傳輸結束
  static const char CHAR_ENQ = 0x05;  ///< 請求
  static const char CHAR_ACK = 0x06;  ///< 確認回應
  static const char CHAR_BEL = 0x07;  ///< 響鈴
  static const char CHAR_BS = 0x08;   ///< 退格
  static const char CHAR_HT = 0x09;   ///< 水平定位符號
  static const char CHAR_LF = 0x0A;   ///< 換行鍵
  static const char CHAR_VT = 0x0B;   ///< 垂直定位符號
  static const char CHAR_FF = 0x0C;   ///< 換頁鍵
  static const char CHAR_CR = 0x0D;   ///< CR (字元)
  static const char CHAR_SO = 0x0E;   ///< 取消變換（Shift out）
  static const char CHAR_SI = 0x0F;   ///< 啟用變換（Shift in）
  static const char CHAR_DLE = 0x10;  ///< 跳出資料通訊
  static const char CHAR_DC1 = 0x11;  ///< 裝置控制一（XON 啟用軟體速度控制）
  static const char CHAR_DC2 = 0x12;  ///< 裝置控制二
  static const char CHAR_DC3 = 0x13;  ///< 裝置控制三（XOFF 停用軟體速度控制）
  static const char CHAR_DC4 = 0x14;  ///< 裝置控制四
  static const char CHAR_NAK = 0x15;  ///< 確認失敗回應
  static const char CHAR_SYN = 0x16;  ///< 同步用暫停
  static const char CHAR_ETB = 0x17;  ///< 區塊傳輸結束
  static const char CHAR_CAN = 0x18;  ///< 取消
  static const char CHAR_EM = 0x19;   ///< 連線媒介中斷
  static const char CHAR_SUB = 0x1A;  ///< 替換
  static const char CHAR_ESC = 0x1B;  ///< 登出鍵
  static const char CHAR_FS = 0x1C;   ///< 檔案分割符
  static const char CHAR_GS = 0x1D;   ///< 群組分隔符
  static const char CHAR_RS = 0x1E;   ///< 記錄分隔符
  static const char CHAR_US = 0x1F;   ///< 單元分隔符
  static const char CHAR_DEL = 0x7F;  ///< Delete字元

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

#endif /* MFRAME_5098703C_A1D7_4D60_9E2D_E5F648A0C629 */
