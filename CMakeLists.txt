cmake_minimum_required(VERSION 3.21)
project(advent_of_code_2022)

set(CMAKE_CXX_STANDARD 20)


file(GLOB_RECURSE advent_of_code_2022_main src/main.cpp)
file(GLOB_RECURSE advent_of_code_2022_hdr src/*.h*)
file(GLOB_RECURSE advent_of_code_2022_src src/*.cpp)
list(REMOVE_ITEM advent_of_code_2022_src ${advent_of_code_2022_main})

add_executable(advent_of_code_2022 ${advent_of_code_2022_main} ${advent_of_code_2022_hdr} ${advent_of_code_2022_src})

add_custom_target(copy_resources
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-resources.cmake
        )
add_dependencies(advent_of_code_2022 copy_resources)
