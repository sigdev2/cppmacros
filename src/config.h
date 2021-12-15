//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_CONFIG_H__
#define __HAS_CPPMACROS_CONFIG_H__

/*! \file config.h
    \brief File with CppMacros configuration.
    
    Define base macros then used in library. If you need you may redefine this macros before include library.
*/


// Types

#ifdef _UNICODE
#    ifndef UNICODE
#        define UNICODE
#    endif // UNICODE
#endif // _UNICODE

#ifdef UNICODE
#    ifndef _UNICODE
#        define _UNICODE
#    endif // _UNICODE
#endif // UNICODE

#ifdef NO_UNICODE
#    undef UNICODE
#    undef _UNICODE
#endif // NO_UNICODE

#ifndef CHAR_TYPE
#    ifdef UNICODE
#        define CHAR_TYPE wchar_t
#    else
#        define CHAR_TYPE char
#    endif // UNICODE
#endif // CHAR_TYPE

#ifndef _T
#    ifdef UNICODE
#        define _T(c) L##c
#    else 
#        define _T(c) c
#    endif // UNICODE
#endif // _T

#ifndef TEXT
#    ifdef UNICODE
#        define TEXT(c) L##c
#    else 
#        define TEXT(c) c
#    endif // UNICODE
#endif // TEXT

#ifndef _TEXT
#    ifdef UNICODE
#        define _TEXT(c) L##c
#    else 
#        define _TEXT(c) c
#    endif // UNICODE
#endif // _TEXT

// operators/pointers.h

#ifndef NULL
#    ifdef __cplusplus
#        if __cplusplus > 199711L
#            define NULL nullptr
#        else // less C++11
#            include <cstddef>
#        #endif // C++11
#    else // __cplusplus
#        include <stddef>
#    endif // __cplusplus
#endif // NULL

#ifndef SIZE_TYPE
#    ifdef __cplusplus
#        include <cstddef>
#    else // __cplusplus
#        include <stddef>
#    endif // __cplusplus
#    define SIZE_TYPE size_t
#endif // SIZE_TYPE

// Collection

#ifndef STD_BASE_GET
#    if __cplusplus >= 201103L
#        include <iterator>
#        define STD_BASE_GET(collection, type) std::##type( collection )
#    else
#        define STD_BASE_GET(collection, type) ( collection ).##type()
#    endif // C++11
#endif // STD_BASE_GET

// Iterator

// operators/foreach.h

#ifndef STD_BEGIN_IT
#    define STD_BEGIN_IT(...) STD_BASE_GET(( __VA_ARGS__ ), begin )
#endif // STD_BEGIN_IT

#ifndef STD_CBEGIN_IT
#    define STD_CBEGIN_IT(...) STD_BASE_GET(( __VA_ARGS__ ), cbegin )
#endif // STD_CBEGIN_IT

#ifndef STD_RBEGIN_IT
#    define STD_RBEGIN_IT(...) STD_BASE_GET(( __VA_ARGS__ ), rbegin )
#endif // STD_RBEGIN_IT

#ifndef STD_CRBEGIN_IT
#    define STD_CRBEGIN_IT(...) STD_BASE_GET(( __VA_ARGS__ ), crbegin )
#endif // STD_CRBEGIN_IT

#ifndef STD_END_IT
#    define STD_END_IT(...) STD_BASE_GET(( __VA_ARGS__ ), end )
#endif // STD_END_IT

#ifndef STD_CEND_IT
#    define STD_CEND_IT(...) STD_BASE_GET(( __VA_ARGS__ ), cend )
#endif // STD_CEND_IT

#ifndef STD_REND_IT
#    define STD_REND_IT(...) STD_BASE_GET(( __VA_ARGS__ ), rend )
#endif // STD_REND_IT

#ifndef STD_CREND_IT
#    define STD_CREND_IT(...) STD_BASE_GET(( __VA_ARGS__ ), crend )
#endif // STD_CREND_IT


// Pairs

// operators/foreach.h

#ifndef STD_PAIR_VALUE
#    define STD_PAIR_VALUE(...) ( __VA_ARGS__ ).second
#endif // STD_PAIR_VALUE

#ifndef STD_PAIR_KEY
#    define STD_PAIR_KEY(...) ( __VA_ARGS__ ).first
#endif // STD_PAIR_KEY


// Functions

// operators/if.h

#ifndef IS_EMPTY
#    define IS_EMPTY(...) STD_BASE_GET(( __VA_ARGS__ ), empty )
#endif // IS_EMPTY

// use with operators/for.h

#ifndef LEN
#    define LEN(...) STD_BASE_GET(( __VA_ARGS__ ), size )
#endif // LEN


// Debug

// common/debug.h

#ifndef DEBUG_OUT
#    ifdef __cplusplus
#        define DEBUG_OUT std::cerr
#    else
#        define DEBUG_OUT stderr
#    endif // __cplusplus
#endif // DEBUG_OUT


// Translation

#ifndef TR
#    define TR(...) __VA_ARGS__
#endif // TR

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_CONFIG_H__
