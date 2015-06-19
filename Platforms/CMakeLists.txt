include_directories(..)
include_directories(../Extras)

file(GLOB Platforms_SRC "*.cpp")

add_library(plats ${Platforms_SRC})
target_link_libraries(plats  extra)
