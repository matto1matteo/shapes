cmake_minimum_required(VERSION 3.20)

set(P_NAME "Shapes")
set(V_MAJOR 0)
set(V_MINOR 0)
set(V_PATCH 1)
set(PACKAGE_VERSION "${V_MAJOR}.${V_MINOR}.${V_PATCH}")
set(CMAKE_BUILD_TYPE "Debug")

project(${P_NAME} VERSION ${PACKAGE_VERSION})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Shape Lib
set(Shapes_sources
    "src/shapes.cpp"
    "src/circle.cpp"
    "src/rectangle.cpp"
    "src/bound_box.cpp"
)
set(SHAPE_LIB ShapesLib)
add_library(${SHAPE_LIB} ${Shapes_sources})
target_include_directories(${SHAPE_LIB} PUBLIC "include/shapes")

# Window Lib
set(Window_sources
    "src/game.cpp"
)
set(WINDOW_LIB "WindowLib")
add_library(${WINDOW_LIB} ${Window_sources})
target_include_directories(${WINDOW_LIB}
    PUBLIC "include/game")

# Main Executable
add_executable(${P_NAME} "src/main.cpp")

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/dependencies.cmake")
set(CATCH_VERSION "3.3.2")

# SFML Needed vars
set(SFML_VERSION "2.6.x")
set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

# Get external dependencies
dependency("Catch2" "https://github.com/catchorg/Catch2" "v${CATCH_VERSION}")
dependency("sfml" "https://github.com/SFML/SFML.git" "${SFML_VERSION}")
find_package(Catch2 QUIET)
find_package(SFML REQUIRED COMPONENTS system window graphics REQUIRED)

set(BUILD_TEST ON CACHE BOOL "Build test switch. If catch2 is not found is set to false")
if(NOT Catch2_FOUND)
    set(BUILD_TEST OFF)
else()
    message(STATUS "Adding BUILD_TEST to preprocessor")

    # Shapes test
    add_executable(${SHAPE_LIB}TEST ${Shapes_sources})
    target_include_directories(${SHAPE_LIB}TEST
        PUBLIC "include/shapes")
    target_link_libraries(${SHAPE_LIB}TEST
        PRIVATE Catch2::Catch2WithMain
        PRIVATE sfml-system sfml-window sfml-graphics)
    target_compile_definitions(${SHAPE_LIB}TEST
        PUBLIC BUILD_TEST)

    # Window test
    add_executable(${WINDOW_LIB}TEST ${Window_sources})
    target_include_directories(${WINDOW_LIB}TEST
        PUBLIC "include/game")
    target_link_libraries(${WINDOW_LIB}TEST
        PUBLIC ${SHAPE_LIB}
        PRIVATE Catch2::Catch2WithMain
        PRIVATE sfml-system sfml-window sfml-graphics)
    target_compile_definitions(${WINDOW_LIB}TEST
        PUBLIC BUILD_TEST)
endif()

# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/_deps/sfml-build")

target_link_libraries(${WINDOW_LIB}
    PUBLIC ${SHAPE_LIB}
    PRIVATE sfml-system sfml-window sfml-graphics)

target_link_libraries(${SHAPE_LIB}
    PRIVATE sfml-system sfml-window sfml-graphics)

target_link_libraries(${P_NAME}
    PUBLIC ${SHAPE_LIB}
        ${WINDOW_LIB}
    PUBLIC sfml-system sfml-window sfml-graphics)

# message(STATUS "Building with tests: ${BUILD_TEST}")

