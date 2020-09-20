//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_CACHE_H__
#define __HAS_MACROS_LIB_CACHE_H__

/*! \file cache.h
    \brief Macros for simplae function caching

    Depend from:
	 - /operators/if.h
     - /preprocessor/utils.h
*/

#ifdef __cplusplus

#include <unordered_map>

#ifndef CACHE_STORAGE_NAME
/*!
   \brief [C++] If not defined then is name of variable for cache storage in function. May redefine (with #undef) to change name
   \returns name of variable
*/
#    define CACHE_STORAGE_NAME __static_hash
#endif // CACHE_STORAGE_NAME

/*!
   \brief [C++] Inserted at the beginning of the function and declare satatic key-value storage (see CACHE_STORAGE_NAME), and also checks the presence of the cached value
   \param IN_TYPE type of function argument.
   \param OUT_TYPE return function type.
   \param IN_VAL function argument variable.
   \returns static key-value storage and value checking
*/
#define CACHE_FUNC(IN_TYPE, OUT_TYPE, IN_VAL) static std::unordered_map<PP_SINGLE_TYPE( IN_TYPE ), PP_SINGLE_TYPE( OUT_TYPE ) >  CACHE_STORAGE_NAME ; \
    std::unordered_map<PP_SINGLE_TYPE( IN_TYPE ), PP_SINGLE_TYPE( OUT_TYPE ) >::iterator it = ( CACHE_STORAGE_NAME ).find(IN_VAL); \
    retifn(it == ( CACHE_STORAGE_NAME ).end(), *it)

/*!
   \brief [C++] Inserted at the ending of the function for set output value to satatic key-value storage and then return this value
   \param IN function argument variable.
   \param OUT calculated function value to store.
   \returns storing function calculation and return his result
*/
#define RETURN_CACHE_FUNC(IN, OUT) ( CACHE_STORAGE_NAME )[IN] = OUT; return OUT;

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_CACHE_H__