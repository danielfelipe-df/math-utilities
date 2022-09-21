cmake_minimum_required(VERSION 3.10)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Set the project name
project( Tests_Math-Utilities
  VERSION 1.0
  DESCRIPTION "Tests for Math-Utilities"
  LANGUAGES CXX C
)

# Set the name of the target
set(TARGET_NAME tests)

# Add the executable
add_executable(${TARGET_NAME} main.cpp)

# Add the sources
target_sources(${TARGET_NAME} PRIVATE
  primes_test.cpp
  digits_test.cpp
  ../src/primes.cpp
  ../src/digits.cpp
  )

# Include folders of directories
target_include_directories(${TARGET_NAME} PUBLIC
  ./
  ../inc/
  )

# Add the tests
add_test(
  NAME ${TARGET_NAME}
  COMMAND ${TARGET_NAME} -o report.xml r junit
  )
