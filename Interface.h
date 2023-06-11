/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D
#define MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D

/* ******************************************************************************
 * Macro
 */

#pragma clang diagnostic ignored "-Wnon-virtual-dtor"
#pragma clang diagnostic ignored "-Wdeprecated-copy-dtor"
#pragma clang diagnostic ignored "-Wc++98-compat"
#pragma clang diagnostic ignored "-Wweak-vtables"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wc++17-extensions"
#pragma clang diagnostic ignored "-Wnested-anon-types"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wimplicit-fallthrough"

#define abstract = 0

#define enum_operator(e, t, o)                                                                             \
  static inline e operator o(e a, e b) { return static_cast<e>((static_cast<t>(a) o static_cast<t>(b))); } \
  static inline e operator o(e a, t b) { return static_cast<e>((static_cast<t>(a) o b)); }

#define enum_auto_operator(e, t) \
  enum_operator(e, t, |)         \
      enum_operator(e, t, &)

using size_t = unsigned int;

/* ******************************************************************************
 * Include
 */
#include <stdarg.h>
#include <stdint.h>

//-------------------------------------------------------------------------------

/* ******************************************************************************
 * Namespace
 */
namespace mframe::lang {
  struct Interface;
  class Object;
}  // namespace mframe::lang

/* ******************************************************************************
 * Class/struct/Struct/Enum
 */
struct mframe::lang::Interface {
  /* ****************************************************************************
   * Method
   */

  /**
   * @brief Destroy the struct object
   *
   */
  virtual ~Interface(void) = default;

  /**
   *
   */
  virtual mframe::lang::Object &getObject(void) abstract;
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wheader-hygiene"
using namespace mframe::lang;
#pragma clang diagnostic pop

/* ******************************************************************************
 * End of file
 */

#endif /* MFRAME_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
