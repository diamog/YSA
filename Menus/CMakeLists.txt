include_directories(..)


set(MENU_SRC 
  StartMenu.cpp
  FileMenu.cpp
)

add_library(menus ${MENU_SRC})
target_link_libraries(menus extra)
