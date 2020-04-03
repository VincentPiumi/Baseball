cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)

project (baseball)

set(SOURCES Main.cpp Player.cpp Team.cpp Game.cpp Inning.cpp GameTeam.cpp)
list(TRANSFORM SOURCES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
