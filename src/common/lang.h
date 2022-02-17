//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_LANG_H__
#define __HAS_CPPMACROS_LANG_H__

/*! \file lang.h
    \brief Language depend utils. C/C++
    
    Depend from:
     - /operators/while.h
*/

#include <macroslib.h>
#include "../operators/while.h"


// FOR TYPES

/*! 
   \brief PP_LIST_TERM_BEFORE_COMMAS alias for generate lists of variables with types comma separated. Maximum arguments count is PP_VA_MAXARGS.
   \param type type of variables
   \param __VA_ARGS__ variables names list
   \returns list of variables with types comma separated
*/
#define TYPES_LIST(type, ...) PP_LIST_TERM_BEFORE_COMMAS(type, __VA_ARGS__)

/*! 
   \brief Сomma separated list of bool variables. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ variables names list
   \returns comma separated list of bool variables
*/
#define BOOL_LIST(...) TYPES_LIST(bool, __VA_ARGS__)

/*! 
   \brief Сomma separated list of bool variables with numerated names like _1, _2, _3 in \a NUM count and maximum as PP_VA_MAXARGS.
   \param NUM count of variables names
   \returns comma separated list of bool variables with numerated names like _1, _2, _3
*/
#define BOOL_LIST_N(NUM) TYPES_LIST(bool, PP_VA_GEN_A_N( NUM ))

/*! 
   \brief Сomma separated list of int variables. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ variables names list
   \returns comma separated list of int variables
*/
#define INT_LIST(...) TYPES_LIST(int, __VA_ARGS__)

/*! 
   \brief Сomma separated list of int variables with numerated names like _1, _2, _3 in \a NUM count and maximum as PP_VA_MAXARGS.
   \param NUM count of variables names
   \returns comma separated list of int variables with numerated names like _1, _2, _3
*/
#define INT_LIST_N(NUM) TYPES_LIST(int, PP_VA_GEN_A_N( NUM ))

/*! 
   \brief Сomma separated list of float variables. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ variables names list
   \returns comma separated list of float variables
*/
#define FLOAT_LIST(...) TYPES_LIST(float, __VA_ARGS__)

/*! 
   \brief Сomma separated list of float variables with numerated names like _1, _2, _3 in \a NUM count and maximum as PP_VA_MAXARGS.
   \param NUM count of variables names
   \returns comma separated list of float variables with numerated names like _1, _2, _3
*/
#define FLOAT_LIST_N(NUM) TYPES_LIST(float, PP_VA_GEN_A_N( NUM ))

/*! 
   \brief Define dummy variable by \a type name
   \param type type and name of variable
   \returns dummy variable by \a type name with _ prefix
*/
#define TYPE_VARIABLE(type) type _##type


// SINGLE TYPE

/* */
#ifdef __cplusplus

/* */
#define PP_FUNC_IF_BRACKETS_PP_HAS_BRACKETS
#define PP_HAS_BRACKETS(...) void (__VA_ARGS__)
#define PP_FUNC_IF_BRACKETS_void void
/*! 
   \brief [C++] Determines whether arguments are enclosed in parentheses, if so, converts them to the function type.
   This is used to convert type lists into a single type, but imposes some additional compilation costs.
   This mecros is just an example, use PP_UNPAREN
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type or function type.
*/
#define PP_FUNC_IF_BRACKETS(...) PP_CAT(PP_FUNC_IF_BRACKETS_, PP_HAS_BRACKETS __VA_ARGS__)

namespace __CppMacrosPrivate
{
    template<typename T> struct single_argument_type { typedef T type; };
    template<typename T, typename U> struct single_argument_type<T(U)> { typedef U type; };
}

/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates. May use for inherit classes.
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whithout typename keyword.
*/
#define PP_SINGLE_TYPE_INHERIT(...) __CppMacrosPrivate::single_argument_type< PP_UNPAREN(__VA_ARGS__) >::type

/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates for passing in parentheses complex types contains commas
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whith typename keyword.
*/
#define PP_SINGLE_TYPE(...) typename __CppMacrosPrivate::single_argument_type< PP_UNPAREN(__VA_ARGS__) >::type

#else // !__cplusplus

#define PP_SINGLE_TYPE_INHERIT(...) __VA_ARGS__
#define PP_SINGLE_TYPE(...) __VA_ARGS__

#endif // __cplusplus


// PP BOOL CONVERSION

/*!
   \brief Convertion PP_TRUE and PP_FALSE to C/C++ bool value
   \param c preprocessor bool like condition expression
   \returns true or false
*/
#define PP_TO_BOOL(c) PP_IF( c , true, false )


// UTILS

/*!
   \brief Call code from one or more operators in args, is anyway converted to single operator.
   \param __VA_ARGS__ code.
   \returns Expands to \a __VA_ARGS__ in single operator loop
*/
#define PP_DO_SAFE(...) do { __VA_ARGS__ ; } whileone

/*!
   \brief Assigment code \a y to variable with name \a x. Use in other macros.
   \param x variable name.
   \param y code to assigment.
   \returns \a x = ( \a y )
*/
#define PP_ASSIGMENT(x, y) x = ( y )


// HELPERS FOR IF OPERATORS

/*! 
   \brief Call code if bool is true. Use for write short and safe if-operator in macroses.
   \param x bool value.
   \param __VA_ARGS__ code.
   \returns Expands to if expression with \a as condition and return \a __VA_ARGS__ if true
*/
#define PP_CHECK_IF(x, ...) PP_DO_SAFE(const bool PP_VAR = ( x ); if ( PP_VAR ) { __VA_ARGS__ ; })

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_LANG_H__