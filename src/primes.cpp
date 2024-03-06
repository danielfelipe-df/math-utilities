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
