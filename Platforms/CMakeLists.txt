include_directories(..)
include_directories(../Extras)

set(PLATFORM_SRC
  Platform.cpp
  ThinPlat.cpp
  VerticalPlat.cpp
  ColorPlat.cpp
  Slope.cpp
  KickPlat.cpp
  Stem.cpp
)

add_library(plats ${PLATFORM_SRC})
target_link_libraries(plats  extra)
