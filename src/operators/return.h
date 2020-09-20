//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_RETURN_H__
#define __HAS_MACROS_LIB_RETURN_H__

/*! \file return.h
    \brief Short return operators

    Depend from:
     - /preprocessor/utils.h
*/

#include "../preprocessor/utils.h"

/*!
   \brief Safe do something and return void
   \param __VA_ARGS__ code.
   \returns return operator.
*/
#define return_void(...)  PP_DO_SAFE(__VA_ARGS__; return;)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_RETURN_H__