#mainGameEngine

add_library(
    gui
    src/StartMenu.cpp
    src/SettingsMenu.cpp
    src/SettingsAdvance.cpp
    #src/StartMenuView.cpp
    #src/StartMenu_Koper.cpp
)

target_include_directories(gui PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(gui PUBLIC sfml-audio utils UI mainEngine settings)