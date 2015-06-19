include_directories(..)
include_directories(../Extras)

file(GLOB Enemy_SRC "*.cpp")

add_library(enemy ${Enemy_SRC})
target_link_libraries(enemy extra)