cmake_minimum_required(VERSION 3.1.0)
project(Platformwrapper_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
set(LIBRARY_OUTPUT_PATH "Bin")

file(GLOB_RECURSE SOURCES "Source/*.cpp")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

add_library(Platformwrapper32 SHARED ${SOURCES})
add_library(Platformwrapper64 SHARED ${SOURCES})
add_library(steam_api SHARED ${SOURCES})

set_target_properties(Platformwrapper32 PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
set_target_properties(Platformwrapper64 PROPERTIES COMPILE_FLAGS "-m64" LINK_FLAGS "-m64")
set_target_properties(Platformwrapper32 Platformwrapper64 PROPERTIES PREFIX "")
set_target_properties(Platformwrapper32 PROPERTIES SUFFIX "ayria32")
set_target_properties(Platformwrapper64 PROPERTIES SUFFIX "ayria64")

target_link_libraries(Platformwrapper32 dl pthread)
target_link_libraries(Platformwrapper64 dl pthread)

set_target_properties(steam_api PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32 -static-libgcc -static-libstdc++")
target_link_libraries(steam_api dl pthread)
