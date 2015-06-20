cmake_minimum_required (VERSION 2.6)
project (YSA)

add_definitions(-DCOMPILE_NO_SF)
add_definitions(-DCOMPILE_NO_VB)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Levels)

add_subdirectory(Extras)
add_subdirectory(Enemies)
add_subdirectory(Platforms)
add_subdirectory(Switables)
add_subdirectory(Levels)

set(ROOT_HEADERS
  stdafx.h
  Codes.h
  Actor.h
  Mover.h
  Level.h
)

set(ROOT_SOURCES
  Actor.cpp
  Mover.cpp
  Level.cpp
)

add_executable(YSA ${ROOT_HEADERS} ${ROOT_SOURCES} You.h You.cpp First.cpp)

target_link_libraries(YSA extra)
target_link_libraries(YSA enemy)
target_link_libraries(YSA plats)
target_link_libraries(YSA switable)
target_link_libraries(YSA level)