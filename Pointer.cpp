/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */ 

#include <string.h>

//-----------------------------------------------------------------------------------------
#include "./Pointer.h"

/* ****************************************************************************************
 * Using
 */  
using lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Pointer:: Pointer object
 * 
 */
Pointer::Pointer(void){
  Pointer::mPointer = nullptr;
  return;
}

/**
 * @brief Construct a new Pointer object
 * 
 * @param pointer 
 */
Pointer::Pointer(const void* pointer){
  Pointer::mPointer = const_cast<uint8_t*>(static_cast<const uint8_t*>(pointer));
  return;  
}

/**
 * @brief Construct a new Pointer:: Pointer object
 * 
 * @param pointer 
 */
Pointer::Pointer(void* pointer){
  Pointer::mPointer = static_cast<uint8_t*>(pointer);
  return;
}

/**
 * @brief Construct a new Pointer:: Pointer object
 * 
 * @param pointer 
 */
Pointer::Pointer(uint32_t pointer){
  Pointer::mPointer = reinterpret_cast<uint8_t*>(pointer);
  return;
}

/**
 * @brief Construct a new Pointer object
 * 
 * @param other 
 */
Pointer::Pointer(const Pointer& other){
  *this = other;
  return;
}

/**
 * @brief Destroy the Pointer object
 * 
 */
Pointer::~Pointer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @return Pointer 
 */
Pointer Pointer::nullPointer(void){
  return Pointer();
}

/**
 * @brief Copies the values of num bytes from the location pointed to by source 
 *        directly to the memory block pointed to by destination.
 * 
 *        he underlying type of the objects pointed to by both the source and 
 *        destination pointers are irrelevant for this function; The result is a 
 *         binary copy of the data.
 *  
 *        The function does not check for any terminating null character in source - 
 *        it always copies exactly num bytes.
 * 
 *        To avoid overflows, the size of the arrays pointed to by both the 
 *        destination and source parameters, shall be at least num bytes, and should 
 *        not overlap(for overlapping memory blocks, move is a safer approach).
 * 
 * @param destination Pointer to the destination array where the content is to be copied, 
 *                    type-casted to a pointer of type void*.
 * 
 * @param source Pointer to the source of data to be copied, type-casted to a pointer of 
 *               type const void*.
 * 
 * @param length Number of bytes to copy.
 */
void Pointer::copy(void* destination, const void* source, int length){
  memcpy(destination, source, static_cast<size_t>(length));
}

/**
 * @brief Copies the values of num bytes from the location pointed by source to the memory 
 *        block pointed by destination. Copying takes place as if an intermediate buffer 
 *        were used, allowing the destination and source to overlap.
 *        
 *        The underlying type of the objects pointed by both the source and destination 
 *        pointers are irrelevant for this function; The result is a binary copy of the data.
 * 
 *        The function does not check for any terminating null character in source - it always 
 *        copies exactly num bytes.
 * 
 *        To avoid overflows, the size of the arrays pointed by both the destination and source 
 *        parameters, shall be at least num bytes.
 * 
 * @param destination Pointer to the destination array where the content is to be copied, 
 *                    type-casted to a pointer of type void*.
 * 
 * @param source Pointer to the source of data to be copied, type-casted to a pointer of 
 *               type const void*.
 * 
 * @param length Number of bytes to copy.
 */
void Pointer::move(void* destination, const void* source, int length){
  memmove(destination, source, static_cast<size_t>(length));
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, int length){
  return this->copy(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, int start, int length){
  return this->copy(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, int offset, int start, int length){
  if(length <= 0)
    return 0;  
  
  if((source == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  if(length <= 0)
    return 0;
  
  memcpy(this->pointer(start), (static_cast<const char*>(source) + offset), static_cast<size_t>(length));
  return length;
}

/**
 * @brief 
 * 
 * @param destination 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, int length) const{
  return this->copyTo(destination, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param destination 
 * @param shift 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, int start, int length) const{
  return this->copyTo(destination, 0, start, length);
}

/**
 * @brief 
 * 
 * @param destination 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, int shift, int start, int length) const{
  if(length <= 0)
    return 0;
  
  if((destination == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  if(length <= 0)
    return 0;
  
  memcpy((static_cast<char*>(destination) + shift), Pointer::pointer(start), static_cast<size_t>(length));
  return static_cast<int>(length);
}

/**
 * @brief 
 * 
 * @param str 
 * @return true equal
 * @return false not equal
 */
bool Pointer::compairStrings(const char* str) const{
  return this->compair(str, 0, 0, static_cast<int>(strlen(str)));
}

/**
 * @brief 
 * 
 * @param str 
 * @param start 
 * @return true equal
 * @return false not equal
 */
bool Pointer::compairStrings(const char* str, int start) const{
  return this->compair(str, 0, start, static_cast<int>(strlen(str)));
}

/**
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return true equal
 * @return false not equal
 */
bool Pointer::compair(const void* source, int length) const{
  return this->compair(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return true equal
 * @return false not equal
 */
bool Pointer::compair(const void* source, int start, int length) const{
  return this->compair(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return true equal
 * @return false not equal
 */
bool Pointer::compair(const void* source, int shift, int start, int length) const{
  if(length <= 0)
    return false;
  
  const char* str1 = static_cast<const char*>(source) + shift;
  const char* str2 = static_cast<const char*>(this->pointer()) + start;
  
  return (memcmp(str1, str2, static_cast<size_t>(length)) == 0);  
}

/**
 * @brief 
 * 
 * @param ch 
 * @param start 
 * @param limit 
 * @return int 
 */
int Pointer::indexOf(char ch, int start, int limit) const{
  return this->indexOfData(&ch, 1, start, limit);
}

/**
 * @brief 
 * 
 * @param str 
 * @param limit 
 * @return int 
 */
int Pointer::indexOfStrings(const char* str, int limit) const{
  return this->indexOfData(str, static_cast<int>(strlen(str)), 0, limit);
}

/**
 * @brief 
 * 
 * @param str 
 * @param start 
 * @param limit 
 * @return int 
 */
int Pointer::indexOfStrings(const char* str, int start, int limit) const{
  return this->indexOfData(str, static_cast<int>(strlen(str)), start, limit);
}

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @param limit 
 * @return int 
 */
int Pointer::indexOfData(const void* destination, int destinationLen, int start, int limit) const{
  if(limit <= 0)
    return -1;

  if(destinationLen <= 0)
    return -1;
  
  const char* ptr = static_cast<const char*>(Pointer::pointer(start));
  const char* dst = static_cast<const char*>(destination);

  for(int i=0; i<limit; ++i){
    if(ptr[i] == dst[0]){
      bool result = true;
      for(int j=1; j<destinationLen; ++j){
        if(ptr[i+j] != dst[j]){
          result = false;
          i+=j;
          break;
        }
      }
      
      if(result)
        return i + start;
    }
  }
  
  return -1;
}

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */
 
/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */
