cmake_minimum_required(VERSION 3.0.0)
project(ExercisePlanner VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(src include)

set(Sources src/project/ExercisePlanner/main.cpp)
set(Sources ${Sources} src/feature/MuscleUse/MuscleUse.cpp)
set(Sources ${Sources} src/feature/MuscleUse/LoadData.cpp)
add_executable(ExercisePlanner ${Sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
