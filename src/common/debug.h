//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_DEBUG_H__
#define __HAS_MACROS_LIB_DEBUG_H__

/*! \file debug.h
    \brief Main file for MacrosLib include.
    
    Depend from:
	 - /common/templates.h
	 - /common/versions.h
     - /preprocessor/utils.h
*/

#include "templates.h"
#include "versions.h"
#include "../preprocessor/utils.h"


// messages

#if (defined DEBUG || defined _DEBUG)
#    include <assert.h>
/*!
   \brief Do code inside only if DEBUG or _DEBUG macro defined
   \param __VA_ARGS__ code
   \returns code inside
*/
#    define DO_DEBUG(...) PP_DO_SAFE( __VA_ARGS__ )
#else
#    define DO_DEBUG(...)
#endif // DEBUG || _DEBUG

#ifndef __FUNCTION_DECL__
#    if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#        define __FUNCTION_DECL__ __PRETTY_FUNCTION__
#    elif defined(__DMC__) && (__DMC__ >= 0x810)
#        define __FUNCTION_DECL__ __PRETTY_FUNCTION__
#    elif defined(__FUNCSIG__)
#        define __FUNCTION_DECL__ __FUNCSIG__
#    elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#        define __FUNCTION_DECL__ __FUNCTION__
#    elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#        define __FUNCTION_DECL__ __FUNC__
#    elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#        define __FUNCTION_DECL__ __func__
#    elif defined(__cplusplus) && (__cplusplus >= 201103)
#        define __FUNCTION_DECL__ __func__
#    else
/*!
   \brief Cross compilable macro for details about of the current called function
   \returns current called function definition string or "(unknown)" if not supported
*/
#       define __FUNCTION_DECL__ "(unknown)" // note: unsupported
#    endif // __FUNCTION_DECL__
#endif // __FUNCTION_DECL__

#ifdef __cplusplus
#    include <stdio.h>
/*!
   \brief Print arguments to DEBUG_OUT. Use DO_DEBUG
   \param __VA_ARGS__ to out
   \returns print to out or nothing
*/
#    define DEBUG_PRINT(...) DO_DEBUG(DEBUG_OUT << __VA_ARGS__ )
/*!
   \brief Print expression and his calcilated value to DEBUG_OUT. Use DO_DEBUG
   \param __VA_ARGS__ variable or expression
   \returns print to out or nothing
*/
#    define DEBUG_LOG(...) DEBUG_PRINT(#__VA_ARGS__ << " = [" << ( __VA_ARGS__ ) << "]\n")
/*!
   \brief Print expression, his calcilated value and calling function to DEBUG_OUT. Use DO_DEBUG
   \param __VA_ARGS__ variable or expression
   \returns print to out or nothing
*/
#    define DEBUG_TRACE(...) DEBUG_PRINT( ( __VA_ARGS__ ) << "\nCallstack: " << \
            #__VA_ARGS__ << __FUNCTION_DECL__ << '[' << __FILE__ << ':' << __LINE__ << "]\n" )
#else // !__cplusplus
#    include <stdio.h>
#    define DEBUG_PRINT(...) DO_DEBUG(fprintf(DEBUG_OUT, __VA_ARGS__ ))
#    define DEBUG_LOG(...) DEBUG_PRINT( "%s = [ %s ]\n", #__VA_ARGS__, ( __VA_ARGS__ ))
#    define DEBUG_TRACE(...) DEBUG_PRINT( "%s\nCallstack: %s [%s:%d]\n", ( __VA_ARGS__ ), \
            #__VA_ARGS__, __FUNCTION_DECL__, __FILE__, __LINE__,)
#endif // __cplusplus

#ifdef _WIN32
#    pragma comment( lib, "user32.lib" )
#    include <winuser.h>
/*!
   \brief If _WIN32 defined then display GUI message with arguments string, else just print arguments to DEBUG_OUT. Use DO_DEBUG
   \param __VA_ARGS__ string variable or value
   \returns display GUI message, or print to out, or nothing
*/
#    define DEBUG_MESSAGE(...) DO_DEBUG(MessageBoxA(0, ( __VA_ARGS__ ), "Debug", 0))
#else // !_WIN32
#    define DEBUG_MESSAGE(...) DEBUG_PRINT( ( __VA_ARGS__ ) )
#endif // _WIN32


// aliases

#ifndef _dbg
/*!
   \brief Do code inside only if DEBUG or _DEBUG macro defined. DO_DEBUG alias
   \param __VA_ARGS__ code
   \returns code inside
*/
#    define _dbg(...) DO_DEBUG(__VA_ARGS__)
#endif // _dbg

#ifndef _dprint
/*!
   \brief Print arguments to DEBUG_OUT. Use DO_DEBUG. DEBUG_PRINT alias
   \param __VA_ARGS__ to out
   \returns print to out or nothing
*/
#    define _dprint(...) DEBUG_PRINT(__VA_ARGS__)
#endif // _dprint

#ifndef _dlog
/*!
   \brief Print expression and his calcilated value to DEBUG_OUT. Use DO_DEBUG. DEBUG_LOG alias
   \param __VA_ARGS__ variable or expression
   \returns print to out or nothing
*/
#    define _dlog(...) DEBUG_LOG(__VA_ARGS__)
#endif // _dlog

