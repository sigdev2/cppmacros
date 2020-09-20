//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_UNUSED_H__
#define __HAS_MACROS_LIB_UNUSED_H__

/*! \file unused.h
    \brief Unused operator

    Depend from:
     - /preprocessor/functional.h
*/

#include "../preprocessor/functional.h"

/*!
   \brief Disable warrings for single unused variable
   \param __VA_ARGS__ variable name
   \returns void casting variable
*/
#define PP_UNUSED_SINGLE(...) ((void) __VA_ARGS__ )
/*!
   \brief Disable warrings for unused variables
   \param __VA_ARGS__ unsused variables.
   \returns void casting variables.
*/
#define unused(...) PP_INVOKE( PP_VA_SEMICOLON_LIST, (PP_UNUSED_SINGLE, __VA_ARGS__ ) )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_UNUSED_H__