//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_PROPERTY_H__
#define __HAS_CPPMACROS_PROPERTY_H__

/*! \file property.h
    \brief C++ class property macros.

    Depend from:
     - /common/lang.h"
*/

#include <macroslib.h>
#include "lang.h"


/* */
#ifdef __cplusplus

/*! 
   \brief [C++] Define property in private section of namespace with \a type and \a name with "__" prefix
   \param type type of property
   \param name name of property
   \returns property in private section with "__" prefix
*/
#define DEFINE_PROPERTY(type, name) private: PP_SINGLE_TYPE( type ) __##name;

/**/
#define SET_PROPERTY_5(class, type, name, setter, body) public: virtual PP_SINGLE_TYPE( class ) & setter ( const PP_SINGLE_TYPE( type ) & value ) { body ; return *this; }
#define SET_PROPERTY_4(class, type, name, setter) SET_PROPERTY_5(( class ), ( type ), name, setter, __##name = value )
#define SET_PROPERTY_3(class, type, name) SET_PROPERTY_4(( class ), ( type ), name, set_##name )
#define SET_PROPERTY_2(class, type)
#define SET_PROPERTY_1(class)
#define SET_PROPERTY_0
/*!
   \brief [C++] Generate set-function with \a setter name and \a body for property in \a class with \a type and \a name
   \param body [optional, default just set value, if 5 agruments (class, type, name, setter, body)] body of setter function
   \param setter [optional, default set_name, if 4 agruments (class, type, name, setter)] name of setter function
   \param name name of property
   \param type type of property
   \param class class of property
   \returns property setter
*/
#define SET_PROPERTY(...) PP_VA_FUNC(SET_PROPERTY, __VA_ARGS__)

/**/
#define GET_PROPERTY_4(type, name, getter, body) public: virtual const PP_SINGLE_TYPE( type ) & getter () { body ; }
#define GET_PROPERTY_3(type, name, getter) GET_PROPERTY_4(( type ), name, getter, return __##name )
#define GET_PROPERTY_2(type, name) GET_PROPERTY_3(( type ), name, get_##name)
#define GET_PROPERTY_1(type)
#define GET_PROPERTY_0
/*!
   \brief [C++] Generate get-function with \a getter name and \a body for property with \a type and \a name
   \param body [optional, default just return value, if 4 agruments (type, name, getter, body)] body of getter function
   \param getter [optional, default get_name, if 3 agruments (type, name, getter)] name of getter function
   \param name name of property
   \param type type of property
   \returns property getter
*/
#define GET_PROPERTY(...) PP_VA_FUNC(GET_PROPERTY, __VA_ARGS__)

/**/
#define PROPERTY_0
#define PROPERTY_1(class)
#define PROPERTY_2(class, type)
#define PROPERTY_3(class, type, name) DEFINE_PROPERTY(( type ), name) SET_PROPERTY3(( class ), ( type ), name) GET_PROPERTY2(( type ), name)
#define PROPERTY_4(class, type, name, getter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY3(( class ), ( type ), name) GET_PROPERTY3(( type ), name, getter)
#define PROPERTY_5(class, type, name, getter, setter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY4(( class ), ( type ), name, setter) GET_PROPERTY3(( type ), name, getter)
#define PROPERTY_6(class, type, name, getter, getbody, setter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY4(( class ), ( type ), name, setter) GET_PROPERTY4(( type ), name, getter, getbody)
#define PROPERTY_7(class, type, name, getter, getbody, setter, setbody) DEFINE_PROPERTY(( type ), name) SET_PROPERTY5(( class ), ( type ), name, setter, setbody) GET_PROPERTY4(( type ), name, getter, getbody)
/*!
   \brief [C++] Generate get-function and set-function with \a getter, \a setter name and \a body for property with \a type and \a name
   \param setbody [optional, default just set value, if 7 agruments (class, type, name, getter, getbody, setter, setbody)] body of setter function
   \param setter [optional, default set_name, if 6 agruments (class, type, name, getter, getbody, setter)] name of setter function
   \param getbody [optional, default just return value, if 5 agruments (type, name, getter, body)] body of getter function
   \param getter [optional, default get_name, if 4 agruments (class, type, name, getter)] name of getter function
   \param name name of property
   \param type type of property
   \param class class of property
   \returns define property
*/
#define PROPERTY(...) PP_VA_FUNC(PROPERTY, __VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_PROPERTY_H__