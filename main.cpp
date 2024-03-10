/**
 * @file main.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 10/03/2024
 * @brief File made to test some functions in an specific context
 */


#include <iostream>
#include <chrono>

#include <digits.h>
#include <divisors.h>
#include <fractions.h>
#include <primes.h>
#include <special_numbers.h>



int main(void)
{
  std::chrono::high_resolution_clock::time_point t1, t2;
  std::chrono::duration<double> time_span;

  t1 = std::chrono::high_resolution_clock::now();

  // Aquí va el código que se ejecutará

  t2 = std::chrono::high_resolution_clock::now();
  time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);

  std::cout << "Time: " << time_span.count()*1e3 << " ms." << std::endl;

  return 0;
}
