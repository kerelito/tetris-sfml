cmake_minimum_required(VERSION 3.27)
project(tetris_sfml)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 14)

# Znalezienie pakietu SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Dodanie podkatalogu src
add_subdirectory(src)