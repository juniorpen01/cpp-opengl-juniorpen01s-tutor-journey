cmake_minimum_required(VERSION 3.25.1)
project(
  Juniorpen01sTemplate
  LANGUAGES CXX
  VERSION 0.1.0
  DESCRIPTION "juniorpen01's CMake C++ project template."
  HOMEPAGE_URL https://github.com/juniorpen01/cpp-juniorpen01s-template)

add_executable(juniorpen01s_template src/main.cpp)
target_link_libraries(juniorpen01s_template PRIVATE juniorpen01s_template::core)

add_custom_command(
  TARGET juniorpen01s_template
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res
          $<TARGET_FILE_DIR:juniorpen01s_template>/res)

add_library(juniorpen01s_template_core STATIC src/direction.cpp)
add_library(juniorpen01s_template::core ALIAS juniorpen01s_template_core)
target_include_directories(juniorpen01s_template_core PUBLIC include)
target_link_libraries(juniorpen01s_template_core PUBLIC raylib)

include(CTest)
foreach(testSource IN ITEMS tests/direction.cpp)
  cmake_path(GET testSource STEM testSourceName)
  add_executable(${testSourceName} ${testSource})
  add_test(NAME ${testSourceName} COMMAND ${testSourceName})
  target_link_libraries(${testSourceName} PRIVATE juniorpen01s_template::core
                                                  doctest)
  target_compile_definitions(${testSourceName}
                             PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
endforeach()

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib
  GIT_TAG 5.5
  GIT_SHALLOW ON
  SYSTEM)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest
  GIT_TAG v2.4.12
  GIT_SHALLOW ON
  SYSTEM)
FetchContent_MakeAvailable(doctest)
