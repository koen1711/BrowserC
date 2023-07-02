cmake_minimum_required(VERSION 3.10)
project(browser)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    extern/v8/v8/include
    extern/libtidy/include
)

add_subdirectory(extern/qt5)
add_subdirectory(extern/libtidy)
add_subdirectory(extern/v8)
add_subdirectory(src)







add_executable(MyApp src/main.cpp)
target_link_libraries(MyApp Qt5::Widgets)
target_link_libraries(MyApp HTML)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/extern/libtidy/build/cmake/libtidy.so)
target_link_libraries(MyApp v8_libbase)
target_link_libraries(MyApp v8_base_without_compiler)
target_link_libraries(MyApp v8_compiler)
target_link_libraries(MyApp v8_libplatform)
target_link_libraries(MyApp v8_snapshot)
target_link_libraries(MyApp v8_libsampler)
target_link_libraries(MyApp v8_inspector)
target_link_libraries(MyApp v8_initializers)
target_link_libraries(MyApp v8_torque_generated)
