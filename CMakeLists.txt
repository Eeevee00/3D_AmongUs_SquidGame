cmake_minimum_required(VERSION 3.23)
project(Main_Scene_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main_Scene_3 main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(Main_Scene_3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

target_link_libraries(Main_Scene_3 "-framework OpenGL")
target_link_libraries(Main_Scene_3 "-framework GLUT")