//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CONFIG_H__
#define __HAS_MACROS_LIB_CONFIG_H__

/*! \file config.h
    \brief File with MacrosLib configuration.
    
    Define base macros then used in library. If you need you may redefine this macros before include library.
*/

// Types

// operators/for.h
// operators/pointers.h

#ifndef NULL
#    include <cstddef>
#endif // NULL

#ifndef TSize
#    include <cstddef>
#    define TSize size_t
#endif // TSize


// Iterator

// operators/foreach.h

#ifndef STD_BASE_GET_IT
#    ifdef CXX11
#        include <iterator>
#        define STD_BASE_GET_IT(collection, type) std::##type( collection )
#    else
#        define STD_BASE_GET_IT(collection, type) ( collection ).##type()
#    endif // C++11
#endif // STD_BASE_GET_IT

#ifndef STD_BEGIN_IT
#    define STD_BEGIN_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), begin )
#endif // STD_BEGIN_IT

#ifndef STD_CBEGIN_IT
#    define STD_CBEGIN_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), cbegin )
#endif // STD_CBEGIN_IT

#ifndef STD_RBEGIN_IT
#    define STD_RBEGIN_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), rbegin )
#endif // STD_RBEGIN_IT

#ifndef STD_CRBEGIN_IT
#    define STD_CRBEGIN_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), crbegin )
#endif // STD_CRBEGIN_IT

#ifndef STD_END_IT
#    define STD_END_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), end )
#endif // STD_END_IT

#ifndef STD_CEND_IT
#    define STD_CEND_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), cend )
#endif // STD_CEND_IT

#ifndef STD_REND_IT
#    define STD_REND_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), rend )
#endif // STD_REND_IT

#ifndef STD_CREND_IT
#    define STD_CREND_IT(...) STD_BASE_GET_IT(( __VA_ARGS__ ), crend )
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
#    define IS_EMPTY(...) STD_BASE_GET_IT(( __VA_ARGS__ ), empty )
#endif // IS_EMPTY


// Functions

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
#endif // __HAS_MACROS_LIB_CONFIG_H__