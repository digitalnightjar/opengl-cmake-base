cmake_minimum_required(VERSION 3.1)
project(opengl-cmake-base VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# Set 3rd Party Library Directories
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
set(GLFW_DIR "${LIB_DIR}/glfw3")
set(GLAD_DIR "${LIB_DIR}/glad")
set(GLM_DIR "${LIB_DIR}/glm")

# Disable some things from the GLFW CMake system (Example/Test Programs etc.)
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

# Tell CMake to compile the glad source file into a library with the name "glad"
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")

# Add the GLFW Library
add_subdirectory("${GLFW_DIR}")

include_directories(libs/glfw/include)

# GLM
include_directories("${GLM_DIR}/glm")

# Add the Engine
add_subdirectory("game")