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

/*
bool is_strong_right_truncatable_harshad_prime_number(unsigned long int num){

  // Check if num is prime
  if(is_prime(num)){

    size_t truncated_num = num/10;

  }

  // If not is prime, then is not SRTHP number
  return false;

  // Check if the num is less than the limit
  if(num < limit){
    // Loop over all possible new digits
    for(unsigned long int i=0; i<10; i++){
      // Check if the new constructed number, based on num (a Harshad number), is a Harshad number too
      if(is_Harshad_number(num*10 + i, sum_dig + i)){

	// Check if the new constructed number is a strong Harshad number
	if(is_strong_Harshad_number(num*10 + i, sum_dig + i)){

	  // Loop over odd digits, because those can be prime
	  for(unsigned int j=1; j<10; j+=2){
	    // Check if the new new constructed number is prime, and add.
	    if(is_prime((num*10 + i)*10 + j)){
	      sum += (num*10 + i)*10 + j;
	    }
	  }
	}

	// Look for the new right truncatable Harshad numbers based on the new one
	SRHTP_number(num*10 + i, sum_dig + i, sum, limit);
      }
    }
  }
}
*/
