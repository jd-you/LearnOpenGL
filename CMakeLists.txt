cmake_minimum_required(VERSION 3.0)

project(LearnOpenGL)
link_directories(${PROJECT_SOURCE_DIR}/lib)
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")
find_package(GLFW3 REQUIRED)
find_package(GLM REQUIRED)
find_package(Assimp REQUIRED)

file(GLOB SOURCE_FILES src/*.c src/*.cpp)
add_executable(main ${SOURCE_FILES})

include_directories(
    ${PROJECT_SOURCE_DIR}/include 
    ${GLFW3_INCLUDE_DIR}
    ${GLM_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
)

target_link_libraries(main 
    ${GLFW3_LIBRARY}
    ${ASSIMP_LIBRARY}
    ${PROJECT_SOURCE_DIR}/lib/libz.a
)



