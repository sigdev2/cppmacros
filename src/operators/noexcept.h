//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_NOEXCEPT_H__
#define __HAS_MACROS_LIB_NOEXCEPT_H__

/*! \file noexcept.h
    \brief Noexcept stub if not supported

    Depend from:
     - /common/versions.h
     - /preprocessor/variadic.h
*/

#include "../common/versions.h"
#include "../preprocessor/variadic.h"

#ifdef CXX11
/*!
   \brief Inserting noexcept modifier if is supported else remove his. Note that this is a functional macro.
   \param __VA_ARGS__ nothing or expression of noexcept
   \returns noexcept if supported
*/
#    define NOEXCEPT(...) noexcept PP_VA_ARGS_LIST( __VA_ARGS__ )
#else // CXX11
#    define NOEXCEPT(...)
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_NOEXCEPT_H__