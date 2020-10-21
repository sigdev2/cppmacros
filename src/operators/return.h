//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_RETURN_H__
#define __HAS_CPPMACROS_RETURN_H__

/*! \file return.h
    \brief Short return operators

    Depend from:
     - /common/lang.h
*/

#include "../common/lang.h"


/*!
   \brief Safe do something and return void
   \param __VA_ARGS__ code.
   \returns return operator.
*/
#define return_void(...)  PP_DO_SAFE(__VA_ARGS__; return;)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_RETURN_H__