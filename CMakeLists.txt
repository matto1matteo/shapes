cmake_minimum_required(VERSION 3.20)

set(P_NAME "Shapes")
set(V_MAJOR 0)
set(V_MINOR 0)
set(V_PATCH 1)

project(${P_NAME} VERSION "${V_MAJOR}.${V_MINOR}.${V_PATCH}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Shapes_sources
    "src/shapes.cpp"
)
set(SHAPE_LIB ShapesLib)
add_library(${SHAPE_LIB} ${Shapes_sources})
target_include_directories(${SHAPE_LIB} PUBLIC "include/shapes")

add_executable(${P_NAME} "src/main.cpp")
target_link_libraries(${P_NAME} PUBLIC ${SHAPE_LIB})

list(APPEND CMAKE_MODULE_PATH "./cmake")
include(dependencies)
set(CATCH_VERSION "3.3.2")
dependency("https://github.com/catchorg/Catch2" "v${CATCH_VERSION}")

find_package(Catch2 QUIET)
set(BUILD_TEST ON CACHE BOOL "Build test switch. If catch2 is not found is set to false")
if(NOT Catch2_FOUND)
    set(BUILD_TEST OFF)
else()
    message(STATUS "Adding BUILD_TEST to preprocessor")
    add_executable(${SHAPE_LIB}TEST ${Shapes_sources})
    target_include_directories(${SHAPE_LIB}TEST PUBLIC "include/shapes")
    target_link_libraries(${SHAPE_LIB}TEST PRIVATE Catch2::Catch2WithMain)
    target_compile_definitions(${SHAPE_LIB}TEST PUBLIC BUILD_TEST)
endif()

message(STATUS "Building with tests: ${BUILD_TEST}")

