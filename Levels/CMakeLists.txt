include_directories(..)
include_directories(../Extras)
include_directories(../Platforms)
include_directories(../Switables)
include_directories(../Enemies)

SET(LEVEL_SRC
  Level1.cpp
  Level2.cpp
  Level3.cpp
  Boss1.cpp
  Level4.cpp
  Level5.cpp
  Level6.cpp
  Level7.cpp
  Level8.cpp
  Level9.cpp
  Boss2.cpp
  Level10.cpp
  Level11.cpp
  Level12.cpp
  Level13.cpp
  Level14.cpp
  Boss3_1.cpp
  Boss3_2.cpp
  Secret1.cpp
  Level15.cpp
  Level16.cpp
  Boss_cat.cpp
)

add_library(level ${LEVEL_SRC})
target_link_libraries(level plats)
target_link_libraries(level enemy)
target_link_libraries(level switable)
target_link_libraries(level bullets)
target_link_libraries(level graphics)
target_link_libraries(level detectors)