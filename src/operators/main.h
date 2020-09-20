//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_MAIN_H__
#define __HAS_MACROS_LIB_MAIN_H__

/*! \file main.h
    \brief Main function headers
*/

/*!
   \brief Base main function header without args
   \returns main function header
*/
#define MAIN_F int main()

/*!
   \brief Main function header with argc as arguments count and pointer to array of arguments argv.
   \returns main function header
*/
#define MAIN_ARGS int main (int argc, char** argv)

/*!
   \brief \brief Main function header with argc as arguments count, pointer to array of arguments argv and pointer to array of pointers to the execution environment variables.
   \returns main function header
*/
#define MAIN_ENV int main (int argc, char** argv, char** env)

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_MAIN_H__