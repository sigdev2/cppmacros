//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_CONSTEXPR_H__
#define __HAS_CPPMACROS_CONSTEXPR_H__

/*! \file constexpr.h
    \brief Constexpr stub if not supported

    Depend from:
     - /common/versions.h
*/

#include "../common/versions.h"


#ifdef CXX11
#    define CONSTEXPR constexpr
#else // CXX11
/*!
   \brief Inserting constexpr modifier if is supported else remove his.
   \returns сonstexpr if supported
*/
#    define CONSTEXPR
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_CONSTEXPR_H__