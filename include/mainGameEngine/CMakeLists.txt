#mainGameEngine

add_library(
    mainEngine
    src/MainEngine.cpp
    src/AssetsMenager.cpp
    src/StateManager.cpp
)

#add_executable(mainEngine src/MainEngine.cpp)

#target_include_directories(mainEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(mainEngine PUBLIC 
    #$<INSTALL_INTERFACE:export>
    #$<INSTALL_INTERFACE:inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(mainEngine PUBLIC sfml-audio city UI gui)