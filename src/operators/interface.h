//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_INTERFACE_H__
#define __HAS_CPPMACROS_INTERFACE_H__

/*! \file interface.h
    \brief Macro for define interfaces as concepts with single inherit model or stub if not supported

    Depend from:
	 - /operators/concept.h
     - /common/versions.h
*/

#include <macroslib.h>
#include "../common/versions.h"
#include "../common/templates.h"
#include "../common/interfaces.h"
#include "concept.h"


// Operators

#ifdef CXX11
#    define interface template< typename T > CONCEPT
#    define multiinterface(...) template< TYPENAMES_LIST( __VA_ARGS__ ) > CONCEPT
#else
#    ifdef __cplusplus
#        define interface template< typename T > class
#        define multiinterface(...) template< TYPENAMES_LIST( __VA_ARGS__ ) > class
#    else // __cplusplus
         /*!
             \brief Inserting template define header with one argument T and concept modifier in version С++ greater than C++11. In version less than С++11 is just template class. In C his removed.
             \returns concept if supported, else template class or empty
         */
#        define interface
         /*!
             \brief Inserting template define header with many arguments names as \a __VA_ARGS__ and concept modifier  in version С++ greater than C++11. In version less than С++11 is just template class. In C his removed.
             \param __VA_ARGS__ type names for interface
             \returns concept if supported, else template class or empty
         */
#        define multiinterface(...)
#endif //  __cplusplus
#endif // CXX11

#ifdef CXX20
#    define interface_inherit(NAME) template< typename T > requires NAME < T >
#    define multiinterface_inherit(NAME, ...) template< TYPENAMES_LIST( __VA_ARGS__ ) > requires NAME < __VA_ARGS__ >
#else
#    ifdef CXX11
#        include <type_traits>
#        define interface_inherit(NAME) template<typename T, typename  = typename std::enable_if< NAME < T > >::type >
#        define multiinterface_inherit(NAME, ...) template< TYPENAMES_LIST( __VA_ARGS__ ) , typename  = typename std::enable_if< NAME < __VA_ARGS__ > >::type >
#    else // CXX11
         /*!
             \brief Inserting template define header with one argument T which corresponds to the concept \a NMAE, or remove his if not supported.
             \param NAME name of concept
             \returns template define header with one argument T
         */
#        define interface_inherit(NAME)
         /*!
             \brief Inserting template define header with many arguments names as \a __VA_ARGS__ which corresponds to the concept \a NMAE, or remove his if not supported
             \param NAME name of concept
             \param __VA_ARGS__ type names for interface
             \returns template define header with many arguments names
         */
#        define multiinterface_inherit(NAME, ...)
#    endif // CXX11
#endif // CXX20

#ifdef __DOXYGEN__
     /*! 
         \brief Macros defined if version of C++ support interfaces ( > С++11).
     */
#    define INTERFACE_IS_SUPPORTED
#endif // __DOXYGEN__
#ifdef CXX11
#    define INTERFACE_IS_SUPPORTED
#endif // CXX11

// Declare helpers

#ifdef CXX11
#    include <type_traits>
#    define DECL_INTERFACE(NAME, METHODS, ...) multiinterface( __VA_ARGS__ ) NAME  = METHODS ;
#    define DECL_INHERIT_INTERFACE(NAME, INHERIT, METHODS, ...) multiinterface( __VA_ARGS__ ) NAME  = ( INHERIT ) && ( METHODS ) ;
#    define INTERFACE_INHERITS(...) PP_SEPARATE_LIST( && , __VA_ARGS__ )
#    define INTERFACE_ITEMS(...) PP_SEPARATE_LIST( && , __VA_ARGS__ )
#    define INTERFACE_INHERITS_OR(...) PP_SEPARATE_LIST( || , __VA_ARGS__ )
#    define INTERFACE_ITEMS_OR(...) PP_SEPARATE_LIST( || , __VA_ARGS__ )
#    define INTERFACE_METHOD(BASE, RET_TYPE, NAME, ...) std::is_same<decltype(& BASE :: NAME ), RET_TYPE ( BASE ::*)( __VA_ARGS__ ) >::value
#    define INTERFACE_CONST_METHOD(BASE, RET_TYPE, NAME, ...) std::is_same<decltype(& BASE :: NAME ), RET_TYPE ( BASE ::*)( __VA_ARGS__ ) const >::value
#    define INTERFACE_VAR(BASE, TYPE, NAME) std::is_same<decltype(& BASE :: NAME ), TYPE BASE ::*>::value
#else // CXX11
#    ifdef __cplusplus
#        define DECL_INTERFACE(NAME, METHODS, ...) multiinterface( __VA_ARGS__ ) NAME { METHODS };
#        define DECL_INHERIT_INTERFACE(NAME, INHERIT, METHODS, ...) multiinterface( __VA_ARGS__ ) NAME : public INHERIT { METHODS ; };
#        define INTERFACE_INHERITS(...) PP_HEAD( __VA_ARGS__ ) PP_INSERT_COMMA() IPUBLIC( PP_TAIL( __VA_ARGS__ ) )
#        define INTERFACE_ITEMS(...) PP_SEPARATE_LIST( ; , __VA_ARGS__ )
#        define INTERFACE_INHERITS_OR(...) PP_HEAD( __VA_ARGS__ ) PP_INSERT_COMMA() IPUBLIC( PP_TAIL( __VA_ARGS__ ) )
#        define INTERFACE_ITEMS_OR(...) PP_SEPARATE_LIST( ; , __VA_ARGS__ )
#        define INTERFACE_METHOD(BASE, RET_TYPE, NAME, ...) virtual RET_TYPE NAME ( __VA_ARGS__ ) = 0
#        define INTERFACE_CONST_METHOD(BASE, RET_TYPE, NAME, ...) virtual RET_TYPE NAME ( __VA_ARGS__ ) const = 0
#        define INTERFACE_VAR(BASE, TYPE, NAME) TYPE NAME
#    else // __cplusplus
          /*!
             \brief Declarate interface with \a NAME and \a METHODS list builded with INTERFACE_METHODS, and list of types. If constexpr not supported then class will be defined. Empty in C.
             \param NAME name of interface
             \param METHODS list of methods builded with INTERFACE_METHODS
             \param __VA_ARGS__ list of used types
             \returns interface with \a NAME and \a METHODS list builded with INTERFACE_METHODS. If constexpr not supported then class will be defined. Empty in C.
         */
