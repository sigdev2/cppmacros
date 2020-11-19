//
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef __HAS_CPPMACROS_CONTAINERS_H__
#define __HAS_CPPMACROS_CONTAINERS_H__

/*! \file containers.h
    \brief Macros for define conteiners variables and types in current namespace.
    
    Depend from:
	 - /common/lang.h
*/

#include "../macroslib/src/macroslib.h"
#include "lang.h"


/* */
#ifdef __cplusplus


// containers typedef's

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form \a container with specified base \a name
   \param container container base type, wirthout template arguments
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for \a container template arguments
   \returns typdef's for \a container type with specified base \a name
*/
#define CONTAINER_TYPEDEF(container, name, ... ) typedef container##< PP_MAP( PP_SINGLE_TYPE, __VA_ARGS__ ) > name##_t;\
    typedef name##_t::iterator name##_iter_t;\
    typedef name##_t::const_iterator name##_citer_t;\
    typedef name##_t& name##_ref_t;\
    typedef const name##_t& name##_cref_t;\
    typedef name##_t* name##_pointer_t;

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::map with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::map template arguments
   \returns typdef's for std::map type with specified base \a name
*/
#define MAP_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::unordered_map with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::unordered_map template arguments
   \returns typdef's for std::unordered_map type with specified base \a name
*/
#define UMAP_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::unordered_map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::multimap with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::multimap template arguments
   \returns typdef's for std::multimap type with specified base \a name
*/
#define MMAP_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::unordered_multimap with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::unordered_multimap template arguments
   \returns typdef's for std::unordered_multimap type with specified base \a name
*/
#define UMMAP_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::unordered_multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::set with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::set template arguments
   \returns typdef's for std::set type with specified base \a name
*/
#define SET_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::unordered_set with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::unordered_set template arguments
   \returns typdef's for std::unordered_set type with specified base \a name
*/
#define USET_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::unordered_set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::multiset with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::multiset template arguments
   \returns typdef's for std::multiset type with specified base \a name
*/
#define MSET_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::unordered_multiset with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::unordered_multiset template arguments
   \returns typdef's for std::unordered_multiset type with specified base \a name
*/
#define UMSET_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::unordered_multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::vector with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::vector template arguments
   \returns typdef's for std::vector type with specified base \a name
*/
#define VECTOR_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::vector, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::list with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::list template arguments
   \returns typdef's for std::list type with specified base \a name
*/
#define LIST_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::forward_list with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::forward_list template arguments
   \returns typdef's for std::forward_list type with specified base \a name
*/
#define FLIST_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::forward_list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::deque with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::deque template arguments
   \returns typdef's for std::deque type with specified base \a name
*/
#define DEQUE_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::deque, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::queue with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::queue template arguments
   \returns typdef's for std::queue type with specified base \a name
*/
#define QUEUE_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::priority_queue with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::priority_queue template arguments
   \returns typdef's for std::priority_queue type with specified base \a name
*/
#define PQUEUE_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::priority_queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::stack with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \param __VA_ARGS__ types for std::stack template arguments
   \returns typdef's for std::stack type with specified base \a name
*/
#define STACK_TYPEDEF(name, ... ) CONTAINER_TYPEDEF(std::stack, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::string with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \returns typdef's for std::string type with specified base \a name
*/
#define STR_TYPEDEF(name) CONTAINER_TYPEDEF(std::basic_string, name, char)

/*! 
   \brief [C++] Define in current namespace iterators, references and pointer types form std::wstring with specified base \a name
   \param name base name from types name_t, name_iter_t, name_ref_t and etc ...
   \returns typdef's for std::wstring type with specified base \a name
*/
#define WSTR_TYPEDEF(name) CONTAINER_TYPEDEF(std::basic_string, name, wchar_t)


// define variable

/*! 
   \brief [C++] Define in current namespace variable with \a container type with specified base \a name and \a prefix
   \param container container base type, wirthout template arguments
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for \a container template arguments
   \returns define variable with \a container type with specified base \a name and \a prefix
*/
#define CONTAINER_VAR(container, prefix, name, ... ) container##< PP_MAP( PP_SINGLE_TYPE, __VA_ARGS__ ) > prefix##name;

/*! 
   \brief [C++] Define in current namespace std::map with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::map template arguments
   \returns define std::map with specified base \a name and \a prefix
*/
#define MAP_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::unordered_map with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_map template arguments
   \returns define std::unordered_map with specified base \a name and \a prefix
*/
#define UMAP_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::unordered_map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::multimap with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::multimap template arguments
   \returns define std::multimap with specified base \a name and \a prefix
*/
#define MMAP_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::unordered_multimap with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_multimap template arguments
   \returns define std::unordered_multimap with specified base \a name and \a prefix
*/
#define UMMAP_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::unordered_multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::set with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::set template arguments
   \returns define std::set with specified base \a name and \a prefix
