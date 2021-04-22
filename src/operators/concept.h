//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_CONCEPT_H__
#define __HAS_CPPMACROS_CONCEPT_H__

/*! \file concept.h
    \brief Concept constexpr stub if not supported

    Depend from:
	 - /operators/constexpr.h
     - /common/versions.h
*/

#include "../common/versions.h"
#include "constexpr.h"

#ifdef CXX20
#    define CONCEPT concept
#else
#    ifdef CXX11
#        define CONCEPT constexpr bool
#    else // CXX11
        /*!
            \brief Inserting concept modifier if is supported, else remove his. If standard of compiler greather C++11 but less then C++20 then replase to constexpr bool.
            \returns concept if supported
        */
#        define CONCEPT
#    endif // CXX11
#endif // CXX20

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_CONCEPT_H__