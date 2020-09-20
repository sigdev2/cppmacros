//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_ENUM_H__
#define __HAS_MACROS_LIB_ENUM_H__

/*! \file enum.h
    \brief Macros for define and process enums

    This macroses use enum handles defined as macro with list of enum elements:

        #define ENUM_HANDLE eItem1, eItem2, eItem3

    Depend from:
	 - /operators/switch.h
     - /common/debug.h
     - /preprocessor/utils.h
     - /preprocessor/variadic.h
*/

#include "switch.h"
#include "../common/debug.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef __cplusplus

/*!
   \brief [C++] Define enum with \a name
   \param name enum name.
   \param __VA_ARGS__ enum handle or items list.
   \returns enum definition
*/
#define DEFINE_ENUM(name, ...) enum name { __VA_ARGS__ };
/*!
   \brief [C++] Define enum with \a name with set numeric values starting from 0
   \param name enum name.
   \param __VA_ARGS__ enum handle or items list.
   \returns enum definition
*/
#define DEFINE_ENUM_NUM(name, ...) enum name {  PP_INVOKE( PP_VA_HEAD, (__VA_ARGS__) ) = 0 PP_COMMA PP_INVOKE( PP_VA_TAIL, (__VA_ARGS__) ) };

/*!
   \brief [C++] Generate return switch by RETCASE from \a name for return his name
   \param __VA_ARGS__ enum or other name
   \returns switch case from \a name which returns his name
*/
#define ENUM_MEMBER_TO_STR_RETCASE(...) RETCASE( __VA_ARGS__ , #__VA_ARGS__ )
/*!
   \brief [C++] Generate switch that process \a var as enum type and where every case return name of enum item as string. For example this use for functions thats generate translate id's
   \param var variable name contains enum value.
   \param __VA_ARGS__ enum handle or items list.
   \returns switch expression
*/
#define ENUM_TO_STR_RETCASE(var, ...) SWITCH_BEGIN ( var ) PP_INVOKE( PP_VA_LIST, ( ENUM_MEMBER_TO_STR_RETCASE, __VA_ARGS__) ) DEFCASE( _ass(false); return "<error>" ) SWITCH_END
/*!
   \brief [C++] Macro combinator, that define enum by \a name, and generate function of the form const char* <enum_type_name>_toString(<enum_type_name> v) that returns the names of the enum elements as strings
   \param name enum name.
   \param __VA_ARGS__ enum handle or items list.
   \returns define enum and his _toString frunction
*/
#define ENUM_OF_STRINGS(name, ...) DEFINE_ENUM_NUM(name, __VA_ARGS__ ) const char* name##_toString(name v) { ENUM_TO_STR_RETCASE( v , __VA_ARGS__) _ass(false); return "<error>"; };

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_ENUM_H__