*/
#define SET_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::unordered_set with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_set template arguments
   \returns define std::unordered_set with specified base \a name and \a prefix
*/
#define USET_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::unordered_set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::multiset with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::multiset template arguments
   \returns define std::multiset with specified base \a name and \a prefix
*/
#define MSET_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::unordered_multiset with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_multiset template arguments
   \returns define std::unordered_multiset with specified base \a name and \a prefix
*/
#define UMSET_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::unordered_multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::vector with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::vector template arguments
   \returns define std::vector with specified base \a name and \a prefix
*/
#define VECTOR_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::vector, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::list with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::list template arguments
   \returns define std::list with specified base \a name and \a prefix
*/
#define LIST_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::forward_list with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::forward_list template arguments
   \returns define std::forward_list with specified base \a name and \a prefix
*/
#define FLIST_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::forward_list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::deque with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::deque template arguments
   \returns define std::deque with specified base \a name and \a prefix
*/
#define DEQUE_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::deque, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::queue with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::queue template arguments
   \returns define std::queue with specified base \a name and \a prefix
*/
#define QUEUE_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::priority_queue with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::priority_queue template arguments
   \returns define std::priority_queue with specified base \a name and \a prefix
*/
#define PQUEUE_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::priority_queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::stack with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::stack template arguments
   \returns define std::stack with specified base \a name and \a prefix
*/
#define STACK_VAR(prefix, name, ... ) CONTAINER_VAR(prefix, std::stack, name, __VA_ARGS__)

/*! 
   \brief [C++] Define in current namespace std::string with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \returns define std::string with specified base \a name and \a prefix
*/
#define STR_VAR(prefix, name) CONTAINER_VAR(prefix, std::string, name, char)

/*! 
   \brief [C++] Define in current namespace std::wstring with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \returns define std::wstring with specified base \a name and \a prefix
*/
#define WSTR_VAR(prefix, name) CONTAINER_VAR(prefix, std::wstring, name, wchar_t)


// define with typedef

/*! 
   \brief [C++] Define \a conteiner variable with default typedef's in current namespace with specified base \a name and \a prefix
   \param container container base type, wirthout template arguments
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for \a container template arguments
   \returns define \a conteiner variable with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define CONTAINER_MAINVAR(container, prefix, name, ... ) CONTAINER_TYPEDEF(container, name, __VA_ARGS__);\
    CONTAINER_VAR(container, prefix, name, __VA_ARGS__);

/*! 
   \brief [C++] Define std::map with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::map template arguments
   \returns define std::map with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define MAP_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::unordered_map with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_map template arguments
   \returns define std::unordered_map with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define UMAP_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::unordered_map, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::multimap with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::multimap template arguments
   \returns define std::multimap with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define MMAP_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::unordered_multimap with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_multimap template arguments
   \returns define std::unordered_multimap with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define UMMAP_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::unordered_multimap, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::set with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::set template arguments
   \returns define std::set with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define SET_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::unordered_set with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_set template arguments
   \returns define std::unordered_set with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define USET_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::unordered_set, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::multiset with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::multiset template arguments
   \returns define std::multiset with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define MSET_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::unordered_multiset with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::unordered_multiset template arguments
   \returns define std::unordered_multiset with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define UMSET_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::unordered_multiset, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::vector with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::vector template arguments
   \returns define std::vector with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define VECTOR_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::vector, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::list with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::list template arguments
   \returns define std::list with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define LIST_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::forward_list with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::forward_list template arguments
   \returns define std::forward_list with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define FLIST_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::forward_list, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::deque with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::deque template arguments
   \returns define std::deque with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define DEQUE_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::deque, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::queue with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::queue template arguments
   \returns define std::queue with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define QUEUE_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::priority_queue with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::priority_queue template arguments
   \returns define std::priority_queue with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define PQUEUE_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::priority_queue, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::stack with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::stack template arguments
   \returns define std::stack with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define STACK_MAINVAR(prefix, name, ... ) CONTAINER_MAINVAR(prefix, std::stack, name, __VA_ARGS__)

/*! 
   \brief [C++] Define std::string with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::string template arguments
   \returns define std::string with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define STR_MAINVAR(prefix, name) CONTAINER_MAINVAR(prefix, std::string, name, char)

/*! 
   \brief [C++] Define std::wstring with default typedef's in current namespace with specified base \a name and \a prefix
   \param prefix prefix for variable name, for example m_, m_n or just _
   \param name base name from variable
   \param __VA_ARGS__ types for std::wstring template arguments
   \returns define std::wstring with default typedef's in current namespace with specified base \a name and \a prefix
*/
#define WSTR_MAINVAR(prefix, name) CONTAINER_MAINVAR(prefix, std::wstring, name, wchar_t)


#endif // __cplusplus

/////////////////////////////////////////////////////////////////////////////
#endif // __HAS_CPPMACROS_CONTAINERS_H__