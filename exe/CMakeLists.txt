
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC  mainEngine) #sfml-graphics sfml-audio
#find_package(mainEngine REQUIRED)
