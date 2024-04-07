/**
 * @file other_functions.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 02/09/2022
 * @brief
 */


#include <iostream>
#include <string>


unsigned int Euler_Totient_Function(unsigned int n){
  unsigned int result = n; //Init the result

  if(n%2 == 0){ // If n is even then reduce it to its odd form
    while(n%2 == 0){ // Reduce the number
      n /= 2;
    }
    result -= result/2; // Check that result = result*(1 - 1/p) = result - result/p, then result -= result/p
  }

  // We do the loop until sqrt because there's ony one prime number (if is exists) greater than sqrt and a divisor of n
  for(unsigned int i=3; i*i<=n; i+=2){ // Loop over all odd numbers because there is no an even prime number greater than 2.
    if(n%i == 0){ // Check if i divides n
      while(n%i == 0){ // Reduce the number n
	n /= i;
      }
      result -= result/i; // Update result
    }
  }

  //If n has a prime factor greater than n, then take it
  if(n > 1){
    result -= result/n;
  }

  return result;
}


std::string base10_to_base2(unsigned int num){
  std::string base2{};
  while(num > 0){ // While num is greater than 0.
    if(num%2 == 0){ // If num is even then save '0'.
      base2.insert(base2.begin(), '0');
    }
    else{ // If num is odd then save '1'.
      base2.insert(base2.begin(), '1');
    }
    // Move the bit representation of the number 1 location to the left.
    num >>= 1;
  }
  return base2;
}


bool string_is_palindrome(std::string s){
  for(size_t i=0; 2*i<s.size(); i++){ //Loop over the first half of the string
    if(s[i] != s[s.size()-(1+i)]){ // If are not equal, then is False
      return false;
    }
  }
  // If all are equal then is True
  return true;
}


void Cummulative_Prime_Decomposition(unsigned int n, unsigned int *myarray){
  // Variable saves the number of time the prime divides the number
  unsigned int count = 0;

  // If n is even then reduce it to its odd form
  if(n%2 == 0){

    // Init the counter
    count = 0;

    // Reduce the number and count
    while(n%2 == 0){
      n /= 2;
      count++;
    }

    // If count is greater than the value in the array, then save it. Otherwise, keep the same value
    myarray[0] = ((myarray[0] < count) ? count : myarray[0]);

  }

  // We do the loop until sqrt because there's ony one prime number (if is exists) greater than sqrt and a divisor of n
  for(unsigned int i=3; i*i<=n; i+=2){ // Loop over all odd numbers because there is no an even number greater than 2 prime.
    // Check if i divides n
    if(n%i == 0){

      // Init the counter
      count = 0;

      // Reduce the number n and add to the counter
      while(n%i == 0){
	n /= i;
	count++;
      }

      // If count is greater than the value in the array, then save it. Otherwise, keep the same value
      myarray[i-2] = ((myarray[i-2] < count) ? count : myarray[i-2]);
    }
  }

  //If n has a prime factor greater than sqrt n, then check if that number has a number greater than 1 in the array
  if(n > 1){
    myarray[n-2] = ((myarray[n-2] < 1) ? 1 : myarray[n-2]);
  }
}
