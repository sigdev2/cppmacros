//
//
/////////////////////////////////////////////////////////////////////////////


#pragma once
#ifndef __HAS_CPPMACROS_LIB_H__
#define __HAS_CPPMACROS_LIB_H__

/*! \file cppmacros.h
    \brief Main file for CppMacros include.
    
    The file contains includes of all library files and macros for managing them. If is included, then macros __HAS_CPPMACROS_LIB_H__ is defined
*/

#include <macroslib.h>
#include "config.h"


#ifdef __DOXYGEN__
/*! 
   \brief Macros for disable include operators section. But if other files depend for them, then ignored.
   Operators section contain macros with operators, modifiers and attributes, change the syntax and perception of the language.
*/
#define CPPMACROS_NO_OPERATORS
#endif // __DOXYGEN__
#ifndef CPPMACROS_NO_OPERATORS
#include "operators/cache.h"
#include "operators/concept.h"
#include "operators/constexpr.h"
#include "operators/enum.h"
#include "operators/fallthrough.h"
#include "operators/for.h"
#include "operators/foreach.h"
#include "operators/if.h"
#include "operators/interface.h"
#include "operators/lambda.h"
#include "operators/main.h"
#include "operators/modules.h"
#include "operators/noexcept.h"
#include "operators/pointers.h"
#include "operators/return.h"
#include "operators/swap.h"
#include "operators/switch.h"
#include "operators/unused.h"
#include "operators/while.h"
#endif // CPPMACROS_NO_OPERATORS

#ifdef __DOXYGEN__
/*! 
   \brief Macros for disable include code common macroses section. But if other files depend for them, then ignored.
   Common section contain complex macros for simplify evreyday tasks.
*/
#define CPPMACROS_NO_COMMON
#endif // __DOXYGEN__
#ifndef CPPMACROS_NO_COMMON
#include "common/containers.h"
#include "common/debug.h"
#include "common/interfaces.h"
#include "common/property.h"
#include "common/templates.h"
#include "common/lang.h"
#include "common/versions.h"
#endif // CPPMACROS_NO_COMMON

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_LIB_H__