#ifndef _trace
/*!
   \brief Print expression, his calcilated value and calling function to DEBUG_OUT. Use DO_DEBUG. DEBUG_TRACE alias
   \param __VA_ARGS__ variable or expression
   \returns print to out or nothing
*/
#    define _trace(...) DEBUG_TRACE(__VA_ARGS__)
#endif // _trace

#ifndef _dmsg
/*!
   \brief If _WIN32 defined then display GUI message with arguments string, else just print arguments to DEBUG_OUT. Use DO_DEBUG. DEBUG_MESSAGE alias
   \param __VA_ARGS__ string variable or value
   \returns display GUI message, or print to out, or nothing
*/
#    define _dmsg(...) DEBUG_MESSAGE(__VA_ARGS__)
#endif // _dmsg

// assert

/*!
   \brief Assert expression, throw assert if arguments is false. Use DO_DEBUG.
   \param __VA_ARGS__ bool variable or expression
   \returns assert or nothing
*/
#define _ass(...) DO_DEBUG(assert(__VA_ARGS__))
/*!
   \brief Assert expression, throw assert if arguments is true. Use DO_DEBUG.
   \param __VA_ARGS__ bool variable or expression
   \returns assert or nothing
*/
#define _assn(...) DO_DEBUG(assert(!(__VA_ARGS__)))


// revert if assert, assert if, assert return if

#define PP_ASSERT_CHECK_IF(x, ...) PP_DO_SAFE(const bool PP_VAR = ( x ); _ass(! PP_VAR ); if ( PP_VAR ) { __VA_ARGS__; })

/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_if(x, ...) PP_ASSERT_CHECK_IF( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_ifn(x, ...) PP_ASSERT_CHECK_IF(!( x ), __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_retif(x, ...) assert_if( x , return __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_retifn(x, ...) assert_ifn( x , return __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return true. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_trueif(...) assert_if(( __VA_ARGS__ ), return true )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return false. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_falseif(...) assert_if(( __VA_ARGS__ ), return false )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return true. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_trueifn(...) assert_ifn(( __VA_ARGS__ ), return true )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return false. Assert is use DO_DEBUG, but the condition remains.
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define assert_falseifn(...) assert_ifn(( __VA_ARGS__ ), return false )


// rif
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains. assert_if alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rif(x, ...) assert_if( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains. assert_ifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rifn(x, ...) assert_ifn( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rifret(x, ...) assert_retif( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rifnret(x, ...) assert_retifn( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return true. Assert is use DO_DEBUG, but the condition remains. assert_trueif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rtrueif(...) assert_trueif(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return false. Assert is use DO_DEBUG, but the condition remains. assert_falseif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rfalseif(...) assert_falseif(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return true. Assert is use DO_DEBUG, but the condition remains. assert_trueifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rtrueifn(...) assert_trueifn(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return false. Assert is use DO_DEBUG, but the condition remains. assert_falseifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define _rfalseifn(...) assert_falseifn(__VA_ARGS__)


// if asserts
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains. assert_if alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define ifa(x, ...) assert_if( x , __VA_ARGS__  )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and execude code in arguments. Assert is use DO_DEBUG, but the condition remains. assert_ifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define ifna(x, ...) assert_ifn( x , __VA_ARGS__  )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define return_ifa(x, ...) assert_retif( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define return_ifna(x, ...) assert_retifn( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define retifa(x, ...) assert_retif( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return value in arguments. Assert is use DO_DEBUG, but the condition remains. assert_retifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define retifna(x, ...) assert_retifn( x , __VA_ARGS__ )
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return true. Assert is use DO_DEBUG, but the condition remains. assert_trueif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define true_ifa(...) assert_trueif(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is true then throw assert and return false. Assert is use DO_DEBUG, but the condition remains. assert_falseif alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define false_ifa(...) assert_falseif(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return true. Assert is use DO_DEBUG, but the condition remains. assert_trueifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define true_ifna(...) assert_trueifn(__VA_ARGS__)
/*!
   \brief Condition expression with assert. If condition \a x is false then throw assert and return false. Assert is use DO_DEBUG, but the condition remains. assert_falseifn alias
   \param x bool condition
   \param __VA_ARGS__ code to execute if assert
   \returns condition expression with assert
*/
#define false_ifna(...) assert_falseifn(__VA_ARGS__)


// type assert

#ifdef __cplusplus

namespace __MacrosLibPrivate
{
#ifdef CXX11
	template<typename ... T>
    struct TVoid {};
#else // CXX11
    template<TYPENAMES_LIST_VOID_N(PP_VA_MAXARGS)>
    struct TVoid {};
#endif // CXX11
}
/*!
   \brief [C++] Check type existing. Use when inherit and with TVoid< TYPE > template cast to an empty structure, which is skipped on compilationand causes a compilation error if the type does not exist
   \param __VA_ARGS__ type
   \returns empty structure template
*/
#define TYPE_ASSERT(...) __MacrosLibPrivate::TVoid< __VA_ARGS__ >
/*!
   \brief [C++] Check type existing. Use when inherit and with TVoid< TYPE > template cast to an empty structure, which is skipped on compilationand causes a compilation error if the type does not exist. TYPE_ASSERT alias
   \param __VA_ARGS__ type
   \returns empty structure template
*/
#define TYPE_EXIST(...) TYPE_ASSERT(__VA_ARGS__)

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_DEBUG_H__