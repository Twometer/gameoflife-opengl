cmake_minimum_required(VERSION 3.15)
project(gameoflife_3d)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)
add_subdirectory(libs/glfw)

add_executable(gameoflife_3d
        ext/glad.cpp
        src/main.cpp src/util/Logger.cpp src/util/Logger.h src/model/IField.h src/render/GameOfLifeRenderer.cpp src/render/GameOfLifeRenderer.h src/model/Field2d.cpp src/model/Field2d.h src/util/DoubleBuffer.h)

target_include_directories(gameoflife_3d PRIVATE libs/glm libs/glfw/include inc)
target_link_libraries(gameoflife_3d glfw ${GLFW_LIBRARIES})