include_directories(..)

#add_library(graphics SaveGraphic.cpp ColorRemove.cpp)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/save.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Colorless.wav DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
