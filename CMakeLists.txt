cmake_minimum_required(VERSION 3.15)
project(gameoflife_opengl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/glm/glm)
add_subdirectory(libs/glfw)

add_executable(gameoflife_opengl
        ext/glad.cpp
        ext/spng.c
        ext/tinyxml2.cpp
        src/main.cpp
        src/util/Logger.cpp
        src/render/GameWindow.cpp
        src/render/Camera.cpp
        src/render/shaders/IShader.cpp
        src/io/AssetLoader.cpp
        src/io/FontReader.cpp
        src/io/XmlGuiLoader.cpp
        src/io/FieldIO.cpp
        src/gl/Vao.cpp
        src/gl/MeshBuilder.cpp
        src/gl/TextureManager.cpp
        src/gui/font/FontRenderer.cpp
        src/gui/screens/MenuScreen.cpp
        src/gui/screens/NewGameScreen.cpp
        src/gui/screens/IngameGuiScreen.cpp
        src/gui/base/IContainer.cpp
        src/gui/base/IScreen.cpp
        src/gui/base/IDialog.cpp
        src/gui/base/IComponent.cpp
        src/gui/base/IImageComponent.cpp
        src/gui/components/Label.cpp
        src/gui/components/Panel.cpp
        src/gui/components/Button.cpp
        src/gui/components/TextBox.cpp
        src/gui/components/CheckBox.cpp
        src/gui/components/ToolButton.cpp
        src/gui/dialogs/SettingsDialog.cpp
        src/gui/GuiRenderer.cpp
        src/gui/Graphics.cpp
        src/model/Field.cpp)

target_include_directories(gameoflife_opengl PRIVATE libs/glm libs/glfw/include inc)
target_link_libraries(gameoflife_opengl glfw ${GLFW_LIBRARIES} z.lib comctl32.lib ${CMAKE_SOURCE_DIR}/libs/nfd.lib)