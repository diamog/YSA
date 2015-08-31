cmake_minimum_required (VERSION 2.6)
project (YSA)
option(ENABLE_SF "ENABLE_SF" OFF)
option(ENABLE_SF "ENABLE_DEBUG" OFF)
option(ENABLE_SF "ENABLE_PREVERSION" OFF)
IF(ENABLE_PREVERSION)
  add_definitions(-DPREVERSION)
ENDIF()
IF(ENABLE_DEBUG)
  add_definitions(-DCOMPILE_DEBUG)
ENDIF()
IF(NOT ENABLE_SF)
  add_definitions(-DCOMPILE_NO_SF)
ENDIF()
add_definitions(-DCOMPILE_NO_VB)
file(COPY Fonts DESTINATION ${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(Levels)
include_directories(Switables)

add_subdirectory(Music)
add_subdirectory(Graphics)
add_subdirectory(Extras)
add_subdirectory(Menus)
add_subdirectory(Bullets)
add_subdirectory(Enemies)
add_subdirectory(Platforms)
add_subdirectory(Switables)
add_subdirectory(Detectors)
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
  Fairy.cpp
)

add_executable(YSA ${ROOT_SOURCES})

target_link_libraries(YSA menus)
target_link_libraries(YSA graphics)
target_link_libraries(YSA extra)
target_link_libraries(YSA enemy)
target_link_libraries(YSA plats)
target_link_libraries(YSA switable)
target_link_libraries(YSA detectors)
target_link_libraries(YSA level)

IF (ENABLE_SF)
  IF (CYGWIN)
    set(SFML_ROOT E:/)
    MESSAGE(${SFML_ROOT})
  ELSE()
    set(SFML_ROOT /home/diamog)
  ENDIF()
  set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
  
  find_package(SFML REQUIRED system window graphics audio)

  if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(YSA ${SFML_LIBRARIES})
  endif()
ENDIF()
