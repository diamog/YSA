cmake_minimum_required (VERSION 2.6)
project (YSA)
option(ENABLE_SF "ENABLE_SF" OFF)
IF(NOT ENABLE_SF)
  add_definitions(-DCOMPILE_NO_SF)
ENDIF()
add_definitions(-DCOMPILE_NO_VB)
file(COPY Fonts DESTINATION ${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Levels)
include_directories(Switables)

add_subdirectory(Extras)
add_subdirectory(Bullets)
add_subdirectory(Enemies)
add_subdirectory(Platforms)
add_subdirectory(Switables)
add_subdirectory(Levels)

set(ROOT_SOURCES
  Actor.cpp
  Mover.cpp
  Level.cpp
  Detector.cpp
  Bullet.cpp
  You.cpp
  First.cpp
  SpeechBubble.cpp
)

add_executable(YSA ${ROOT_SOURCES})

target_link_libraries(YSA extra)
target_link_libraries(YSA enemy)
target_link_libraries(YSA plats)
target_link_libraries(YSA switable)
target_link_libraries(YSA level)

IF (ENABLE_SF)
  set(SFML_ROOT /home/diamog)
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
  find_package(SFML REQUIRED system window graphics audio)

  if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(YSA ${SFML_LIBRARIES})
  endif()
ENDIF()