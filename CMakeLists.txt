cmake_minimum_required(VERSION 3.10)

project(MapGenerator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/Biome.cpp
    src/Map.cpp
    src/MapDetail.cpp
    src/MapGenerator.cpp
    src/Objects.cpp
    src/Tile.cpp
    main.cpp
)

add_executable(generatedmap ${SOURCES})

target_include_directories(generatedmap PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/libs/FastNoiseLite/Cpp"
)