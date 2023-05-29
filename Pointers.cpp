/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Pointers.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using lang::Pointers;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

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
lang::Pointer Pointers::nullPointer(void){
  return lang::Pointer();
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
void Pointers::copy(void* destination, const void* source, int length){
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
void Pointers::move(void* destination, const void* source, int length){
  memmove(destination, source, static_cast<size_t>(length));
}
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

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
