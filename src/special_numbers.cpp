/**
 * @file special_numbers.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 17/09/2022
 * @brief
 */


#include <special_numbers.h>

#include <digits.h>
#include <primes.h>


bool is_Harshad_number(unsigned long int num){

  // Calculate the sum of its digits
  unsigned int sum_dig = sum_digits(num);

  // If the number is divisible by the sum of its digits, then is True
  return (num%sum_dig == 0);
}


bool is_strong_Harshad_number(unsigned long int num){

  // Calculate the sum of its digits
  unsigned int sum_dig = sum_digits(num);

  // Check if is a Harshad number
  if(num%sum_dig == 0)

    // If the division of Harshad number by the sum of its digits is prime, then is true
    return is_prime(num/sum_dig);


  // If is not a Harshad number return false
  else
    return false;
}
