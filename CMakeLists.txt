cmake_minimum_required(VERSION 3.0.0)
project(ExercisePlanner VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(src include)

add_library(MuscleUse src/feature/MuscleUse/MuscleUse.cpp src/feature/MuscleUse/LoadData.cpp)

add_executable(ExercisePlanner src/project/ExercisePlanner/main.cpp)
target_link_libraries(ExercisePlanner MuscleUse)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
