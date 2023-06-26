#mainGameEngine

add_library(
    city
    src/City.cpp
)

#add_executable(mainEngine src/MainEngine.cpp)

#target_include_directories(mainEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(city PUBLIC 
    #$<INSTALL_INTERFACE:export>
    #$<INSTALL_INTERFACE:inc>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
)

target_link_libraries(city PUBLIC sfml-audio UI)