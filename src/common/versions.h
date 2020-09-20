//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROSLIB_VERSIONS_H__
#define __HAS_MACROS_LIB_VERSIONS_H__

/*! \file versions.h
    \brief File with C/C++ compilers versions macros.
    
    Small memo for predefined macroses:

    OS and platforms:

    Linux and Linux-derived           __linux__
    Android                           __ANDROID__ (implies __linux__)
    Linux (non-Android)               __linux__ && !__ANDROID__
    Darwin (Mac OS X and iOS)         __APPLE__
    Akaros                            __ros__
    Windows                           _WIN32
    Windows 64 bit                    _WIN64 (implies _WIN32)
    NaCL                              __native_client__
    AsmJS                             __asmjs__
    Fuschia                           __Fuchsia__

    Compilers:

    Visual Studio       _MSC_VER, _MSC_FULL_VER
    gcc                 __GNUC__, __GNUC_MINOR__
    clang               __clang__, __clang_major__, __clang_minor__, __clang_patchlevel__
    emscripten          __EMSCRIPTEN__ (for asm.js and webassembly)
    MinGW32             __MINGW32__, __MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION
    MinGW-w64 32bit     __MINGW32__, __MINGW32_MAJOR_VERSION, __MINGW32_MINOR_VERSION
    MinGW-w64 64bit     __MINGW64__, __MINGW64_VERSION_MAJOR, __MINGW64_VERSION_MINOR

    Visual Studio version check:

    VS                        _MSC_VER   _MSC_FULL_VER
    1                         800
    3                         900
    4                         1000
    4                         1020
    5                         1100
    6                         1200
    6 SP6                     1200    12008804
    7                         1300    13009466
    7.1 (2003)                1310    13103077
    8 (2005)                  1400    140050727
    9 (2008)                  1500    150021022
    9 SP1                     1500    150030729
    10 (2010)                 1600    160030319
    10 (2010) SP1             1600    160040219
    11 (2012)                 1700    170050727
    12 (2013)                 1800    180021005
    14 (2015)                 1900    190023026
    14 (2015 Update 1)        1900    190023506
    14 (2015 Update 2)        1900    190023918
    14 (2015 Update 3)        1900    190024210
    15 (2017 Update 1 & 2)    1910    191025017
    15 (2017 Update 3)        1911    191125507
    15 (2017 Update 4)        1911    191125542
    15 (2017 Update 5)        1912    191225831
    15 (2017 Update 6)        1913    191326128
    15 (2017 Update 7)        1914    191426428
    15 (2017 Update 8)        1915
    15 (2017 Update 9)        1916    191627023
    16 (2019)                 1920    192027508
    16 (2019 Update 1)        1921    192127702
    16 (2019 Update 2)        1922    192227905
    16 (2019 Update 3)        1923    192328105
    16 (2019 Update 4)        1924    192428314
    16 (2019 Update 5)        1925    192528611
    16 (2019 Update 6)        1926
    16 (2019 Update 7)        1927

    Checking processor architecture in gcc:

    __i386__
    __x86_64__
    __arm__
    
    If in gcc defined __arm__, you can further check:

    __ARM_ARCH_5T__
    __ARM_ARCH_7A__
    __powerpc64__
    __aarch64__

    More predefined macroses you may check in https://sourceforge.net/projects/predef/
    For Visual Studio check this page https://docs.microsoft.com/ru-ru/cpp/preprocessor/predefined-macros?view=vs-2019
    And of course take a look at the standard С++ https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros
*/

#if __cplusplus >= 199711L
/*!
   \brief [C++] Defined if use C++98(1997) standard or grather
*/
#    define CXX98
/*!
   \brief [C++] Defined if use C++03(2003) standard or grather
*/
#    define CXX03
#endif

#if __cplusplus >= 201103L
/*!
   \brief [C++] Defined if use C++11(2011) standard or grather
*/
#    define CXX11
#endif

#if __cplusplus >= 201402L
/*!
   \brief [C++] Defined if use C++14(2014) standard or grather
*/
#    define CXX14
#endif

#if __cplusplus >= 201703L
/*!
   \brief [C++] Defined if use C++17(2017) standard or grather
*/
#    define CXX17
#endif

#if __cplusplus > 201703L
/*!
   \brief [C++] Defined if use C++20(2020) standard or grather
*/
#    define CXX20
#endif


#ifdef __cplusplus
#    ifndef TRIVIAL_ABI
#        ifdef __clang__
#            define TRIVIAL_ABI __attribute__((trivial_abi))
#        else // !__clang__
/*!
   \brief [C++] Inserting Trivial ABI attribute if is supported by compiler else remove his.
   The Trivial ABI attribute use for classes to help the compiler understand that the class has
   a trivial implementation of methods and is suitable for optimizing the generated code.

   Example:
       ...
           ~Class1() = defult; // trivial
       ...

       ...
           ~Class2() {} // non-trivial
       ...

       class TRIVIAL_ABI Class3
       ...
           ~Class3() {} // again trivial
       ...

   \returns Trivial ABI attribute if supported
*/
#            define TRIVIAL_ABI
#        endif // __clang__
#    endif // TRIVIAL_ABI
#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_VERSIONS_H__