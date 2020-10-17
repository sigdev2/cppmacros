//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_LANG_H__
#define __HAS_CPPMACROS_LANG_H__

/*! \file lang.h
    \brief Language depend utils. C/C++
*/


/* */
#define PP_FUNC_IF_BRACKETS_PP_HAS_BRACKETS
#define PP_HAS_BRACKETS(...) void (__VA_ARGS__)
#define PP_FUNC_IF_BRACKETS_void void
/*! 
   \brief Determines whether arguments are enclosed in parentheses, if so, converts them to the function type. This is used to convert type lists into a single type.
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type or function type.
*/
#define PP_FUNC_IF_BRACKETS(...) PP_CAT(PP_FUNC_IF_BRACKETS_, PP_HAS_BRACKETS __VA_ARGS__)

/* */
#ifdef __cplusplus

namespace __MacrosLibPrivate
{
    template<typename T> struct single_argument_type { typedef T type; };
    template<typename T, typename U> struct single_argument_type<T(U)> { typedef U type; };
}
/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates. May use for inherit classes.
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whithout typename keyword.
*/
#define PP_SINGLE_TYPE_INHERIT(...) __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type

/*! 
   \brief [C++] Convert any types or type list to single literal for use in code. This is needed in some macros and templates for passing in parentheses complex types contains commas
   \param __VA_ARGS__ type or type list in parentheses.
   \returns type literal whith typename keyword.
*/
#define PP_SINGLE_TYPE(...) typename __MacrosLibPrivate::single_argument_type< PP_FUNC_IF_BRACKETS(__VA_ARGS__) >::type


#else // !__cplusplus

#define PP_SINGLE_TYPE_INHERIT(...) __VA_ARGS__
#define PP_SINGLE_TYPE(...) __VA_ARGS__

#endif // __cplusplus

/*!
   \brief Convertion PP_TRUE and PP_FALSE to C/C++ bool value
   \param c preprocessor bool like condition expression
   \returns true or false
*/
#define PP_TO_BOOL(c) PP_IF( c , true, false )

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_LANG_H__