set( _GLAD_HEADER_SEARCH_DIRS
"/usr/include"
"/usr/local/include"
"${CMAKE_SOURCE_DIR}/includes"
"C:/Program Files (x86)/GLAD/include" )
set( _GLAD_LIB_SEARCH_DIRS
"/usr/lib"
"/usr/local/lib"
"${CMAKE_SOURCE_DIR}/lib"
"C:/Program Files (x86)/GLAD/lib" )

# Search for the header
FIND_PATH(GLAD_INCLUDE_DIR "glad/glad.h"
PATHS ${_GLAD_HEADER_SEARCH_DIRS} )

FIND_LIBRARY(GLAD_LIBRARY NAMES glad
PATHS ${_GLAD_LIB_SEARCH_DIRS} )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLAD DEFAULT_MSG GLAD_INCLUDE_DIR GLAD_LIBRARY)