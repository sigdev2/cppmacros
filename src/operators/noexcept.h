//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_NOEXCEPT_H__
#define __HAS_CPPMACROS_NOEXCEPT_H__

/*! \file noexcept.h
    \brief Noexcept stub if not supported

    Depend from:
     - /common/versions.h
*/

#include "../macroslib/src/macroslib.h"
#include "../common/versions.h"


#ifdef CXX11
#    define NOEXCEPT(...) noexcept PP_SKIP_OR_CHOOSE( PP_COMMA_TEST( __VA_ARGS__ ) , ( __VA_ARGS__ ) )
#else // CXX11
/*!
   \brief Inserting noexcept modifier if is supported else remove his. Note that this is a functional macro.
   \param __VA_ARGS__ nothing or expression of noexcept
   \returns noexcept if supported
*/
#    define NOEXCEPT(...)
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_NOEXCEPT_H__