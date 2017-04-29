cmake_minimum_required(VERSION 3.7)
project(Ember_core)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    main.cpp
    Display/Window.cpp
    Display/Window.h
    Graphical/Renderer.cpp Graphical/Renderer.h Graphical/Renderable.cpp Graphical/Renderable.h Math/Vector3D.cpp Math/Vector3D.h Math/Vector2D.cpp Math/Vector2D.h Math/Vector4D.cpp Math/Vector4D.h Math/Matrix.cpp Math/Matrix.h Math/Math.cpp Math/Math.h)

add_executable(Ember_core ${SOURCE_FILES})

# Use the FindPkgCOnfig to find sdl and sdl image.
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(GLFW REQUIRED glfw3)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${SDL2IMAGE_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLFW_INCLUDE_DIRS})


TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${GLFW_LIBRARIES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories($(GLEW_INCLUDE_DIRS))

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})
