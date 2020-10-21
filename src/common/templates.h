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
*/

#include "../macroslib/src/macroslib.h"
#include "lang.h"


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
   \brief [C++] Leding type name with typename keyword and set void value
   \param __VA_ARGS__ type name
   \returns typename \a __VA_ARGS__ = void
*/
#define PP_TYPENAMES_LIST_VOID_HEAD(...) typename __VA_ARGS__ = void

/*! 
   \brief [C++] Сomma separated list of template arguments names marked typename keyword and set default value as void.
   Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ template arguments names
   \returns typenames list with void default values
*/
#define TYPENAMES_LIST_VOID(...) PP_MAP(PP_TYPENAMES_LIST_VOID_HEAD , __VA_ARGS__)

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


#ifdef CXX11
	template<typename ... T>
    struct TVoid {};
#else // CXX11
    template<TYPENAMES_LIST_VOID_N(PP_VA_MAXARGS)>
    struct TVoid {};
#endif // CXX11


#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_TEMPLATES_H__