//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_SWAP_H__
#define __HAS_CPPMACROS_SWAP_H__

/*! \file swap.h
    \brief Swap operator, for swap two variables without temporary variables

    Depend from:
     - /common/versions.h
*/

#include "../common/versions.h"


#ifndef swap

#ifdef CXX11
#    include <utility>
#    define swap(first, second) std::swap(( first ), ( second ))
#else // CXX11
/*!
   \brief Operator for swap two variables without temporary variables
   \param first first variable name, don't use expressions - in C/C++ < C++11 they are duplicated
   \param second second variable name, don't use expressions - in C/C++ < C++11 they are duplicated
   \returns variables with swapped values
*/
#    define swap(first, second) (( first ) ^= ( second ) ^=  ( first ) ^= ( second ))
#endif // CXX11

#endif // swap

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_SWAP_H__