//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_TEMPLATES_H__
#define __HAS_CPPMACROS_TEMPLATES_H__

/*! \file templates.h
    \brief Macros for C++ templates
*/

#include "../macroslib/src/macroslib.h"
#include "../lang.h"


#ifdef __cplusplus

/*! 
   \brief PP_LIST_TERM_BEFORE_COMMAS alias for generate lists of variables with types comma separated. Maximum arguments count is PP_VA_MAXARGS.
   \param type type of variables
   \param __VA_ARGS__ variables names list
   \returns list of variables with types comma separated
*/
#define TYPES_LIST(type, ...) PP_LIST_TERM_BEFORE_COMMAS(type, __VA_ARGS__)

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

#define PUBLIC_INHERIT_HEAD( dummy , head ) PP_COMMA public PP_SINGLE_TYPE_INHERIT( head )
#define IPUBLIC_STATIC(...) public PP_SINGLE_TYPE_INHERIT(PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__))) PP_VA_FOR(PUBLIC_INHERIT_HEAD, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define IPUBLIC(...) IPUBLIC_STATIC(__VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_TEMPLATES_H__