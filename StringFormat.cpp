/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ******************************************************************************
 * Include
 */

#include <stdio.h>
#include <string.h>

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
#include "./StringFormat.h"
#include "./System.h"

/* ******************************************************************************
 * Macro
 */

/* ******************************************************************************
 * Using
 */

//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
using lang::StringFormat;

/* ******************************************************************************
 * Variable <Static>
 */
char StringFormat::mFormatBuffer[128];
/* ******************************************************************************
 * Construct Method
 */

/* ******************************************************************************
 * Operator Method
 */

/* ******************************************************************************
 * Public Method <Static>
 */

//-------------------------------------------------------------------------------
int StringFormat::pointerVa(void* buffer, size_t bufferSize, const char* format, va_list args) {
  return vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
}

//-------------------------------------------------------------------------------
int StringFormat::memoryVa(const lang::Memory& memory, const char* format, va_list args) {
  if (memory.isReadOnly())
    return 0;

  return vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
}

//-------------------------------------------------------------------------------
int StringFormat::writeBufferVa(io::WriteBuffer& writeBuffer, const char* format, va_list args) {
  lang::System::lock();
  int result = vsnprintf(StringFormat::mFormatBuffer, sizeof(StringFormat::mFormatBuffer), format, args);
  result = writeBuffer.put(StringFormat::mFormatBuffer, result);
  lang::System::unlock();
  return result;
}

//-------------------------------------------------------------------------------
int StringFormat::pointer(void* buffer, uint32_t bufferSize, const char* format, ...) {
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
  va_end(args);
  return result;
}

//-------------------------------------------------------------------------------
int StringFormat::memory(const lang::Memory& memory, const char* format, ...) {
  if (memory.isReadOnly())
    return 0;

  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
  va_end(args);
  return result;
}

//-------------------------------------------------------------------------------
int StringFormat::writeBuffer(io::WriteBuffer& writeBuffer, const char* format, ...) {
  va_list args;
  va_start(args, format);
  lang::System::lock();
  int result = vsnprintf(static_cast<char*>(StringFormat::mFormatBuffer), sizeof(StringFormat::mFormatBuffer), format, args);
  result = writeBuffer.put(StringFormat::mFormatBuffer, result);
  lang::System::unlock();
  va_end(args);
  return result;
}

//-------------------------------------------------------------------------------
int StringFormat::scanVa(const char* src, const char* format, va_list args) {
  return vsscanf(src, format, args);
}

//-------------------------------------------------------------------------------
int StringFormat::scan(const char* src, const char* format, ...) {
  va_list args;
  va_start(args, format);
  int result = vsscanf(src, format, args);
  va_end(args);
  return result;
}
/* ******************************************************************************
 * Public Method <Override>
 */

/* ******************************************************************************
 * Public Method
 */

/* ******************************************************************************
 * Protected Method <Static>
 */

/* ******************************************************************************
 * Protected Method <Override>
 */

/* ******************************************************************************
 * Protected Method
 */

/* ******************************************************************************
 * Private Method
 */

/* ******************************************************************************
 * End of file
 */
