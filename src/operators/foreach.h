//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_MACROS_LIB_FOREACH_H__
#define __HAS_MACROS_LIB_FOREACH_H__

/*! \file foreach.h
    \brief Foreach style operators for containers

    Depend from:
	 - /config.h
     - /common/versions.h
     - /preprocessor/utils.h
     - /preprocessor/variadic.h
*/

#include "../config.h"

#include "../common/versions.h"
#include "../preprocessor/utils.h"
#include "../preprocessor/variadic.h"

#ifdef CXX11
/*!
   \brief Iterate from begin to end iterators. For compatibility it is better to use the full set of arguments
   \param name iterator name.
   \param begin begin iterator
   \param end end iterator
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#   define forrange(name, begin, end, ...) for ( auto name = ( begin ); name != ( end ); ++( name ))
/*!
   \brief Iterate from end to begin (reversed) iterators. For compatibility it is better to use the full set of arguments
   \param name iterator name.
   \param begin begin iterator
   \param end end iterator
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#   define rforrange(name, begin, end, ...) for ( auto name = ( end ); ( name )-- != ( begin ); )
#else
#   define forrange(name, begin, end, ...) for ( PP_SINGLE_TYPE(__VA_ARGS__) name = ( begin );  name != ( end ); ++( name ))
#   define rforrange(name, begin, end, ...) for ( PP_SINGLE_TYPE(__VA_ARGS__) name = ( end ); ( name )-- != ( begin ); )
#endif // C++11

#ifdef __cplusplus

namespace __MacrosLibPrivate
{
	template<typename IT>
	class MultiIterator : public IT
	{
	public:
	    MacrosIt(const IT& _begin, const IT& end, bool reverse = false)
		    : IT(reverse ? _end : _begin), begin(_begin), end(_end) {}
	    typedef IT TIt;
		IT begin;
		IT end;
	};

	template<typename T>
	MultiIterator<typename T::iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::iterator>(STD_BEGIN_IT(collection),
		                                STD_END_IT(collection),
										reverse); }
	template<typename T>
	MultiIterator<typename T::const_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::const_iterator>(STD_CBEGIN_IT(collection),
		                                    STD_CEND_IT(collection),
											reverse); }
	template<typename T>
	MultiIterator<typename T::reverse_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::reverse_iterator>(STD_RBEGIN_IT(collection),
		                                    STD_REND_IT(collection),
											reverse); }
	template<typename T>
	MultiIterator<typename T::const_reverse_iterator> _make(const T& collection, bool reverse = false)
	    { return MultiIterator<T::const_reverse_iterator>(STD_CRBEGIN_IT(collection),
		                                    STD_CREND_IT(collection),
											reverse); }
}

// forit
#ifdef CXX11
#    define forit_3(collection, type, name) for (auto name  = __MacrosLibPrivate::_make( collection ); name != ( name ).end; ++ name )
#    define forit_2(collection, name) forit_3(collection, NULL, name)
#    define forit_1(collection) forit_2(collection, it)
#else
#    define forit_3(collection, type, name) for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE( type )> name = __MacrosLibPrivate::_make( collection ); name != ( name ).end; ++ name )
#    define forit_2(collection, type) forit_3(collection, ( type ), it)
#    define forit_1(collection)
#endif // C++11
#define forit_0
/*!
   \brief [C++] Iterate collection with iterator. For compatibility it is better to use the full set of arguments
   \param collection collection object
   \param type [if 2 arguments (collection, type) for less than C++11 and if 3 arguments (collection, type, name)] type of iterator
   \param name [if 2 arguments (collection, name) for C++11 and greater and if 3 arguments (collection, type, name)] iterator name
   \returns loop expression without brackets
*/
#define forit(...) PP_VA_FUNC(forit, __VA_ARGS__)

// rfroit
#ifdef CXX11
#    define rforit_3(collection, type, name) for (auto name  = __MacrosLibPrivate::_make( collection ); ( name )-- != ( name ).begin; )
#    define rforit_2(collection, name) rforit_3(collection, NULL, name)
#    define rforit_1(collection) rforit_2(collection, it)
#else
#    define rforit_3(collection, type, name) for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE( type )> name = __MacrosLibPrivate::_make( collection , true); ( name )-- != ( name ).begin; )
#    define rforit_2(collection, type) rforit_3(collection, ( type ), it)
#    define rforit_1(collection)
#endif // C++11
#define rforit_0
/*!
   \brief [C++] Iterate collection with iterator in reverse order. For compatibility it is better to use the full set of arguments
   \param collection collection object
   \param type [if 2 arguments (collection, type) for less than C++11 and if 3 arguments (collection, type, name)] type of iterator
   \param name [if 2 arguments (collection, name) for C++11 and greater and if 3 arguments (collection, type, name)] iterator name
   \returns loop expression without brackets
*/
#define rforit(...) PP_VA_FUNC(rforit, __VA_ARGS__)

#define forch_0
#define forch_1
#ifdef CXX11
#    define forch_2(collection, name) for(auto& name : collection )
#    define forch_3(collection, name, ...) forch_2(collection, name)
#else
#    define forch_2(collection, name)
#    define forch3(collection, name, ...) PP_SINGLE_TYPE(__VA_ARGS__)::value_type name = STD_PAIR_VALUE(collection.begin()); \
                                        for (__MacrosLibPrivate::MultiIterator<PP_SINGLE_TYPE(__VA_ARGS__)> name##_it = __MacrosLibPrivate::_make( collection ); \
										     name##_it != ( name##_it ).end; ++ name##_it , name = * name##_it )
#endif // CXX11
/*!
   \brief [C++] Iterate collection like foreach by value. For compatibility it is better to use the full set of arguments
   \param collection collection object
   \param name variable name
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#define forch(...) PP_VA_FUNC(forch, __VA_ARGS__)

/*!
   \brief [C++] Iterate collection like foreach by value. For compatibility it is better to use the full set of arguments. Alias for forch
   \param collection collection object
   \param name variable name
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#define forech(...) forch(__VA_ARGS__)
/*!
   \brief [C++] Iterate collection like foreach by value. For compatibility it is better to use the full set of arguments. Alias for forch
   \param collection collection object
   \param name variable name
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#define foreh(...) forch(__VA_ARGS__)

#ifndef foreach
/*!
   \brief [C++] Declare if macro foreach no exists. Iterate collection like foreach by value. For compatibility it is better to use the full set of arguments. Alias for forch. 
   if you want iterate by value - use C++11 range based for or boost foreach, else use forit and iterators - it's more useful
   \param collection collection object
   \param name variable name
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#    define foreach(...) forch(__VA_ARGS__)
#endif // foreach

#ifdef CXX11
/*!
   \brief [C++] Iterate collection like foreach by value with name of variable 'val'. For compatibility it is better to use the full set of arguments.
   \param collection collection object
   \param __VA_ARGS__ [optional in C++11 and greater] type of iterator
   \returns loop expression without brackets
*/
#define forval(colleltion, ...) foreach(colleltion, val)
#else
#define forval(colleltion, ...) foreach(colleltion, val, (__VA_ARGS__))
#endif // CXX11

#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_MACROS_LIB_FOREACH_H__