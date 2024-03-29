/**
 * @file digits.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 21/09/2022
 * @brief Source file of functions which are mainly related to digits
 */


#include <digits.h>


bool is_increasing_number(size_t num){
  // Init the variable with the smaller digit
  size_t digit = 9;

  // Loop over all digits
  while(num > 0){
    // If the new digit is smaller than the last one, then is not increasing
    if(digit < num%10){
      return false;
    }

    // Save the new digit
    digit = num%10;
    num /= 10;
  }

  // If all digits are in an increasing progressive, then is increasing number
  return true;
}


bool is_decreasing_number(size_t num){
  // Init the variable with the greater digit
  size_t digit = 0;

  // Loop over all digits
  while(num > 0){
    // If the new digit is greater than the last one, then is not decreasing
    if(digit > num%10){
      return false;
    }

    // Save the new digit
    digit = num%10;
    num /= 10;
  }

  // If all digits are in an decreasing progressive, then is decreasing number
  return true;
}


bool is_bouncy_number(size_t num){
  // If is decreasing or increasing number, then is not bouncy number
  if(is_decreasing_number(num) || is_increasing_number(num))
    return false;

  // If is not neither decreasing nor increasing, then is bouncy
  else
    return true;
}


bool is_palindrome(size_t num){
  // Check if num is igual to its reverse
  return num == reverse(num);
}


size_t reverse(size_t num){
  // Init reversed variable
  size_t reversed = 0;

  // Loop over all digits
  while(num > 0){

    // Construct the reversed number
    // Divide by 10 original number
    reversed = 10*reversed + num%10;
    num /= 10;
  }

  // Return reversed number
  return reversed;
}


size_t sum_digits(size_t num){
  // Init sum variable with zero
  size_t sum = 0;

  // Loop over all digits
  while(num != 0){

    // Sum digits
    sum += num%10;
    num /= 10;
  }

  // Return sum of digits
  return sum;
}


size_t sum_digits_string(std::string num){
  // Init sum variable with zero
  size_t sum = 0;

  // Loop over all digits
  // We make the sum of i and size-i-1 digit
  size_t string_size = num.length();
  for(size_t i=0; 2*i+2<=string_size; i++)
    sum += num[i] + num[string_size-i-1] - 2*48;


  // If the length of num is odd then sum the digit in the middle
  sum += (string_size%2 == 1) ? num[(string_size-1)/2]-48 : 0;

  // Return the sum of digits
  return sum;
}
