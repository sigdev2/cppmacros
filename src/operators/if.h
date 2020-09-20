//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_IF_H__
#define __HAS_MACROS_LIB_IF_H__

/*! \file if.h
    \brief If operators

    Depend from:
     - /config.h
     - /preprocessor/utils.h
*/

#include "../config.h"

#include "../preprocessor/utils.h"

/*!
   \brief If not operator
   \param __VA_ARGS__ condition.
   \returns if expression without brackets
*/
#define ifn(...) if (!( __VA_ARGS__ ))
/*!
   \brief Else if operator
   \param __VA_ARGS__ condition.
   \returns if expression without brackets
*/
#define elif(...) else if (__VA_ARGS__)
/*!
   \brief Else if not operator
   \param __VA_ARGS__ condition.
   \returns if expression without brackets
*/
#define elifn(...) else if (!( __VA_ARGS__ ))
/*!
   \brief Else if operator. elif alias
   \param __VA_ARGS__ condition.
   \returns if expression without brackets
*/
#define elseif(...) else if (__VA_ARGS__)
/*!
   \brief Else if not operator. elifn alias
   \param __VA_ARGS__ condition.
   \returns if expression without brackets
*/
#define elseifn(...) else if (!( __VA_ARGS__ ))

/*!
   \brief If empty operator. Use IS_EMPTY macro to check empty state
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define ifempty(...) if (IS_EMPTY( __VA_ARGS__ ))
/*!
   \brief If not empty operator. Use IS_EMPTY macro to check empty state
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define ifnempty(...) if (!IS_EMPTY( __VA_ARGS__ ))
/*!
   \brief Else if empty operator. Use IS_EMPTY macro to check empty state
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define elifempty(...) else if (IS_EMPTY(__VA_ARGS__))
/*!
   \brief Else if not empty operator. Use IS_EMPTY macro to check empty state
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define elifnempty(...) else if (!IS_EMPTY(__VA_ARGS__ ))
/*!
   \brief Else if empty operator. Use IS_EMPTY macro to check empty state. elifempty alias
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define elseifempty(...) else if (IS_EMPTY(__VA_ARGS__))
/*!
   \brief Else if not empty operator. Use IS_EMPTY macro to check empty state. elifnempty alias
   \param __VA_ARGS__ expression.
   \returns if expression without brackets
*/
#define elseifnempty(...) else if (!IS_EMPTY(__VA_ARGS__ ))

/*!
   \brief If value is empty return default value, else return value. Use IS_EMPTY macro to check empty state
   \param val variable.
   \param __VA_ARGS__ default value expression
   \returns if ... else expression
*/
#define defval(val, ...) (IS_EMPTY( val ) ? ( val ) : __VA_ARGS__)

/*! 
   \brief Call code if bool is true. Use for write short and safe if-operator in macroses.
   \param x bool value.
   \param __VA_ARGS__ code.
   \returns Expands to \a x \a __VA_ARGS__
*/
#define PP_CHECK_IF(x, ...) PP_DO_SAFE(const bool PP_VAR = ( x ); if ( PP_VAR ) { __VA_ARGS__ ; })

/*!
   \brief If \a x is true then call return operator with value
   \param x condition.
   \param __VA_ARGS__ return value
   \returns if expression
*/
#define return_if(x, ...) PP_CHECK_IF( x , return __VA_ARGS__)
/*!
   \brief If \a x is false then call return operator with value
   \param x condition.
   \param __VA_ARGS__ return value
   \returns if expression
*/
#define return_ifn(x, ...) PP_CHECK_IF(!( x ), return __VA_ARGS__)
/*!
   \brief If \a x is true then call return operator with value. return_if alias
   \param x condition.
   \param __VA_ARGS__ return value
   \returns if expression
*/
#define retif(x, ...) return_if( x , __VA_ARGS__)
/*!
   \brief If \a x is false then call return operator with value. return_ifn alias
   \param x condition.
   \param __VA_ARGS__ return value
   \returns if expression
*/
#define retifn(x, ...) return_ifn( x , __VA_ARGS__)

/*!
   \brief If arguments is true then call return operator with true value
   \param __VA_ARGS__ condition.
   \returns if expression
*/
#define true_if(...) return_if(( __VA_ARGS__ ), true)
/*!
   \brief If arguments is true then call return operator with false value
   \param __VA_ARGS__ condition.
   \returns if expression
*/
#define false_if(...) return_if(( __VA_ARGS__ ), false)
/*!
   \brief If arguments is false then call return operator with true value
   \param __VA_ARGS__ condition.
   \returns if expression
*/
#define true_ifn(...) return_ifn(( __VA_ARGS__ ), true)
/*!
   \brief If arguments is false then call return operator with false value
   \param __VA_ARGS__ condition.
   \returns if expression
*/
#define false_ifn(...) return_ifn(( __VA_ARGS__ ), false)

// todo: ifor, ifand

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_IF_H__