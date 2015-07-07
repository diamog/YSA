include_directories(../Extras)
include_directories(..)
include_directories(../Enemies)
set (SWITCH_SRC
  Switch.cpp
  Save.cpp
  RedSwitch.cpp
  Portal.cpp
  FollowerFactory.cpp
)

set (COLLECTABLE_SRC
  Collectable.cpp
  Hint.cpp
  Crystal.cpp
  Extra.cpp
  Coin.cpp
)

add_library(switable ${SWITCH_SRC} ${COLLECTABLE_SRC})
target_link_libraries(switable enemy)