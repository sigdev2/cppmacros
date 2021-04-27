//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_TEMPLATES_H__
#define __HAS_CPPMACROS_TEMPLATES_H__

/*! \file templates.h
    \brief Macros for C++ templates

    Depend from:
     - /common/lang.h"
     - /common/versions.h"
*/

#include "../macroslib/src/macroslib.h"
#include "lang.h"
#include "versions.h"


/* */
#ifdef __cplusplus

/*! 
   \brief [C++] Сomma separated list of types marked typename keyword. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ types or template arguments names
   \returns typenames list
*/
#define TYPENAMES_LIST(...) TYPES_LIST(typename, __VA_ARGS__)

/*! 
   \brief [C++] Сomma separated list of types marked typename keyword with numerated types names like _1, _2, _3 in \a NUM count and maximum as PP_VA_MAXARGS.
   \param NUM count of types
   \returns typenames list
*/
#define TYPENAMES_LIST_N(NUM) TYPES_LIST(typename, PP_VA_GEN_A_N( NUM ))

/*!
   \brief [C++] Assigment void to variable with name \a __VA_ARGS__. Use in other macros.
   \param __VA_ARGS__ variable name
   \returns \a __VA_ARGS__ = void
*/
#define PP_ASSIGMENT_VOID( ... ) __VA_ARGS__ = void

/*! 
   \brief [C++] Сomma separated list of template arguments names marked typename keyword and set default value as void.
   Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ template arguments names
   \returns typenames list with void default values
*/
#define TYPENAMES_LIST_VOID(...) PP_LIST_TERM_BEFORE_COMMAS_M(PP_ASSIGMENT_VOID, typename, __VA_ARGS__)

/*! 
   \brief [C++] Сomma separated list of types marked typename keyword with numerated types names like _1, _2, _3 in \a NUM count with maximum as PP_VA_MAXARGS and set default value as void.
   \param NUM count of types
   \returns typenames list with void default values
*/
#define TYPENAMES_LIST_VOID_N(NUM) TYPENAMES_LIST_VOID(PP_VA_GEN_A_N( NUM ))

/*!
   \brief [C++] Сomma separated list of void types with size by size of arguments list. Used for generate by template arguments without default values list of unused arguments. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ any arguments
   \returns comma separated list of void
*/
#define VOIDS_LIST(...) PP_REPEAT(void, PP_VA_SIZE( __VA_ARGS__ ))

/*!
   \brief [C++] Сomma separated list of void types with size by \a NUM. Used for generate for template without default values list of unused arguments. Maximum list size is PP_VA_MAXARGS.
   \param NUM count of template arguments
   \returns comma separated list of void
*/
#define VOIDS_LIST_N(NUM) PP_REPEAT(void, NUM)

#define VARIADIC_TEMPLATE_UNPACK_0
#ifdef CXX11
#    define VARIADIC_TEMPLATE_UNPACK_1( NAME ) NAME...
#    define VARIADIC_TEMPLATE_UNPACK_2( NAME, COUNT ) NAME...
#else // CXX11
#    define VARIADIC_TEMPLATE_UNPACK_1( NAME ) PP_MAP(PP_CAT, PP_PREPEND_ALL( NAME , PP_VA_GEN_A_N(PP_VA_MAXARGS)))
#    define VARIADIC_TEMPLATE_UNPACK_2( NAME, COUNT ) PP_MAP(PP_CAT, PP_PREPEND_ALL( NAME , PP_VA_GEN_A_N(COUNT)))
#endif // CXX11
/*!
   \brief [C++] Unpack variadic template arguments as list.
   If a version of the standard lower than C++11, then not supported unpack as arguments of code template,
   only as list with commas limited by count as PP_VA_MAXARGS
   \param NAME name of template arguments set
   \param COUNT [optional, default PP_VA_MAXARGS] in c++ version less than c++1 is maximum of variadic template arguments count, is necessary in order to be able to generate sequences of a given length, for example, for another macro of limited PP_VA_MAXARGS
   \returns unpacked variadic template arguments
*/
#define VARIADIC_TEMPLATE_UNPACK(...) PP_VA_FUNC(VARIADIC_TEMPLATE_UNPACK, __VA_ARGS__)

/*!
   \brief [C++] Definition header of a variadic template with support version of the standard lower than C++11.
   If a version of the standard lower than C++11, then the maximum number of arguments is PP_VA_MAXARGS,
   as well unpacking the template arguments is limited functional of VARIADIC_TEMPLATE_UNPACK macro.
   \param __VA_ARGS__ name of template arguments set
   \returns template definition header
*/
#define VARIADIC_TEMPLATE( ... ) template<TYPENAMES_LIST_VOID(VARIADIC_TEMPLATE_UNPACK( __VA_ARGS__ )) >


#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_TEMPLATES_H__