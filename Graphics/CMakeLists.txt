include_directories(..)

add_library(graphics SaveGraphic.cpp ColorRemove.cpp ExtraBoard.cpp)
file(GLOB IMAGES
  "*.png"
)
file(COPY ${IMAGES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
