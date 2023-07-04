cmake_minimum_required(VERSION 3.10)
project(browser)

add_executable(MyApp src/main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
    build/SDK/include
    extern/libtidy/include
    extern/curl/include
    #extern/v8/v8/include
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




#add_subdirectory(extern/v8)
add_subdirectory(extern/libtidy)
add_subdirectory(extern/curl)
add_subdirectory(src)

add_library(Curl STATIC IMPORTED)
set_target_properties(Curl PROPERTIES IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/libcurl.a)

target_link_libraries(MyApp PRIVATE
    RENDER
    AppData
    TABMANAGER
    TAB
    EVENTS
    Curl
    ${CMAKE_SOURCE_DIR}/extern/libtidy/build/cmake/libtidy.so
    ${CMAKE_BINARY_DIR}/SDK/bin/libUltralightCore.so
    ${CMAKE_BINARY_DIR}/SDK/bin/libWebCore.so
    ${CMAKE_BINARY_DIR}/SDK/bin/libUltralight.so
    ${CMAKE_BINARY_DIR}/SDK/bin/libAppCore.so

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
