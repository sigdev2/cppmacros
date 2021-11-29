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
     - /common/lang.h
     - /common/versions.h
*/

#include "../config.h"
#include "../common/lang.h"
#include "../common/versions.h"


#ifdef __cplusplus

#ifdef CXX11
#    define DELETE(pointer) PP_DO_SAFE(delete pointer ; pointer = NULL)
#else // CXX11
/*!
   \brief Safe delete pointer and set pointer as NULL
   \param pointer pointer, do not use expressions
   \returns delete or free operator
*/
#    define DELETE(pointer) PP_DO_SAFE(delete pointer ; pointer = nullptr)
#endif // CXX11

#else // !__cplusplus

#include <stdlib.h>
#define DELETE(pointer) PP_DO_SAFE(free( pointer ); pointer = NULL)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_POINTERS_H__