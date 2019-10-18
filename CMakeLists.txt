cmake_minimum_required(VERSION 3.8)
project(monopolyc___V2)

set(CMAKE_CXX_STANDARD 14)
set(GPP_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP_ENABLE_WARNINGS}")

add_executable(SOURCE_FILES main.cpp GameState.h GameState.cpp Board.h Space.h CSVReader.h CSVReader.cpp Space.cpp SpaceType.h Board.cpp SpaceType.cpp Go.h Go.cpp Property.h Property.cpp Rules.h Rules.cpp Utility.h Utility.cpp DiceRoller.h DiceRoller.cpp Player.h Player.cpp Move.h Move.cpp)
