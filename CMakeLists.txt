cmake_minimum_required(VERSION 3.7)
project(Ember_core)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/engine")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    main.cpp
    engine/Display/Window.cpp
    engine/Display/Window.h
    engine/Graphical/Renderer.cpp
    engine/Graphical/Renderer.h
    engine/Graphical/Renderable.cpp
    engine/Graphical/Renderable.h
    engine/Tools/file.h
    engine/Graphical/Shader.cpp
    engine/Graphical/Shader.h
    engine/Tools/helpers.cpp
    engine/Tools/fps.h
    engine/Tools/Interval.h
    engine/Tools/helpers.h
    engine/Buffers/Buffer.cpp
    engine/Buffers/Buffer.h
    engine/Buffers/IndexBuffer.cpp
    engine/Buffers/IndexBuffer.h
    engine/Buffers/VertexArray.cpp
    engine/Buffers/VertexArray.h
        game/Game.cpp
    game/Game.h
        engine/Tools/ImageLoader.h engine/Graphical/Texture.cpp engine/Graphical/Texture.h engine/tools/ToString.h)

add_executable(Ember_core ${SOURCE_FILES})

# Use the FindPkgCOnfig to find sdl and sdl image.
INCLUDE(FindPkgConfig)
INCLUDE(FindFreeImage.cmake)
INCLUDE(FindGLM.cmake)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(GLFW REQUIRED glfw3)
PKG_SEARCH_MODULE(GLM REQUIRED glm)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${SDL2IMAGE_INCLUDE_DIRS})

INCLUDE_DIRECTORIES(${GLFW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLM_INCLUDE_DIRS})

FIND_PATH( SOIL_INCLUDE_DIRS SOIL.h PATH_SUFFIXES SOIL )
FIND_LIBRARY( SOIL_LIBRARIES SOIL)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${GLFW_LIBRARIES} ${SOIL_LIBRARIES} ${FREEIMAGE_LIBRARIES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLUT_INCLUDE_DIRS})
include_directories($(GLEW_INCLUDE_DIRS))
include_directories($(SOIL_INCLUDE_DIRS))

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})


ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND rsync
        ARGS -r
        "${PROJECT_SOURCE_DIR}/files/"
        "${PROJECT_SOURCE_DIR}/bin/files"
        COMMENT "Copying Bundle Assets")