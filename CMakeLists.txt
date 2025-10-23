cmake_minimum_required(VERSION 3.28)
project(asteroid_game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(asteroid_game src/main.cpp "src/game/Ship.cpp" "src/game/Asteroid.cpp")

target_include_directories(asteroid_game PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_compile_features(asteroid_game PRIVATE cxx_std_17)
target_link_libraries(asteroid_game PRIVATE SFML::Graphics)
