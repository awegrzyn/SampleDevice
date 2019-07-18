cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(SampleDevice
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_INSTALL_LIBDIR lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -DBOOST_SYSTEM_NO_DEPRECATED -DBOOST_ERROR_CODE_HEADER_ONLY")

find_package(Boost 1.58 COMPONENTS
  container
  unit_test_framework
  program_options
  system
  log
  system
  REQUIRED)
find_package(FairMQ REQUIRED)
find_package(FairLogger REQUIRED)


add_library(SampleDevice SHARED
  src/HelloDevice.cxx
  src/ExamplePlugin.cxx
)

target_include_directories(SampleDevice
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(SampleDevice
  PUBLIC
    Boost::boost
    FairLogger::FairLogger
    FairMQ::FairMQ
  PRIVATE
    Boost::system
)

target_compile_features(SampleDevice PUBLIC cxx_std_17)

add_executable(HelloDevice src/runHelloDevice.cxx)
target_link_libraries(HelloDevice PRIVATE SampleDevice)
