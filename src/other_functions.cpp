/**
 * @file other_functions.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 02/09/2022
 * @brief
 */


#include <iostream>
#include <string>


void SRHTP_number(unsigned long int num, unsigned int sum_dig, unsigned long int &sum, unsigned long int limit){
  // Check if the num is less than the limit
  if(num < limit){
    // Loop over all possible new digits
    for(unsigned long int i=0; i<10; i++){
      // Check if the new constructed number, based on num (a Harshad number), is a Harshad number too
      if(Harshad_number(num*10 + i, sum_dig + i)){

	// Check if the new constructed number is a strong Harshad number
	if(strong_Harshad_number(num*10 + i, sum_dig + i)){

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


unsigned int sum_amicable_numbers(unsigned int *y, unsigned int N){
  unsigned int sum = 0;
  for(unsigned int i=2; i<N; i++){ // Loop over all values less than N and greater than 1
    if(y[i] < N){ // Check the sum of divisors is less than N
      if(i == y[y[i]] && i != y[i]){ // Check the number has an amicable different of itself
	sum += i;
      }
    }
  }
  return sum;
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


bool is_S_number(std::string n2, long int n){
  // Save all digits of n2.
  // Take care that, e.g, 1234 is saved as {1,2,3,4}
  std::vector<std::string> digits;
  for(unsigned int i=0; i!=n2.length(); i++) digits.push_back(n2.substr(i,1));

  // If is a 2-digits number there is only 1 possiblity
  if(digits.size() == 2) return (std::stol(digits[0]) + std::stol(digits[1])) == n;

  std::vector<std::vector<std::string> > combinations;
  std::vector<std::string> current_vector;

  // Set initial combinations for ab...

  // This combination is {a, b}
  current_vector.push_back(digits[0]);
  current_vector.push_back(digits[1]);
  combinations.push_back(current_vector);
  current_vector.clear();

  // This combination is {ab}
  current_vector.push_back(digits[0]);
  current_vector[0].append(digits[1]);
  combinations.push_back(current_vector);
  current_vector.clear();

  unsigned int comb_size;
  for(unsigned int i=2; i!=digits.size(); i++){
    comb_size = combinations.size();
    for(unsigned int j=0; j!=comb_size; j++){
      // Copy the vector in order to a modification
      current_vector.clear();
      current_vector.resize(combinations[j].size());
      std::copy(combinations[j].begin(), combinations[j].end(), current_vector.begin());

      // Append the digit to last access as joined
      current_vector[current_vector.size()-1].append(digits[i]);
      if(std::stol(current_vector[current_vector.size()-1]) <= n) combinations.push_back(current_vector);

      // Append the digit alone
      combinations[j].push_back(digits[i]);
    }
  }

  // Sum over each combination and check if is equal to @p n
  long int sum;
  for(unsigned int i=0; i<combinations.size(); i++){
    sum = 0;
    for(unsigned int j=0; j<combinations[i].size(); j++) sum += std::stol(combinations[i][j]);
    if(sum == n) return true;
  }

  return false;
}
