include_directories(/usr/local/inlude ${CMAKE_HOME_DIRECTORY}/src/)

link_directories(/usr/local/lib)

add_executable(Test main.cpp ${CMAKE_HOME_DIRECTORY}/src/Vector.cpp VectorTest.cpp VectorTest.h ../src/Line.cpp ../src/Line.h)

target_link_libraries(Test gtest gtest_main pthread)