
add_subdirectory(mainGameEngine)
add_subdirectory(UI)
add_subdirectory(gui)
add_subdirectory(city)

#target_include_directories(mainEngine PUBLIC 
#    $<INSTALL_INTERFACE:mainGameEngine>
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/mainGameEngine>
#)

# target_include_directories(city PUBLIC 
# $<INSTALL_INTERFACE:city>
# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/city>
# )

#add_executable(app0 src/Engine.cpp)

# target_include_directories(city PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/city)

#target_include_directories(mainEngine PUBLIC
  #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
#)