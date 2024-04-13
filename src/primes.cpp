/**
 * @file primes.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 15/09/2022
 * @brief Source file associated to prime algorithms
 */


#include <primes.h>


bool is_prime(unsigned long int num){
  // If the number is 1 or 0, then is not prime
  if(num <= 1)
    return false;

  // If number is 2 then is prime
  if(num == 2)
    return true;

  // If the number is even greater than 2, then is not prime
  if(num%2 == 0)
    return false;

  // Loop over odd numbers less than sqrt
  for(unsigned long int i=3; i*i<=num; i+=2){

    // If i is a divisor, is not prime
    if(num%i == 0)
      return false;
  }

  // If any number is a divisor, is prime
  return true;
}


bool is_rare_prime(unsigned int num){
  // Case of 1. All numbers are divisible by 1
  if(!is_prime(1+num))
    return false;

  // Case of 2. num is an even number
  if(!is_prime(2+num/2))
    return false;

  // Check f(i) = i+num/i is the sum of two divisors.
  // If we take the divisor num/i, then f(num/i) = num/i+num/(num/i) = num/i+i = i+num/i.
  // Then is enough to check the smaller of pair of divisors.

  // Loop over numbers that n
  for(unsigned int i=3; i*i<=num; i++){

    // Check if it is divisor
    if(num%i == 0){

      // If it is not "rare" prime, then return false.
      if(!is_prime(i+num/i))
	return false;
    }
  }

  // If all divisors are "rare" primes return true
  return true;
}


bool is_odd_prime(unsigned int num){
  // Loop over odd numbers below equal sqrt
  for(unsigned int i=3; i*i<=num; i+=2)
    // If i is a divisor, is not prime
    if(num%i == 0) return false;

  // If any number is a divisor, is prime
  return true;
}



size_t calculate_euler_totient_function(size_t n){

  // Init the result
  size_t result = n;

  // If n is even then reduce it to its odd form
  if(n%2 == 0){

    // Reduce the number
    do
      n /= 2;
    while(n%2 == 0);

    // Check that result = result*(1 - 1/p) = result - result/p, then result -= result/p
    result -= result/2;
  }

  // We do the loop until sqrt because there's ony one prime number (if is exists) greater than sqrt and a divisor of n
  // Loop over all odd numbers because there is no an even prime number greater than 2.
  for(unsigned int i=3; i*i<=n; i+=2)

    // Check if i divides n
    if(n%i == 0){

      // Reduce the number n
      do
	n /= i;
      while(n%i == 0);

      // Update result
      result -= result/i;
    }

  //If n has a prime factor greater than n, then take it
  if(n > 1)
    result -= result/n;

  return result;
}
