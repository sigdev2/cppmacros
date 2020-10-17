//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_UNUSED_H__
#define __HAS_CPPMACROS_UNUSED_H__

/*! \file unused.h
    \brief Unused operator
*/

#include "../macroslib/src/macroslib.h"


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
#define unused(...) PP_SEPARATE_LIST_M(PP_UNUSED_SINGLE, ; , __VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_UNUSED_H__