//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_SWITCH_H__
#define __HAS_MACROS_LIB_SWITCH_H__

/*! \file switch.h
    \brief Macros for write switch ... case ... default constructions  
    
    Depend from:
     - /preprocessor/variadic.h
*/

#include "../preprocessor/variadic.h"


/*!
   \brief Start switch block
   \param __VA_ARGS__ switch arguments variable
   \returns switch operator with open bracket
*/
#define SWITCH_BEGIN(...) switch(__VA_ARGS__) {
/*!
   \brief End switch block
   \returns close bracket
*/
#define SWITCH_END }

/*!
   \brief Case block
   \param key value
   \param __VA_ARGS__ code
   \returns Case with \a key as switch value and \a __VA_ARGS__ as body of code block
*/
#define CASE(key, ...) case ( key ): { ( __VA_ARGS__ ) break; }
/*!
   \brief Case block with return
   \param key value
   \param __VA_ARGS__ code
   \returns Case with \a key as switch value and \a __VA_ARGS__ as return value
*/
#define RETCASE(key, ...) case ( key ): return ( __VA_ARGS__ );

/* */
#define DEFCASE_0
#define DEFCASE_1(val) default: { ( val ); break; }
#define DEFCASE_2(key, val) default: case ( key ): { ( val ) break; }
/*!
   \brief Default case block with return
   \param key [optional, if 2 arguments (key, value)] add case with value
   \param val code
   \returns Default block with \a __VA_ARGS__ as code
*/
#define DEFCASE(...) PP_VA_FUNC(DEFCASE, __VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_SWITCH_H__