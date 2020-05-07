cmake_minimum_required(VERSION 3.15)
project(gameoflife_opengl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)
add_subdirectory(libs/glfw)

add_executable(gameoflife_opengl
        ext/glad.cpp
        ext/spng.c
        src/main.cpp
        src/util/Logger.cpp
        src/render/GameWindow.cpp
        src/model/Field2d.cpp
        src/gl/Loader.cpp
        src/gl/Vao.cpp
        src/render/Camera.cpp
        src/render/shaders/IShader.cpp
        src/model/IField.cpp
        src/gl/MeshBuilder.cpp
        src/gui/font/FontRenderer.cpp
        src/gui/font/FontReader.cpp)

target_include_directories(gameoflife_opengl PRIVATE libs/glm libs/glfw/include inc)
target_link_libraries(gameoflife_opengl glfw ${GLFW_LIBRARIES} z.lib)