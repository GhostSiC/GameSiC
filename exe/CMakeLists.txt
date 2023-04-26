
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio mainEngine)
#find_package(mainEngine REQUIRED)
