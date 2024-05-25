#mainGameEngine

add_library(
    UI
    src/Button.cpp
    src/StandardButtonBuilder.cpp
)

#add_executable(mainEngine src/MainEngine.cpp)

#target_include_directories(mainEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(UI PUBLIC 
    #$<INSTALL_INTERFACE:export>
    #$<INSTALL_INTERFACE:inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(UI PUBLIC sfml-graphics utils mainEngine) # TODO: delete sfml-graphics only in mainEngine
