//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FOR_H__
#define _HAS_MACROS_LIB_FOR_H__

/*! \file for.h
    \brief Foreach style operators for containers

    Depend from:
	 - /config.h
     - /common/versions.h
     - /preprocessor/utils.h
     - /preprocessor/variadic.h
*/

#include "../config.h"

#include "../common/versions.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

// fori
#define fori_4(start, len, type, name) for (const PP_SINGLE_TYPE( type ) & _s = ( start ),\
                                           const PP_SINGLE_TYPE( type ) & _l = ( len ),\
                                           PP_SINGLE_TYPE( type ) name = (_s < _l ? _s : _l),\
										   const PP_SINGLE_TYPE( type ) & _e = (_s > _l ? _s : _l);\
										   name < _e; ++ name )
#define fori_3(len, type, name) for ( PP_SINGLE_TYPE( type ) name = 0, const PP_SINGLE_TYPE( type ) & _l = len ; name < _l; ++ name )
#ifdef CXX11
#    define fori_2(len, name) fori_3(len, auto, name)
#else
#    define fori_2(len, name) fori_3(len, TSize, name)
#endif // C++11
#define fori_1(len) fori_2(len, i)
#define fori_0
/*!
   \brief Iterate from start to end of value with numeric type with default name 'i'. For compatibility it is better to use the full set of arguments
   \param start [optional, default 0, if 4 agruments (start, len, type, name)] start value from iterate
   \param type [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 3 agruments (len, type, name)] type of iterable value
   \param name [optional, default 'i', if 2 agruments (len, name)] name of variable
   \param len max value to iterate.
   \returns loop expression without brackets
*/
#define fori(...) PP_VA_FUNC(fori, __VA_ARGS__)

//rfori
#define rfori_4(start, len, type, name) for (const PP_SINGLE_TYPE( type ) & _s = ( start ),\
                                            const PP_SINGLE_TYPE( type ) & _l = ( len ),\
											PP_SINGLE_TYPE( type ) name = (_s > _l ? _s : _l),\
											const PP_SINGLE_TYPE( type ) & _e = (_s < _l ? _s : _l);\
											name > _e; -- name )
#define rfori_3(len, type, name) for ( PP_SINGLE_TYPE( type ) name = ( len ) - 1; name > 0; -- name )
#ifdef CXX11
#    define rfori_2(len, name) rfori_3(len, auto, name)
#else
#    define rfori_2(len, name) rfori_3(len, TSize, name)
#endif // C++11
#define rfori_1(len) rfori_2(len, i)
#define rfori_0
/*!
   \brief Iterate from end to start (reversed) of value with numeric type with default name 'i'. For compatibility it is better to use the full set of arguments
   \param start [optional, default 0, if 4 agruments (start, len, type, name)] start value from iterate
   \param type [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 3 agruments (len, type, name)] type of iterable value
   \param name [optional, default 'i', if 2 agruments (len, name)] name of variable
   \param len max value to iterate.
   \returns loop expression without brackets
*/
#define rfori(...) PP_VA_FUNC(rfori, __VA_ARGS__)

/*!
   \brief Iterate from start to end of value with numeric type with default name 'j'. For compatibility it is better to use the full set of arguments. Alias fori but default name is j, use in nested loops.
   \param start [optional, default 0, if 4 agruments (start, len, type, name)] start value from iterate
   \param type [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 3 agruments (len, type, name)] type of iterable value
   \param name [optional, default 'j', if 2 agruments (len, name)] name of variable
   \param len max value to iterate.
   \returns loop expression without brackets
*/
#define forj(len) fori(len, j)
/*!
   \brief Iterate from end to start (reversed) of value with numeric type with default name 'j'. For compatibility it is better to use the full set of arguments. Alias rfori but default name is j, use in nested loops.
   \param start [optional, default 0, if 4 agruments (start, len, type, name)] start value from iterate
   \param type [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 3 agruments (len, type, name)] type of iterable value
   \param name [optional, default 'j', if 2 agruments (len, name)] name of variable
   \param len max value to iterate.
   \returns loop expression without brackets
*/
#define rforj(len) rfori(len, j)

// forij
#define forij_0
#define forij_1(len)
#define forij_2(len1, len2) fori(len1) fori(len2, j)
#define forij_3(len1, len2, name) fori(len1, name) fori(len2, j)
#define forij_4(len1, len2, name1, name2) fori(len1, name1) fori(len2, name2)
#define forij_5(len1, len2, type, name1, name2) fori(len1, name1, type) fori(len2, name2)
#define forij_6(len1, len2, type1, name1, type2, name2) fori(len1, name1, type1) fori(len2, name2, type2)
/*!
   \brief Iterate nested loops on two variables with default names 'i' and 'j' from 0 to len (or len1 and len2) with numeric types. For compatibility it is better to use the full set of arguments
   \param type2 [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 6 agruments (len1, len2, type1, name1, type2, name2)] type of second iterable value
   \param type1 [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 6 agruments (len1, len2, type1, name1, type2, name2)] type of first iterable value
   \param type [optional, default 'auto' for C++11 and greater and 'TSize' for less than C++11, if 5 agruments (len1, len2, type, name1, name2)] type of iterable values
   \param name2 [optional, default 'j', if 4 agruments (len1, len2, name1, name2)] name of second variable
   \param name1 [optional, default 'i', if 4 agruments (len1, len2, name1, name2)] name of first variable
   \param name [optional, default 'i', if 3 agruments (len1, len2, name)] name of first variable
   \param len2 [optional, if 2 agruments (len1, len2)] max value to iterate second variable.
   \param len1 [optional, if 2 agruments (len1, len2)] max value to iterate first variable.
   \param len max value to iterate for two values.
   \returns nested loops expression without brackets
*/
#define forij(...) PP_VA_FUNC(forij, __VA_ARGS__)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FOR_H__