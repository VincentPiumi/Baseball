cmake_minimum_required(VERSION 3.12)

set(SOURCE_FOLDER ${CMAKE_SOURCE_DIR}/src)
set(DEPENDENCIES ${SOURCE_FOLDER}/Inning.cpp ${SOURCE_FOLDER}/Team.cpp ${SOURCE_FOLDER}/GameTeam.cpp ${SOURCE_FOLDER}/Player.cpp ${SOURCE_FOLDER}/Game.cpp)

add_compile_options(-DBUILD_TESTING)
add_executable(InningTest InningTest.cpp ${DEPENDENCIES})

enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/include)

set(GTEST_LIB ${CMAKE_SOURCE_DIR}/thirdparty/googletest/googletest/lib)
add_library(gtest STATIC IMPORTED)
set_target_properties(gtest PROPERTIES IMPORTED_LOCATION ${GTEST_LIB}/libgtest.a)

target_link_libraries(InningTest gtest pthread)
