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

  // If the number is divisible by the sum of its digits, then is Harshad number
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


bool is_right_truncatable_Harshad_number(size_t num){

  // Check the num is harshad
  while(num!=0 and is_Harshad_number(num))
    num /= 10;

  // If the num result from loop is different to 0 is because, in its trunctatable process, one of its results is not
  // Harshad number, then is not Right Truncatable Harshad number
  if(num != 0)
    return false;

  // Otherwise is Right Truncatable Harshad number
  else
    return true;
}


bool is_strong_right_truncatable_Harshad_number(unsigned long int num){

  // Check the num is Strong Harshad number
  if(is_strong_Harshad_number(num))

    // Because is strong Harshad number, then we can right truncate it and check if is Right Truncatable Harshad number
    if(is_right_truncatable_Harshad_number(num/10))
      return true;

  // If num does not get true in both statement is not a Strong Right Truncatable Harshad number
  return false;
}
