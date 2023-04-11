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
