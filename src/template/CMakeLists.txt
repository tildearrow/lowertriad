# <ProjectLicense>
cmake_minimum_required(VERSION 2.8)
project(ProjectName)
add_executable(ProjectName engine.cpp src/etype.cpp main.cpp)
target_link_libraries(ProjectName SDL2 SDL2_ttf)
target_compile_features(ProjectName PRIVATE cxx_range_for)
