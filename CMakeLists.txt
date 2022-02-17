cmake_minimum_required(VERSION 3.3)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/cmake_gitutils")

include(GitUtils)

GitUtils_Define(macroslib https://github.com/sigdev2/macroslib.git)
GitUtils_Depends(cppmacros DEPENDS macroslib)