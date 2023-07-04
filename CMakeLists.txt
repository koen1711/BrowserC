cmake_minimum_required(VERSION 3.10)
project(browser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
    build/SDK/include
    extern/sciter/include
    #extern/v8/v8/include
    extern/libtidy/include
    extern/gtk/include
    extern/glib/include
    extern/pango/include
    extern/harfbuzz/include
    extern/cairo
    extern/gdk-pixbuf
    extern/atk-1.0
)

add_custom_command(
    OUTPUT browserui
    COMMAND cd src/browser && yarn build
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Building browser"
)

# check which os we are on
if (LINUX) # Linux
    add_custom_command(
        OUTPUT resourcesrenderer
        COMMAND cp -R build/SDK/resources build/assets
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )



elseif (WIN32) # Windows
    add_custom_command(
        OUTPUT resourcesrenderer
        COMMAND xcopy /E /I /Y build/SDK/bin/resources assets/resources
    )
endif()




add_subdirectory(extern/libtidy)
#add_subdirectory(extern/v8)
add_subdirectory(src)





add_executable(MyApp src/main.cpp)
add_custom_target(browser_build ALL DEPENDS browserui)
add_custom_target(resourcesrenderer_build ALL DEPENDS resourcesrenderer)

#target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/extern/sciter/bin.lnx/x64/libsciter-gtk.so)
#target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/extern/sciter/bin.lnx/x64/sciter-sqlite.so)
target_link_libraries(MyApp HTML)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/extern/libtidy/build/cmake/libtidy.so)
#target_link_libraries(MyApp v8_libbase)
#target_link_libraries(MyApp v8_base_without_compiler)
#target_link_libraries(MyApp v8_compiler)
#target_link_libraries(MyApp v8_libplatform)
#target_link_libraries(MyApp v8_snapshot)
#target_link_libraries(MyApp v8_libsampler)
#target_link_libraries(MyApp v8_inspector)
#target_link_libraries(MyApp v8_initializers)
#target_link_libraries(MyApp v8_torque_generated)
target_link_libraries(MyApp pango-1.0)
target_link_libraries(MyApp gtk-3)
target_link_libraries(MyApp glib-2.0)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/build/SDK/bin/libUltralightCore.so)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/build/SDK/bin/libWebCore.so)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/build/SDK/bin/libUltralight.so)
target_link_libraries(MyApp /home/koen/Documents/GitHub/BrowserC/build/SDK/bin/libAppCore.so)
