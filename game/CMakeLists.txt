include(CTest)
enable_testing()

set(GAME_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(GAME_INCLUDE_DIR)


add_executable(backbone src/main.cpp
    src/application/capplication.cpp
    src/examples/example_application.cpp
    src/application/capplication_implementation.cpp
    src/utilities/fps_counter.cpp
    src/game_objects/scenegraph.cpp
    src/game_objects/scenenode.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_INCLUDE_DIR})

# Tell CMake we want backbone to link against GLFW
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

include_directories("${GLFW_DIR}/include")

target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

# CPack Installation Info
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)