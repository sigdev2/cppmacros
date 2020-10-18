//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_POINTERS_H__
#define __HAS_CPPMACROS_POINTERS_H__

/*! \file pointers.h
    \brief Work with pointers

    Depend from:
     - /config.h
     - /operators/while.h
*/

#include "../config.h"
#include "while.h"


#ifdef __cplusplus

/*!
   \brief Safe delete pointer and set pointer as NULL
   \param pointer pointer, do not use expressions
   \returns delete or free operator
*/
#define DELETE(pointer) PP_DO_SAFE(delete pointer ; pointer = NULL)

#else // !__cplusplus

#include <stdlib.h>
#define DELETE(pointer) PP_DO_SAFE(free( pointer ); pointer = NULL)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_POINTERS_H__