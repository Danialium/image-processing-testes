cmake_minimum_required(VERSION 3.10.0)

project(ImageProcessingTestes 
    VERSION 0.1.0 
    LANGUAGES C CXX)

set(PROJECT_EXECUTABLE_NAME "ImageProcessingTestes")
message(STATUS "Project Name : ${PROJECT_EXECUTABLE_NAME}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

list(APPEND CMAKE_PREFIX_PATH 
    "${CMAKE_CURRENT_SOURCE_DIR}/external/opencv/build")

find_package(OpenCV 4.6.0 EXACT REQUIRED)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_EXECUTABLE_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_EXECUTABLE_NAME} PRIVATE _MY_WIN_64_)

target_include_directories(${PROJECT_EXECUTABLE_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${OpenCV_INCLUDE_DIRS})

set(PROJECT_LIBS ${OpenCV_LIBS})

list(APPEND PROJECT_LIBS Winmm.lib Ws2_32.lib)

target_link_libraries(${PROJECT_EXECUTABLE_NAME} PRIVATE ${PROJECT_LIBS})