#        define DECL_INTERFACE(NAME, METHODS, ...)
         /*!
             \brief Declarate interface with \a NAME with \a INHERIT parent and \a METHODS list builded with INTERFACE_METHODS, and list of types. If constexpr not supported then class will be defined. Empty in C.
             \param NAME name of interface
             \param INHERIT parent interface or parents list builded with INTERFACE_INHERITS
             \param METHODS list of methods builded with INTERFACE_METHODS
             \param __VA_ARGS__ list of used types
             \returns interface with \a NAME and \a METHODS list declared with INTERFACE_METHODS. If constexpr not supported then class will be defined. Empty in C.
         */
#        define DECL_INHERIT_INTERFACE(NAME, INHERIT, METHODS, ...)
         /*!
             \brief Concatenate list of parents interfaces as INHERIT for DECL_INHERIT_INTERFACE. Empty in C.
             \param __VA_ARGS__ list interfaces of parents
             \returns сoncatenated list of parents or empty in C.
         */
#        define INTERFACE_INHERITS(...)
         /*!
             \brief Concatenate list of interface methods generated by INTERFACE_METHOD or INTERFACE_CONST_METHOD for DECL_INHERIT_INTERFACE and DECL_INTERFACE. Empty in C.
             \param __VA_ARGS__ list of interface methods
             \returns сoncatenated list of interface methods or empty in C.
         */
#        define INTERFACE_ITEMS(...)
         /*!
             \brief Disjunction of parents intefaces list as INHERIT for DECL_INHERIT_INTERFACE. Empty in C.
             \param __VA_ARGS__ list interfaces of parents
             \returns disjunction of parents intefaces list or empty in C.
         */
#        define INTERFACE_INHERITS_OR(...)
         /*!
             \brief Disjunction of interface methods list generated by INTERFACE_METHOD or INTERFACE_CONST_METHOD for DECL_INHERIT_INTERFACE and DECL_INTERFACE. Empty in C.
             \param __VA_ARGS__ list of interface methods
             \returns disjunction of interface methods list or empty in C.
         */
#        define INTERFACE_ITEMS_OR(...)
         /*!
             \brief Inserting test for method \a NAME with return type as \a RET_TYPE with arguments \a __VA_ARGS__ in \a BASE class in interface, or define virtual method if constexpr not supported. Empty in C.
             \param BASE class to interface test
             \param RET_TYPE return method type
             \param NAME name of method
             \param __VA_ARGS__ method types of arguments
             \returns method test or definition. Empty in C.
         */
#        define INTERFACE_METHOD(BASE, RET_TYPE, NAME, ...)
         /*!
             \brief Inserting test for const method \a NAME with return type as \a RET_TYPE with arguments \a __VA_ARGS__ in \a BASE class in interface, or define virtual const method if constexpr not supported. Empty in C.
             \param BASE class to interface test
             \param RET_TYPE return method type
             \param NAME name of const method
             \param __VA_ARGS__ method types of arguments
             \returns const method test or definition. Empty in C.
         */
#        define INTERFACE_CONST_METHOD(BASE, RET_TYPE, NAME, ...)
         /*!
             \brief Inserting test for variable with name \a NAME and type \a TYPE in \a BASE class in interface, or define this member if constexpr not supported. Empty in C.
             \param BASE class to interface test
             \param TYPE variable type
             \param NAME name of variable
             \returns variable with name \a NAME and type \a TYPE in \a BASE class in interface or definition. Empty in C.
         */
#        define INTERFACE_VAR(BASE, TYPE, NAME) TYPE NAME
#    endif // __cplusplus
#endif // CXX11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_INTERFACE_H__