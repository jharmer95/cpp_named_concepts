cmake_minimum_required(VERSION 3.19)

project(cpp_named_concepts
  VERSION 0.1.0
  DESCRIPTION "Provides concepts for each of the C++ named requirements"
  LANGUAGES CXX
)

add_library(named_concepts INTERFACE)
target_compile_features(named_concepts INTERFACE cxx_std_20)
target_include_directories(named_concepts INTERFACE include)

add_executable(concept_test "tests/test.cpp")
target_compile_features(concept_test PRIVATE cxx_std_20)
target_compile_options(concept_test PRIVATE -fdiagnostics-color=always -fconcepts-diagnostics-depth=10)
target_link_libraries(concept_test PRIVATE named_concepts)
