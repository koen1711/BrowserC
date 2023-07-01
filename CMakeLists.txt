cmake_minimum_required(VERSION 3.10)
project(browser)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(extern/v8)
add_subdirectory(extern/raylib)
add_subdirectory(extern/RmlUi)



include_directories(
    extern/v8/v8/include
    extern/raylib/src
    extern/RmlUi/include
)

add_library(HTMLParser
    src/html/HTMLParser.cpp
)

add_executable(MyApp src/main.cpp)
target_link_libraries(MyApp raylib)
target_link_libraries(MyApp RmlUi)
target_link_libraries(MyApp HTMLParser)
target_link_libraries(MyApp v8_libbase)
target_link_libraries(MyApp v8_base_without_compiler)
target_link_libraries(MyApp v8_compiler)
target_link_libraries(MyApp v8_libplatform)
target_link_libraries(MyApp v8_snapshot)
target_link_libraries(MyApp v8_libsampler)
target_link_libraries(MyApp v8_inspector)
target_link_libraries(MyApp v8_initializers)
target_link_libraries(MyApp v8_torque_generated)
