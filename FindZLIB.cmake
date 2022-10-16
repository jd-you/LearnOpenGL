set( _ZLIB_HEADER_SEARCH_DIRS
"/usr/include"
"/usr/local/include"
"${CMAKE_SOURCE_DIR}/includes"
"C:/Program Files (x86)/zlib/include" )
set( _ZLIB_LIB_SEARCH_DIRS
"/usr/lib"
"/usr/local/lib"
"${CMAKE_SOURCE_DIR}/lib"
"C:/Program Files (x86)/zlib/lib" )

# Search for the header
FIND_PATH(GLAD_INCLUDE_DIR "zlib/zlib.h"
PATHS ${_GLAD_HEADER_SEARCH_DIRS} )

FIND_LIBRARY(GLAD_LIBRARY NAMES zlib
PATHS ${_GLAD_LIB_SEARCH_DIRS} )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ZLIB DEFAULT_MSG ZLIB_INCLUDE_DIR ZLIB_LIBRARY)