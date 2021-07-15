include(CTest)
enable_testing()

set(GAME_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories(GAME_INCLUDE_DIR)


add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${GAME_INCLUDE_DIR})

# Tell CMake we want backbone to link against GLFW
#target_link_libraries(${PROJECT_NAME} "glfw3" "${GLFW_LIBRARIES}")
target_link_libraries(${PROJECT_NAME} glfw)
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

include_directories("${GLFW_DIR}/include")

target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")

target_include_directories(${PROJECT_NAME} PRIVATE "${GLM_DIR}/glm")


# CPack Installation Info
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)