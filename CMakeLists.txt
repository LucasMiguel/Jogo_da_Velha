cmake_minimum_required(VERSION 3.14)

project(Jogo_da_Velha LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Jogo_da_Velha
  main.cpp
  include/macros.h
  src/menu.cpp
  include/menu.h
  src/table.cpp
  include/table.h
  src/functions.cpp
  include/functions.h
  src/templates.cpp
  include/templates.h
  src/player.cpp
  include/player.h
  src/player_vs_player.cpp
  include/player_vs_player.h
  src/player_vs_com.cpp
  include/player_vs_com.h
)

target_link_libraries(Jogo_da_Velha -lncurses)
