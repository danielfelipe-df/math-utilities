/**
 * @file digits.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 21/09/2022
 * @brief
 */


#include <digits.h>


bool is_increasing_number(unsigned int num){
  // Init the variable with the smaller digit
  unsigned int digit = 9;

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


bool is_decreasing_number(unsigned int num){
  // Init the variable with the greater digit
  unsigned int digit = 0;

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


bool is_bouncy_number(unsigned int num){
  // If is decreasing or increasing number, then is not bouncy number
  if(is_decreasing_number(num) || is_increasing_number(num))
    return false;
  
  // If is not neither decreasing nor increasing, then is bouncy
  else
    return true;
}


bool is_palindrome(unsigned int num){
  // Check if num is igual to its reverse
  return num == reverse(num);
}


unsigned int reverse(unsigned int num){
  // Init reversed variable
  unsigned int reversed = 0;

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
