cmake_minimum_required(VERSION 3.7) 
project("sfml-bug")

set(CMAKE_CXX_STANDARD 14)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(OpenGL REQUIRED)

set(SOURCE_FILES 
    src/main.cpp)

add_executable(main ${SOURCE_FILES})

target_link_libraries(main ${OPENGL_LIBRARIES} ${CONAN_LIBS})