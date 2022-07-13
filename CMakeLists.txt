cmake_minimum_required(VERSION 3.0.0)
project(VerbioTechnicalTest VERSION 1.0.0)

include(CTest)
enable_testing()

add_executable(VerbioTechnicalTest main.cpp parser.cpp numberParser.cpp tokenNumber.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
