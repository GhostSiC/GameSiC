cmake_minimum_required(VERSION 3.0.0)
project(Game VERSION 0.0.1)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(ASSETS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets") # ${CMAKE_CURRENT_SOURCE_DIR}/assets

# Komenda kopiuje pliki z katalogu content do katalogu wyjściowego
file(COPY ${ASSETS_DIRECTORY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(include)
#add_subdirectory(include/mainGameEngine)
add_subdirectory(exe)

#target_include_directories(Game PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/assets)

set_property(TARGET Game PROPERTY CXX_STANDARD 23)

include(CPack)

