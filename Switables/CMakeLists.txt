include_directories(../Extras)
include_directories(..)

file(GLOB Switable_SRC "*.h" "*.cpp")

add_library(switable ${Switable_SRC})
