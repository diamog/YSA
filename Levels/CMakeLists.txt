include_directories(..)
include_directories(../Extras)
include_directories(../Platforms)
include_directories(../Switables)

SET(LEVEL_SRC
  Level1.cpp
  Level2.cpp)

add_library(level ${LEVEL_SRC})
target_link_libraries(level plats)
target_link_libraries(level enemy)
target_link_libraries(level switable)