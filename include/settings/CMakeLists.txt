
add_library(
    settings
    src/Settings.cpp
    src/ReadSettingFile.cpp
)


target_include_directories(settings PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(settings PUBLIC UI)
