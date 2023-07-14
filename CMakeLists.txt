cmake_minimum_required(VERSION 3.10)
project(browser)

find_package(PkgConfig REQUIRED)
pkg_check_modules(WEBKIT2GTK REQUIRED IMPORTED_TARGET webkit2gtk-4.0)

add_executable(MyApp src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})



add_custom_command(
    OUTPUT browserui
    COMMAND cd src/browser && yarn build
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building browser"
)

include_directories(
    extern/libtidy/include
    extern/curl/include
    /usr/include/webkitgtk-4.0
    extern/glib/include
    extern/atk-1.0/include
    extern/gtk-3.0/include
    extern/pango/include
    extern/harfbuzz/include
    extern/cairo/include
    extern/gdk-pixbuf/include
    extern/libsoup-3.0/include
    #extern/v8/v8/include
)


#add_subdirectory(extern/v8)
add_subdirectory(extern/libtidy)
add_subdirectory(extern/curl)
add_subdirectory(src)

add_library(Curl STATIC IMPORTED)
set_target_properties(Curl PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/libcurl.a)
add_custom_target(browser_build ALL DEPENDS browserui)
target_link_libraries(MyApp PRIVATE
    JavascriptHandler
    Curl
    PkgConfig::WEBKIT2GTK
    RENDER
    AppData
    TABMANAGER
    TAB
    #EVENTS

    ssl
    crypto
    ${CMAKE_SOURCE_DIR}/extern/libtidy/build/cmake/libtidy.so

)



#target_link_libraries(MyApp v8_libbase)
#target_link_libraries(MyApp v8_base_without_compiler)
#target_link_libraries(MyApp v8_compiler)
#target_link_libraries(MyApp v8_libplatform)
#target_link_libraries(MyApp v8_snapshot)
#target_link_libraries(MyApp v8_libsampler)
#target_link_libraries(MyApp v8_inspector)
#target_link_libraries(MyApp v8_initializers)
#target_link_libraries(MyApp v8_torque_generated)
