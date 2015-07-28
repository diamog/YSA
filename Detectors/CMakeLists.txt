include_directories(..)

SET(DETECTOR_SOURCES
  BigEye.cpp
  Block.cpp
  Wall.cpp
)
add_library(detectors ${DETECTOR_SOURCES})
target_link_libraries(detectors plats)
target_link_libraries(detectors enemy)
