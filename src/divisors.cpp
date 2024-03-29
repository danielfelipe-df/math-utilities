/**
 * @file divisors.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 26/09/2022
 * @brief
 */


#include <divisors.h>

#include <cmath>


size_t gcd_euclides(size_t m, size_t n){
  if(n == 0)
    return m;

  return gcd_euclides(n, m%n);
}


size_t gcd_stein(size_t m, size_t n){
  //Cases to finish
  if(n == 0)
    return m;

  if(m == 0)
    return n;

  // The operator ~ is the Bitwise operator NOT, it means change 0->1 and 1->0 in the binary representation
  // The operator & is the Bitwise operator AND, it is the same operator AND but in the binary representation
  // The even numbers are those that finishes with 0 in binary representation
  // The odd numbers are those that finishes with 1 in binary representation
  // m is even
  if(~m & 1){

    // n is odd
    if(n & 1)
      return gcd_stein(m >> 1, n);

    // both m and m are even
    else
      return gcd_stein(m >> 1, n >> 1) << 1;
  }

  // The operator >> is the Bitwise right shift operator, it moves the binaries to the right, e.g., 010010->001001.
  // The operator << is the Bitwise right shift operator, it moves the binaries to the right, e.g., 010010->100100.
  // m is odd and n is even
  if(~n & 1)
    return gcd_stein(m, n >> 1);

  if(m > n)
    return gcd_stein((m-n) >> 1, n);

  return gcd_stein((n-m) >> 1, m);
}


size_t num_divisors(size_t num){
  size_t count = 0;
  double aux = std::sqrt(num);

  // Loop over all the numbers under the sqrt
  for(size_t i=1; i<aux; i++){

    // Count two divisors if num is divisible by i
    if(num%i == 0)
      count+=2;
  }

  // If the sqrt divide num, then add one divisor more
  if(std::fmod(num, aux) == 0)
    count++;

  return count;
}


size_t sum_divisors(size_t num){
  size_t sum = 1 + num;
  double aux = std::sqrt(num);

  //Check all numbers less than sqrt and greater than one
  for(size_t i=2; i<aux; i++){

    // If is a divisor, sum the value and its opposed
    if(num%i == 0)
      sum += i + num/i;
  }

  // If the sqrt is a divisor, the sum
  if(std::fmod((double)num, aux) == 0)
    sum += aux;


  return sum;
}


std::vector<size_t> get_prime_divisors_vector(size_t num){

  // Create variable where prime divisors of @p num are saved
  std::vector<size_t> vec;

  // Check if is divisble by 2
  if(num%2 == 0){

    // If 2 divides num, then save it in the vector
    vec.push_back(2);

    // Divides @p num by 2 until it becomes not divisible by 2
    do
      num /= 2;
    while(num%2 == 0);
  }

  // Loop over odd numbers
  for(size_t i=3; num!=1; i+=2)

    // Check if is divisble by i
    if(num%i == 0){

      // If i divides num, then save it in the vector
      vec.push_back(i);

      // Divides @p num by i until it becomes not divisible by i
      do
	num /= i;
      while(num%i == 0);
    }

  // Return the vector with divisor primes
  return vec;
}
