cmake_minimum_required(VERSION 3.25.1)
project(
  Juniorpen01sTemplate
  LANGUAGES CXX
  VERSION 0.1.0
  DESCRIPTION "juniorpen01's CMake C++ project template."
  HOMEPAGE_URL https://github.com/juniorpen01/cpp-juniorpen01s-tutor-journey)

add_executable(juniorpen01s_tutor_journey src/main.cpp)
target_link_libraries(juniorpen01s_tutor_journey
                      PRIVATE juniorpen01s_tutor_journey::core)

add_custom_command(
  TARGET juniorpen01s_tutor_journey
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res
          $<TARGET_FILE_DIR:juniorpen01s_tutor_journey>/res)

add_library(juniorpen01s_tutor_journey_core STATIC src/direction.cpp)
add_library(juniorpen01s_tutor_journey::core ALIAS
            juniorpen01s_tutor_journey_core)
target_include_directories(juniorpen01s_tutor_journey_core PUBLIC include)
target_link_libraries(juniorpen01s_tutor_journey_core PUBLIC glfw fmt::fmt)
target_compile_options(juniorpen01s_tutor_journey_core
                       PUBLIC -Weverything -Wno-c++98-compat -Werror)

include(CTest)
foreach(testSource IN ITEMS tests/direction.cpp)
  cmake_path(GET testSource STEM testSourceName)
  add_executable(${testSourceName} ${testSource})
  add_test(NAME ${testSourceName} COMMAND ${testSourceName})
  target_link_libraries(
    ${testSourceName} PRIVATE juniorpen01s_tutor_journey::core doctest::doctest)
  target_compile_definitions(${testSourceName}
                             PRIVATE DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)
endforeach()

include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
  GIT_TAG 3.4
  GIT_SHALLOW ON
  SYSTEM)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 11.2.0
  GIT_SHALLOW ON
  SYSTEM)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
  doctest
  GIT_REPOSITORY https://github.com/doctest/doctest
  GIT_TAG v2.4.12
  GIT_SHALLOW ON
  SYSTEM)
FetchContent_MakeAvailable(doctest)
