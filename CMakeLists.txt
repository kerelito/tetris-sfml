cmake_minimum_required(VERSION 3.27)
project(tetris_sfml)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(tetris_sfml
        resources/Arial.ttf
        src/Board.cpp
        src/Board.h
        src/Game.cpp
        src/Game.h
        src/main.cpp
        src/Piece.cpp
        src/Piece.h
        src/Utils.cpp
        src/Utils.h)

# Znalezienie pakietu SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Dodanie katalogów nagłówkowych SFML
include_directories(${SFML_INCLUDE_DIRS})

# Linkowanie bibliotek SFML
target_link_libraries(tetris_sfml sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

add_custom_command(TARGET tetris_sfml POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:tetris_sfml>/resources)