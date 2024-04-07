/**
 * @file special_numbers.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 17/09/2022
 * @brief
 */


#include <special_numbers.h>

#include <digits.h>
#include <primes.h>
#include <divisors.h>

#include <vector>
#include <cmath>


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



bool is_S_number(size_t n){

  // Check if n is a perfect square, if not then return false to be S-number
  size_t square_n = std::sqrt(n);
  if(square_n*square_n != n)
    return false;

  // Convert n to string
  std::string n_string = std::to_string(n);

  // Save all digits of n_string.
  // Take care that, e.g, 1234 is saved as {1,2,3,4}
  std::vector<std::string> digits;
  for(size_t i=0; i!=n_string.length(); i++)
    digits.push_back(n_string.substr(i,1));

  // If is a 2-digits number there is only 1 possiblity
  if(digits.size() == 2)
    return (size_t)(std::stoi(digits[0]) + std::stoi(digits[1])) == square_n;

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

  size_t comb_size;
  for(size_t i=2; i!=digits.size(); i++){

    comb_size = combinations.size();
    for(size_t j=0; j!=comb_size; j++){

      // Copy the vector in order to a modification
      current_vector.clear();
      current_vector.resize(combinations[j].size());
      std::copy(combinations[j].begin(), combinations[j].end(), current_vector.begin());

      // Append the digit to last access as joined
      current_vector[current_vector.size()-1].append(digits[i]);
      if((size_t)std::stol(current_vector[current_vector.size()-1]) <= square_n)
	combinations.push_back(current_vector);

      // Append the digit alone
      combinations[j].push_back(digits[i]);
    }
  }

  size_t sum;
  // Sum over each combination and check if is equal to @p n
  for(size_t i=0; i<combinations.size(); i++){

    // Setup the sum variable to zero (0) and save the sum of the combination
    sum = 0;
    for(unsigned int j=0; j<combinations[i].size(); j++)
      sum += std::stol(combinations[i][j]);

    // If the sum is equal to @p n then is a S-number
    if(sum == square_n)
      return true;
  }

  // If any combination was equal to @p n then is not a S-number
  return false;
}



bool are_amicable_numbers(size_t n, size_t m){

  // If any of the numbers is greater than the sum of all numbers smaller than
  // other, so cannot be amicable
  if(m > n*(n+1)/2 or n > m*(m+1)/2)
    return false;

  // Use the function sum_divisors in digits file
  return sum_divisors(n) == sum_divisors(m);
}
