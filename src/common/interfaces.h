//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_INTERFACES_H__
#define __HAS_CPPMACROS_INTERFACES_H__

/*! \file interfaces.h
    \brief Interfaces for inheritance in C/C++
    
    Depend from:
     - /common/debug.h
*/

#include "../macroslib/src/macroslib.h"
#include "debug.h"


/* */
#ifdef __cplusplus


// Encapsulation

/*! 
   \brief [C++] Static (at macros time) comma separated list of inherits with public modifier of encapsulation.
   Used for short entry. Maximum inherit count is PP_VA_MAXARGS.
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPUBLIC_STATIC(...) PP_LIST_TERM_BEFORE_COMMAS_M(PP_SINGLE_TYPE_INHERIT, public, __VA_ARGS__)

/*! 
   \brief [C++] Static (at macros time) comma separated list of inherits with private modifier of encapsulation.
   Used for short entry. Maximum inherit count is PP_VA_MAXARGS.
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPRIVATE_STATIC(...) PP_LIST_TERM_BEFORE_COMMAS_M(PP_SINGLE_TYPE_INHERIT, private, __VA_ARGS__)

/*! 
   \brief [C++] Static (at macros time) comma separated list of inherits with protected modifier of encapsulation.
   Used for short entry. Maximum inherit count is PP_VA_MAXARGS.
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPROTECTED_STATIC(...) PP_LIST_TERM_BEFORE_COMMAS_M(PP_SINGLE_TYPE_INHERIT, protected, __VA_ARGS__)

/*! 
   \brief [C++] Short alias for IPUBLIC_STATIC
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPUBLIC(...) IPUBLIC_STATIC(__VA_ARGS__)

/*! 
   \brief [C++] Short alias for IPRIVATE_STATIC
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPRIVATE(...) IPRIVATE_STATIC(__VA_ARGS__)

/*! 
   \brief [C++] Short alias for IPROTECTED_STATIC
   \param __VA_ARGS__ classes to inherit
   \returns inherits list
*/
#define IPROTECTED(...) IPROTECTED_STATIC(__VA_ARGS__)


// Declaration

#define INTERFACE_TYPENAMES(class, ...) TYPES_LIST(typename class, __VA_ARGS__)
#define INTERFACE_MIRROR_ITEM(class, item)  typedef typename class::##item item ;
#define INTERFACE_MIRROR(class, ...) PP_ITERATE( INTERFACE_MIRROR_ITEM , class , __VA_ARGS__ )

// Iterator

#define ITERATOR_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator_category, \
                                    value_type, \
                                    difference_type, \
                                    pointer, \
                                    reference)
	
#define ITERATOR_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator_category, \
                                    value_type, \
                                    difference_type, \
                                    pointer, \
                                    reference)

#define IS_ITERATOR_TYPE(...)  TYPE_ASSERT(ITERATOR_INTERFACE(__VA_ARGS__))


// Iterable

#define ITERABLE_INTERFACE(...) typename __VA_ARGS__::iterator \
    typename __VA_ARGS__::const_iterator \
    typename __VA_ARGS__::reverse_iterator \
    typename __VA_ARGS__::const_reverse_iterator
	
#define ITERABLE_INTERFACE_MIRROR(...)\
	typedef typename __VA_ARGS__::iterator iterator; \
    typedef typename __VA_ARGS__::const_iterator const_iterator; \
    typedef typename __VA_ARGS__::reverse_iterator reverse_iterator; \
    typedef typename __VA_ARGS__::const_reverse_iterator const_reverse_iterator;

#define IS_ITERABLE_TYPE(...)  TYPE_ASSERT(ITERABLE_INTERFACE(__VA_ARGS__))


// Sizable

#define SIZABLE_INTERFACE(...) typename __VA_ARGS__::size_type
	
#define SIZABLE_INTERFACE_MIRROR(...) typedef typename __VA_ARGS__::size_type size_type;

#define IS_SIZABLE_TYPE(...)  TYPE_ASSERT(SIZABLE_INTERFACE(__VA_ARGS__))


// Pair

#define PAIR_INTERFACE(...) typename __VA_ARGS__::first_type, \
	typename __VA_ARGS__::second_type
	
#define PAIR_INTERFACE_MIRROR(...) typedef typename __VA_ARGS__::first_type first_type; \
	typedef typename __VA_ARGS__::second_type second_type;
	
#define IS_PAIR_INTERFACE(...) TYPE_ASSERT(PAIR_INTERFACE(__VA_ARGS__))


// Key-value

#define KEYVALUE_INTERFACE(...) typename __VA_ARGS__::key_type, \
	typename __VA_ARGS__::value_type
	
#define KEYVALUE_INTERFACE_MIRROR(...) typedef typename __VA_ARGS__::key_type key_type; \
	typedef typename __VA_ARGS__::value_type value_type;
	
#define IS_KEYVALUE_INTERFACE(...) TYPE_ASSERT(KEYVALUE_INTERFACE(__VA_ARGS__))

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_INTERFACES_H__