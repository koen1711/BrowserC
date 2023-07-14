
#add_library(EVENTS
#    Events/EventHandler.cpp
#    Events/View/ViewListener.cpp
#)

add_library(RENDER
    App.cpp
)

target_sources(RENDER PRIVATE ../javascript/JavascriptHandler.cpp)