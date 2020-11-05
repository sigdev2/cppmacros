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

/*! 
   \brief [C++] Return typename from \a ns namespace with \a name
   \param ns namespace
   \param name name of type
   \returns typename \a ns :: \a name
*/
#define INTERFACE_TYPENAMES_ITEM(ns, name)  typename ns::##name

/*! 
   \brief [C++] Generate of typenames list from \a ns namespace
   \param ns namespace
   \param __VA_ARGS__ types list
   \returns comma separated list of typenames from \a ns namespace
*/
#define INTERFACE_TYPENAMES(ns, ...) PP_MAP( INTERFACE_TYPENAMES_ITEM , __VA_ARGS__ )

/*! 
   \brief [C++] Create mirror typedef alias for type with \a name from \a ns namespace in another namespace.
   \param ns namespace
   \param name name of type
   \returns typedef typename \a ns :: \a name \a name ;
*/
#define INTERFACE_MIRROR_ITEM(ns, name)  typedef typename ns::##item item ;

/*! 
   \brief [C++] Generate of mirror typedefs list of types aliases from \a ns namespace in another namespace.
   \param ns namespace
   \param __VA_ARGS__ types list
   \returns comma separated list of typedefs aliases from \a ns namespace
*/
#define INTERFACE_MIRROR(ns, ...) PP_ITERATE( INTERFACE_MIRROR_ITEM , class , __VA_ARGS__ )


// Iterator

/*! 
   \brief [C++] Std::iterator types list for use in inherits
   \param __VA_ARGS__ namespace of types
   \returns comma separated list of std::iterator typenames
*/
#define ITERATOR_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator_category, \
                                    value_type, \
                                    difference_type, \
                                    pointer, \
                                    reference)

/*! 
   \brief [C++] Mirror typedefs of std::iterator types
   \param __VA_ARGS__ namespace of types
   \returns Mirror typedefs of std::iterator types
*/
#define ITERATOR_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator_category, \
                                    value_type, \
                                    difference_type, \
                                    pointer, \
                                    reference)

/*! 
   \brief [C++] Checking for the presence of std::iterator types in namespace.
   Compilation error if missing, analogue of C++20 concepts.
   \param __VA_ARGS__ namespace of types
   \returns types assert
*/
#define IS_ITERATOR_TYPE(...)  TYPE_ASSERT(ITERATOR_INTERFACE(__VA_ARGS__))


// Iterable

/*! 
   \brief [C++] List of possible C++ iterator types for use in inherits
   \param __VA_ARGS__ namespace of types
   \returns comma separated list of possible C++ iterator typenames
*/
#define ITERABLE_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator, \
                                    const_iterator, \
                                    reverse_iterator, \
                                    const_reverse_iterator)

/*! 
   \brief [C++] Mirror typedefs of possible C++ iterator types
   \param __VA_ARGS__ namespace of types
   \returns Mirror typedefs of possible C++ iterator types
*/
#define ITERABLE_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    iterator, \
                                    const_iterator, \
                                    reverse_iterator, \
                                    const_reverse_iterator)

/*! 
   \brief [C++] Checking for the presence of possible C++ iterator types in namespace.
   Compilation error if missing, analogue of C++20 concepts.
   \param __VA_ARGS__ namespace of types
   \returns types assert
*/
#define IS_ITERABLE_TYPE(...)  TYPE_ASSERT(ITERABLE_INTERFACE(__VA_ARGS__))


// Sizable

/*! 
   \brief [C++] C++ size type for use in inherits
   \param __VA_ARGS__ namespace of type
   \returns C++ size type
*/
#define SIZABLE_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    size_type)

/*! 
   \brief [C++] Mirror typedef of C++ size type
   \param __VA_ARGS__ namespace of type
   \returns Mirror typedef of C++ size type
*/
#define SIZABLE_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    size_type)

/*! 
   \brief [C++] Checking for the presence of C++ size type in namespace.
   Compilation error if missing, analogue of C++20 concepts.
   \param __VA_ARGS__ namespace of type
   \returns type assert
*/
#define IS_SIZABLE_TYPE(...)  TYPE_ASSERT(SIZABLE_INTERFACE(__VA_ARGS__))


// Pair

/*! 
   \brief [C++] Std::pair types list for use in inherits
   \param __VA_ARGS__ namespace of types
   \returns comma separated list of std::pair typenames
*/
#define PAIR_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    first_type, \
                                    second_type)

/*! 
   \brief [C++] Mirror typedefs of std::pair types
   \param __VA_ARGS__ namespace of types
   \returns Mirror typedefs of std::pair types
*/
#define PAIR_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    first_type, \
                                    second_type)

/*! 
   \brief [C++] Checking for the presence of std::pair types in namespace.
   Compilation error if missing, analogue of C++20 concepts.
   \param __VA_ARGS__ namespace of types
   \returns types assert
*/
#define IS_PAIR_INTERFACE(...) TYPE_ASSERT(PAIR_INTERFACE(__VA_ARGS__))


// Key-value

/*! 
   \brief [C++] Example of generate custom key-value types list for use in inherits
   \param __VA_ARGS__ namespace of types
   \returns comma separated list of custom key-value typenames
*/
#define KEYVALUE_INTERFACE(...) INTERFACE_TYPENAMES(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    key_type, \
                                    value_type)

/*! 
   \brief [C++] Example mirror typedefs of custom key-value types
   \param __VA_ARGS__ namespace of types
   \returns Mirror typedefs of custom key-value types
*/
#define KEYVALUE_INTERFACE_MIRROR(...) INTERFACE_MIRROR(PP_SINGLE_TYPE_INHERIT(__VA_ARGS__), \
                                    key_type, \
                                    value_type)

/*! 
   \brief [C++] Example checking for the presence of custom key-value types in namespace.
   Compilation error if missing, analogue of C++20 concepts.
   \param __VA_ARGS__ namespace of types
   \returns types assert
*/
#define IS_KEYVALUE_INTERFACE(...) TYPE_ASSERT(KEYVALUE_INTERFACE(__VA_ARGS__))

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_INTERFACES_H__