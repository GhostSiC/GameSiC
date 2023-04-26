cmake_minimum_required(VERSION 3.0.0)
project(Game VERSION 0.0.1)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

## If you want to link SFML statically
#set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_subdirectory(include)
#add_subdirectory(include/mainGameEngine)
add_subdirectory(exe)


include(CPack)

