# Tetris SFML

Tetris SFML to gra napisana w języku C++ z wykorzystaniem biblioteki SFML. Jest to prosta implementacja klasycznej gry Tetris.

## Opis

Gra Tetris polega na układaniu spadających klocków w taki sposób, aby wypełnić poziome linie na planszy. Gdy linia jest wypełniona, zostaje usunięta, a gracz otrzymuje punkty. Gra kończy się, gdy klocki osiągną górną część planszy.

## Instalacja i uruchomienie

### Wymagania

- Kompilator C++ (np. g++)
- Biblioteka SFML (https://www.sfml-dev.org/)

### Kompilacja

1. Pobierz repozytorium:
   ```bash
   git clone https://github.com/TwojeRepozytorium/tetris-sfml.git
   cd tetris-sfml
   
2. Skompiluj projekt:
  ```bash
    g++ -std=c++11 -o tetris main.cpp Game.cpp Board.cpp Piece.cpp Utils.cpp -lsfml-graphics -lsfml-window -lsfml-system
  ```
3. Uruchom program:
  ./tetris

Autor:
Karol Łempicki
Program utworzony na potrzeby zaliczenia zajęć laboratoryjnych/projektu Programowanie Obiektowe.

