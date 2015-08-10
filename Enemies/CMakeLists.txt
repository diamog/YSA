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
  LineDrone.cpp
  Rider.cpp
  PBullet.cpp
  PBullet2.cpp
  PSpawner.cpp
  PumpkinHead.cpp
  PGhost.cpp
  Pumpkin.cpp
  Vine.cpp
  WallVine.cpp
  SmallEye.cpp
  CloudBoss1.cpp
  CloudBoss2.cpp
  Cloud.cpp
  CBullet.cpp
  Storm.cpp
)

add_library(enemy ${ENEMY_SRC})
target_link_libraries(enemy extra)
target_link_libraries(enemy plats)