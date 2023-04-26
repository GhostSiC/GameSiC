
add_subdirectory(mainGameEngine)

target_include_directories(mainEngine PUBLIC 
    $<INSTALL_INTERFACE:mainGameEngine>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/mainGameEngine>
)

#add_executable(app0 src/Engine.cpp)

#target_include_directories(mainGameEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mainGameEngine)

#target_include_directories(mainEngine PUBLIC
  #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  #$<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
#)