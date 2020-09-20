//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_LAMBDA_H__
#define __HAS_MACROS_LIB_LAMBDA_H__

/*! \file lambda.h
    \brief Macros for short write lambdas

    Depend from:
     - /common/versions.h
     - /preprocessor/variadic.h
*/

#ifdef CXX11
#    define LAMBDA_0
#    define LAMBDA_1(ret) []() { return ( ret ); }
#    define LAMBDA_2(arg, ret) [] arg { return ( ret ); }
#    define LAMBDA_3(scope, arg, ret) scope arg { return ( ret ); }
/*!
   \brief [C++11 and greater] Construct lambda function
   \param scope [optional, if 3 arguments (scope, arg, ret)] argument passing type in square brackets
   \param arg [optional, if 2 arguments (arg, ret)] arguments block in parentheses
   \param ret return value expression
   \returns noexcept if supported
*/
#    define LAMBDA(...) PP_VA_FUNC(LAMBDA, __VA_ARGS__)
#endif // C++11

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_LAMBDA_H__