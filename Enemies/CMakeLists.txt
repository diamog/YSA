include_directories(..)
include_directories(../Extras)

set(ENEMY_SRC 
  Enemy.cpp
  Death.cpp
  DeathArea.cpp
  ColorBoss.cpp
  Follower.cpp
  Reverser.cpp
  Drone.cpp
  Rider.cpp)

add_library(enemy ${ENEMY_SRC})
target_link_libraries(enemy extra)