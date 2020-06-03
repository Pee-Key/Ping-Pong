cmake_minimum_required(VERSION 3.15)
project(PingPongGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_compile_options(-Wall -Wextra)

if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/Program Files (x86)/mingw64/SFMLx32/lib/cmake")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(PingPongGame main.cpp)

target_link_libraries(PingPongGame sfml-graphics sfml-audio)