cmake_minimum_required(VERSION 3.2)
project(PongGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PongGame ${SOURCE_FILES} game_state.h main_state.cpp main_state.h single_game.cpp single_game.h entity.h paddle.h player.cpp player.h score.cpp score.h double_game.cpp double_game.h ball.cpp ball.h ball_entity.h paddleAI.cpp paddleAI.h winscreen.cpp winscreen.h loose_state.cpp loose_state.h block_mode.cpp block_mode.h blocks.cpp blocks.h )

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PongGame ${SFML_LIBRARIES})
endif()