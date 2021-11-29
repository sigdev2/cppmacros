//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_FALLTHROUGH_H__
#define __HAS_CPPMACROS_FALLTHROUGH_H__

/*! \file fallthrough.h
    \brief Fallthrough stub if not supported

    Depend from:
     - /common/versions.h
*/

#include "../common/versions.h"


#ifdef CXX17
#   define FALLTHROUGH [[fallthrough]]; 
#else // CXX17
/*!
   \brief Inserting fallthrough attribute if is supported else remove his.
   \returns fallthrough if supported
*/
#   define FALLTHROUGH 
#endif // CXX17

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_FALLTHROUGH_H__