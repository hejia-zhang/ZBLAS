include_directories(/usr/local/inlude ${CMAKE_HOME_DIRECTORY}/src/)

add_executable(Example1 main.cpp ${CMAKE_HOME_DIRECTORY}/src/Vector.cpp)