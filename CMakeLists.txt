cmake_minimum_required(VERSION 3.10)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Set the project name
project( Math-Utilities
  VERSION 1.0
  DESCRIPTION "Math-Utilities"
  LANGUAGES CXX C
)

# Add flags used for all targets
set(CMAKE_CXX_FLAGS "-Wall -Werror -g  -lgmp  -lgmpxx -fsanitize=address -fsanitize=leak")


###########################################################


# This is the part to MAIN option

# Set the name of the target
set(TARGET_NAME_1 main)

# Add the executable
add_executable(${TARGET_NAME_1} main.cpp)

# Add the sources
target_sources(${TARGET_NAME_1} PRIVATE
  src/primes.cpp
  src/digits.cpp
  src/divisors.cpp
  src/fractions.cpp
  src/special_numbers.cpp
  )

# Include folders of directories
target_include_directories(${TARGET_NAME_1} PUBLIC
  inc/
  )


###########################################################


# This is the part to TEST option

# Set the name of the target
set(TARGET_NAME_2 tests)

# Add the executable
add_executable(${TARGET_NAME_2} tst/main_tests.cpp)

# Add the sources
target_sources(${TARGET_NAME_2} PRIVATE
  src/primes.cpp
  src/digits.cpp
  src/divisors.cpp
  src/fractions.cpp
  src/special_numbers.cpp
  tst/primes_test.cpp
  tst/digits_test.cpp
  tst/divisors_test.cpp
  tst/fractions_test.cpp
  tst/special_numbers_test.cpp
  )

# Include folders of directories
target_include_directories(${TARGET_NAME_2} PUBLIC
  inc/
  tst/
  )

# Add the tests
add_test(
  NAME ${TARGET_NAME_2}
  COMMAND ${TARGET_NAME_2} -o report.xml r junit
  )
