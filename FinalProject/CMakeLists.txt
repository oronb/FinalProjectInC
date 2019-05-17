cmake_minimum_required(VERSION 3.14)
project(FinalProject C)

set(CMAKE_C_STANDARD 11)

include_directories(Headers)

add_executable(FinalProject
        Headers/createBoard.h
      #  Headers/FindAllPossiblePlayerMoves.h
      #  Headers/FindSingleSourceMoves.h
      #  Headers/FindSingleSourceOptimalMove.h
        Headers/General.h
     #   Headers/LoadBoard.h
     #   Headers/PlayGame.h
      #  Headers/StoreBoard.h
      #  Headers/Turn.h
        Headers/printBoard.h
       # Headers/Tree.h
       # Tree.c
        createBoard.c
      #  FindAllPossiblePlayerMoves.c
       # FindSingleSourceMoves.c
      #  FindSingleSourceOptimalMove.c
      #  LoadBoard.c
        main.c
      #  PlayGame.c
      #  StoreBoard.c
       # Turn.c
        printBoard.c
        )
