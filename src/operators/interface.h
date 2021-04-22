//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_INTERFACE_H__
#define __HAS_CPPMACROS_INTERFACE_H__

/*! \file interface.h
    \brief Macro for define concepts with single inherit model or stub if not supported

    Depend from:
	 - /operators/concept.h
     - /common/versions.h
*/

#include "../common/versions.h"
#include "../common/templates.h"
#include "concept.h"


#ifdef CXX11
#    define interface template< typename T > CONCEPT
#    define multiinterface(...) template< TYPENAMES_LIST( __VA_ARGS__ ) > CONCEPT
#else
/*!
   \brief Inserting template define header with one argument T and concept modifier if is supported, else remove his.
   \returns concept if supported
*/
#    define interface
/*!
   \brief Inserting template define header with many arguments names as __VA_ARGS__ and concept modifier if is supported, else remove his.
   \param __VA_ARGS__ type names for concept
   \returns concept if supported
*/
#    define multiinterface(...)
#endif // CXX11

#ifdef __DOXYGEN__
     /*! 
         \brief Macros defined if version of C++ support interfaces.
     */
#    define INTERFACE_IS_SUPPORTED
#endif // __DOXYGEN__
#ifdef CXX11
#    define INTERFACE_IS_SUPPORTED
#endif // CXX11

#ifdef CXX20
#    define interface_inherit(NAME) template<typename T> requires NAME < T >
#else
#    ifdef CXX11
#        include <type_traits>
#        define interface_inherit(NAME) template<typename T, typename  = typename std::enable_if< NAME < T > >::type >
#    else // CXX11
         /*!
             \brief Inserting template define header with one argument T which corresponds to the concept \a NMAE, or remove his if not supported
             \param NAME name of concept
             \returns template define header with one argument T
         */
#        define interface_inherit(NAME)
#    endif // CXX11
#endif // CXX20

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_INTERFACE_H__