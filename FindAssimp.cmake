set( _assimp_HEADER_SEARCH_DIRS
"/usr/include"
"/usr/local/include"
"${CMAKE_SOURCE_DIR}/includes"
"C:/Program Files (x86)/Assimp/include" )
set( _assimp_LIB_SEARCH_DIRS
"/usr/lib"
"/usr/local/lib"
"${CMAKE_SOURCE_DIR}/lib"
"C:/Program Files (x86)/Assimp/lib" )

# Search for the header
FIND_PATH(ASSIMP_INCLUDE_DIR "assimp/scene.h"
PATHS ${_assimp_HEADER_SEARCH_DIRS} )

FIND_LIBRARY(ASSIMP_LIBRARY NAMES assimp 
PATHS ${_assimp_LIB_SEARCH_DIRS} )

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Assimp DEFAULT_MSG ASSIMP_INCLUDE_DIR ASSIMP_LIBRARY)