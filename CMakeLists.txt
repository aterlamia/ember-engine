cmake_minimum_required(VERSION 3.7)
project(Ember_core)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/engine")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    main.cpp
    engine/Display/Window.cpp
    engine/Display/Window.h
    engine/Graphical/Renderer.cpp engine/Graphical/Renderer.h engine/Graphical/Renderable.cpp engine/Graphical/Renderable.h engine/Math/Vector3D.cpp engine/Math/Vector3D.h engine/Math/Vector2D.cpp engine/Math/Vector2D.h engine/Math/Vector4D.cpp engine/Math/Vector4D.h engine/Math/Matrix.cpp engine/Math/Matrix.h engine/Math/Math.cpp engine/Math/Math.h engine/tools/file.h)

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


ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND rsync
        ARGS -r
        "${PROJECT_SOURCE_DIR}/files/"
        "${PROJECT_SOURCE_DIR}/bin/files"
        COMMENT "Copying Bundle Assets")