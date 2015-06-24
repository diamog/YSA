include_directories(../Extras)
include_directories(..)

set (SWITCH_SRC
  Switch.cpp
  Save.cpp
)

set (COLLECTABLE_SRC
  Collectable.cpp
  Hint.cpp
  Crystal.cpp
  Extra.cpp
)

add_library(switable ${SWITCH_SRC} ${COLLECTABLE_SRC})
