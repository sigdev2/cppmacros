//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_PROPERTY_H__
#define __HAS_MACROS_LIB_PROPERTY_H__

#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef __cplusplus

#define DEFINE_PROPERTY(type, name) private: PP_SINGLE_TYPE( type ) __##name;

#define SET_PROPERTY_5(class, type, name, setter, body) public: virtual PP_SINGLE_TYPE( class ) & setter ( const PP_SINGLE_TYPE( type ) & name ) { body ; return *this; }
#define SET_PROPERTY_4(class, type, name, setter) SET_PROPERTY_5(( class ), ( type ), name, setter, __##name = name )
#define SET_PROPERTY_3(class, type, name) SET_PROPERTY_4(( class ), ( type ), name, set_##name )
#define SET_PROPERTY_2(class, type)
#define SET_PROPERTY_1(class)
#define SET_PROPERTY_0
#define SET_PROPERTY(...) PP_VA_FUNC(SET_PROPERTY, __VA_ARGS__)

#define GET_PROPERTY_4(type, name, getter, body) public: virtual const PP_SINGLE_TYPE( type ) & getter () { body ; }
#define GET_PROPERTY_3(type, name, getter) GET_PROPERTY_4(( type ), name, getter, return __##name )
#define GET_PROPERTY_2(type, name) GET_PROPERTY_3(( type ), name, get_##name)
#define GET_PROPERTY_1(type)
#define GET_PROPERTY_0
#define GET_PROPERTY(...) PP_VA_FUNC(GET_PROPERTY, __VA_ARGS__)

#define PROPERTY_0
#define PROPERTY_1(class)
#define PROPERTY_2(class, type)
#define PROPERTY_3(class, type, name) DEFINE_PROPERTY(( type ), name) SET_PROPERTY3(( class ), ( type ), name) GET_PROPERTY2(( type ), name)
#define PROPERTY_4(class, type, name, getter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY3(( class ), ( type ), name) GET_PROPERTY3(( type ), name, getter)
#define PROPERTY_5(class, type, name, getter, setter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY4(( class ), ( type ), name, setter) GET_PROPERTY3(( type ), name, getter)
#define PROPERTY_6(class, type, name, getter, getbody, setter) DEFINE_PROPERTY(( type ), name) SET_PROPERTY4(( class ), ( type ), name, setter) GET_PROPERTY4(( type ), name, getter, getbody)
#define PROPERTY_7(class, type, name, getter, getbody, setter, setbody) DEFINE_PROPERTY(( type ), name) SET_PROPERTY5(( class ), ( type ), name, setter, setbody) GET_PROPERTY4(( type ), name, getter, getbody)
#define PROPERTY(...) PP_VA_FUNC(PROPERTY, __VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_PROPERTY_H__