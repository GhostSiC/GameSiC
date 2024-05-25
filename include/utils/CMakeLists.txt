
add_library(
    utils
    src/AssetsMenager.cpp
    src/StateManager.cpp
    src/LoadSettings.cpp
)

target_include_directories(utils PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(utils PUBLIC UI)