/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef LANG_A4ED407B_D298_46DA_B209_AEF00726AA6F
#define LANG_A4ED407B_D298_46DA_B209_AEF00726AA6F

/* ****************************************************************************************
 * Include
 */
 
//-----------------------------------------------------------------------------------------
#include "./Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace lang{
  enum struct ThreadPriority : int;
}

/* ****************************************************************************************
 * Class/struct/Struct
 */  
enum struct lang::ThreadPriority : int{
  LOW            =  8,         ///< PRIORITY_: low
  LOW1           =  8+1,       ///< PRIORITY_: low + 1
  LOW2           =  8+2,       ///< PRIORITY_: low + 2
  LOW3           =  8+3,       ///< PRIORITY_: low + 3
  LOW4           =  8+4,       ///< PRIORITY_: low + 4
  LOW5           =  8+5,       ///< PRIORITY_: low + 5
  LOW6           =  8+6,       ///< PRIORITY_: low + 6
  LOW7           =  8+7,       ///< PRIORITY_: low + 7
  BELOW_NORMAL   = 16,         ///< PRIORITY_: below normal
  BELOW_NORMAL1  = 16+1,       ///< PRIORITY_: below normal + 1
  BELOW_NORMAL2  = 16+2,       ///< PRIORITY_: below normal + 2
  BELOW_NORMAL3  = 16+3,       ///< PRIORITY_: below normal + 3
  BELOW_NORMAL4  = 16+4,       ///< PRIORITY_: below normal + 4
  BELOW_NORMAL5  = 16+5,       ///< PRIORITY_: below normal + 5
  BELOW_NORMAL6  = 16+6,       ///< PRIORITY_: below normal + 6
  BELOW_NORMAL7  = 16+7,       ///< PRIORITY_: below normal + 7
  NORMAL         = 24,         ///< PRIORITY_: normal
  NORMAL1        = 24+1,       ///< PRIORITY_: normal + 1
  NORMAL2        = 24+2,       ///< PRIORITY_: normal + 2
  NORMAL3        = 24+3,       ///< PRIORITY_: normal + 3
  NORMAL4        = 24+4,       ///< PRIORITY_: normal + 4
  NORMAL5        = 24+5,       ///< PRIORITY_: normal + 5
  NORMAL6        = 24+6,       ///< PRIORITY_: normal + 6
  NORMAL7        = 24+7,       ///< PRIORITY_: normal + 7
  ABOVE_NORMAL   = 32,         ///< PRIORITY_: above normal
  ABOVE_NORMAL1  = 32+1,       ///< PRIORITY_: above normal + 1
  ABOVE_NORMAL2  = 32+2,       ///< PRIORITY_: above normal + 2
  ABOVE_NORMAL3  = 32+3,       ///< PRIORITY_: above normal + 3
  ABOVE_NORMAL4  = 32+4,       ///< PRIORITY_: above normal + 4
  ABOVE_NORMAL5  = 32+5,       ///< PRIORITY_: above normal + 5
  ABOVE_NORMAL6  = 32+6,       ///< PRIORITY_: above normal + 6
  ABOVE_NORMAL7  = 32+7,       ///< PRIORITY_: above normal + 7
  HIGH           = 40,         ///< PRIORITY_: high
  HIGH1          = 40+1,       ///< PRIORITY_: high + 1
  HIGH2          = 40+2,       ///< PRIORITY_: high + 2
  HIGH3          = 40+3,       ///< PRIORITY_: high + 3
  HIGH4          = 40+4,       ///< PRIORITY_: high + 4
  HIGH5          = 40+5,       ///< PRIORITY_: high + 5
  HIGH6          = 40+6,       ///< PRIORITY_: high + 6
  HIGH7          = 40+7,       ///< PRIORITY_: high + 7
  REALTIME       = 48,         ///< PRIORITY_: realtime
  REALTIME1      = 48+1,       ///< PRIORITY_: realtime + 1
  REALTIME2      = 48+2,       ///< PRIORITY_: realtime + 2
  REALTIME3      = 48+3,       ///< PRIORITY_: realtime + 3
  REALTIME4      = 48+4,       ///< PRIORITY_: realtime + 4
  REALTIME5      = 48+5,       ///< PRIORITY_: realtime + 5
  REALTIME6      = 48+6,       ///< PRIORITY_: realtime + 6
  REALTIME7      = 48+7,       ///< PRIORITY_: realtime + 7
  ERROR          = -1,         ///< System cannot determine priority or illegal priority.    
  RESERVED       = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* LANG_A4ED407B_D298_46DA_B209_AEF00726AA6F */
