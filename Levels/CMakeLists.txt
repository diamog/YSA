include_directories(..)
include_directories(../Extras)
include_directories(../Platforms)
include_directories(../Switables)

file(GLOB Level_SRC "*.h" "*.cpp")

add_library(level ${Level_SRC})
target_link_libraries(level plats)
target_link_libraries(level enemy)
target_link_libraries(level switable)