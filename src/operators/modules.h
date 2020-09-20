//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_MODULES_H__
#define __HAS_MACROS_LIB_MODULES_H__

/*! \file modules.h
    \brief Macros for create c/c++ modules
*/

#ifdef _MSC_VER
//  Microsoft
/*!
   \brief Mark code for export if compiler is support
   \returns dllexport modifer if compiler is support
*/
#    define EXPORT __declspec(dllexport)
/*!
   \brief Mark code for import if compiler is support
   \returns dllimport modifer if compiler is support
*/
#    define IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
//  GCC
#    define EXPORT __attribute__((visibility("default")))
#    define IMPORT
#else
//  do nothing and hope for the best?
#    define EXPORT
#    define IMPORT
#    pragma warning Unknown dynamic link import/export semantics.
#endif

#ifdef __cplusplus
/*!
   \brief Begin block of C declarations module interface without C++ renaming. In C this macro is nothing
   \returns extern C with open braket
*/
#    define C_MODE_BEGIN extern "C" {
/*!
   \brief End block of C declarations module interface without C++ renaming. In C this macro is nothing
   \returns just close braket
*/
#    define C_MODE_END }
#else
#    define C_MODE_BEGIN
#    define C_MODE_END
#endif

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_MODULES_H__