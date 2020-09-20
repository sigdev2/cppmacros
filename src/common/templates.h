//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_TEMPLATES_H__
#define __HAS_MACROS_LIB_TEMPLATES_H__

/*! \file templates.h
    \brief Macros for C++ templates
    
    Depend from:
     - /preprocessor/variadic.h
     - /preprocessor/utils.h
*/

#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef __cplusplus

/*! 
   \brief [C++] Leding type name with typename keyword
   \param __VA_ARGS__ type name
   \returns typename \a __VA_ARGS__
*/
#define PP_TYPENAMES_LIST_HEAD( ... ) typename __VA_ARGS__
/*! 
   \brief [C++] Сomma separated list of types marked typename keyword. Maximum arguments count is PP_VA_MAXARGS.
   \param __VA_ARGS__ types or template arguments names
   \returns typenames list
*/
#define TYPENAMES_LIST(...) PP_INVOKE(PP_VA_COMMA_LIST, (PP_TYPENAMES_LIST_HEAD, __VA_ARGS__))
/*! 
   \brief [C++] Сomma separated list of types marked typename keyword with numerated types names like _1, _2, _3 in \a NUM count and maximum as PP_VA_MAXARGS.
   \param NUM count of types
   \returns typenames list
*/
#define TYPENAMES_LIST_N(NUM) TYPENAMES_LIST(PP_VA_GEN_A_N( NUM ))

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
#define TYPENAMES_LIST_VOID(...) PP_INVOKE(PP_VA_COMMA_LIST, (PP_TYPENAMES_LIST_VOID_HEAD, __VA_ARGS__))
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
#define VOIDS_LIST(...) PP_VA_REPEAT_COMMA(PP_APPLY, void, PP_INVOKE(PP_VA_SIZE, ( __VA_ARGS__ )))
/*!
   \brief [C++] Сomma separated list of void types with size by \a NUM. Used for generate for template without default values list of unused arguments. Maximum list size is PP_VA_MAXARGS.
   \param NUM count of template arguments
   \returns comma separated list of void
*/
#define VOIDS_LIST_N(NUM) PP_VA_REPEAT_COMMA(PP_APPLY, void, NUM)


#define PP_TYPES_LIST_HEAD(type, ...) type __VA_ARGS__
#define TYPES_LIST(type, ...) PP_INVOKE(PP_VA_COMMA_LIST, (PP_TYPENAMES_LIST_HEAD, __VA_ARGS__))
#define TEMPLATES_ARGS_HEAD_BOOL( dummy , head ) PP_COMMA bool head
#define TEMPLATES_ARGS_BOOL(...) bool PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__)) PP_VA_FOR(TEMPLATES_ARGS_HEAD_BOOL, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define TEMPLATES_ARGS_BOOL_N(NUM) TEMPLATES_ARGS_BOOL(PP_VA_GEN_A_N( NUM ))

#define PUBLIC_INHERIT_HEAD( dummy , head ) PP_COMMA public PP_SINGLE_TYPE_INHERIT( head )
#define IPUBLIC_STATIC(...) public PP_SINGLE_TYPE_INHERIT(PP_INVOKE(PP_VA_HEAD, (__VA_ARGS__))) PP_VA_FOR(PUBLIC_INHERIT_HEAD, 0, PP_INVOKE(PP_VA_TAIL, (__VA_ARGS__)))
#define IPUBLIC(...) IPUBLIC_STATIC(__VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_TEMPLATES_H__