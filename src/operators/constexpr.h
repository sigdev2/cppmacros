//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CONSTEXPR_H__
#define __HAS_MACROS_LIB_CONSTEXPR_H__

/*! \file constexpr.h
    \brief Constexpr stub if not supported
*/

#ifdef CXX11
/*!
   \brief Inserting constexpr modifier if is supported else remove his.
   \returns сonstexpr if supported
*/
#    define CONSTEXPR constexpr
#else // CXX11
#    define CONSTEXPR
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_CONSTEXPR_H__