//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_WHILE_H__
#define __HAS_MACROS_LIB_WHILE_H__

/*! \file while.h
    \brief Loop operators
*/

/*!
   \brief Loop working forever whith disable all warrings. May be used with do operator.
   \returns Loop operator
*/
#define forever while((void*)0, true) // note: disable warning, not for(;;) for use do { ... } forever
/*!
   \brief Loop working one iteration whith disable all warrings. Must be use with do operator.
   \returns Loop operator
*/
#define whileone while((void)0, 0) // note: disable warning

/*!
   \brief Loop operator iterate сontinues until the condition is true. May be used with do operator.
   \param __VA_ARGS__ condition.
   \returns Loop operator
*/
#define until(...) while(!( __VA_ARGS__ ))
/*!
   \brief Short alias for while. May be used with do operator.
   \param __VA_ARGS__ condition.
   \returns Loop operator
*/
#define loop(...) while( __VA_ARGS__ )

/*!
   \brief Call code from one or more operators in args, is anyway converted to single operator.
   \param __VA_ARGS__ code.
   \returns Expands to \a __VA_ARGS__ in single operator loop
*/
#define PP_DO_SAFE(...) do { __VA_ARGS__ ; } whileone

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_WHILE_H__