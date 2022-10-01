/**
 * @file fractions.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 26/09/2022
 * @brief
 */


#include <fractions.h>

#include <divisors.h>

#include <vector>
#include <algorithm>
#include <map>
#include <string>


bool is_terminating_decimal(unsigned long int numerator, unsigned long int denominator){
  // Create a vector to store already seen remainders. If it appears again
  // then is a non-terminating decimal.
  std::vector<unsigned long int> remainders;
  remainders.clear();

  // Calculate GCD in order to reduce numerator and denominator to minimum values
  // and then do easier calculates
  unsigned long int gcd = gcd_euclides(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;

  // Find first remainder
  unsigned long int remainder = numerator%denominator;

  // Keep finding remainder until either remainder becomes 0 (no-cycle)
  // or repeats (end of cycle)
  while(remainder != 0 and std::find(remainders.begin(), remainders.end(), remainder) == remainders.end()){

    // Store this remainder
    remainders.push_back(remainder);

    // Multiply remainder with 10 in order to divide it again
    remainder *= 10;

    // Update remainder
    remainder = remainder%denominator;
  }

  // If remainder is zero then is a terminating decimal
  return remainder == 0;
}


bool is_terminating_decimal_2(unsigned long int numerator, unsigned long int denominator){
  // If denominator divides numerator then the fraction is an integer, so is terminating
  if(numerator%denominator == 0)
    return true;

  // Calculate GCD in order to reduce numerator and denominator to minimum values
  // and then do easier calculates
  unsigned long int gcd = gcd_euclides(numerator, denominator);
  denominator /= gcd;

  // Divides denominator by 2 if is divisible
  while(denominator%2 == 0)
    denominator /= 2;

  // Divides denominator by 5 if is divisible
  while(denominator%5 == 0)
    denominator /= 5;

  // If denominator is equal to 1 then it is only divisible by 2 and/or 5,
  // so is terminating decimal. Otherwise is not.
  return denominator == 1;
}


unsigned int size_decimal_cycle(unsigned int numerator, unsigned int denominator){
  // Initialize string result
  std::string decimals;

  // Create a map to store already seen remainders. Remainder is used
  // as key and its position in result is stored as value.
  // Note that we need position for cases like 1/6 = 0.1(6), In this case,
  // the recurring sequence doesn't start from first remainder.
  std::map<int, int> remainderPosition;
  remainderPosition.clear();

  // Calculate GCD in order to reduce numerator and denominator to minimum values
  // and then do easier calculates
  unsigned long int gcd = gcd_euclides(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;

  // Find first remainder
  unsigned int remainder = numerator%denominator, decimal;

  // Keep finding remainder until either remainder becomes 0 (no-cycle)
  // or repeats (end of cycle)
  while(remainder != 0 and remainderPosition.find(remainder) == remainderPosition.end()){
    // Store this remainder
    remainderPosition[remainder] = decimals.length();

    // Multiply remainder with 10 in order to divide it again
    remainder *= 10;

    // Append rem/denr (new decimal) to result
    decimal = remainder/denominator;
    decimals += std::to_string(decimal);

    // Update reminder
    remainder = remainder%denominator;
  }

  // Return the length of the cycle
  return (remainder == 0) ? 0 : decimals.substr(remainderPosition[remainder]).length();
}


int continued_fraction_sqrt_2(int nth){
  if(nth <= 0)
    throw std::invalid_argument("received non-positive value");

  // sqrt(2) = [1; (2)]
  if(nth == 1) return 1;
  else return 2;
}


int continued_fraction_sqrt_23(int nth){
  if(nth <= 0)
    throw std::invalid_argument("received non-positive value");

  // sqrt(23) = [4; (1, 3, 1, 8)]
  // Take into account that
  // 1 is positions 2, 6, 10, 14,..., i.e., nth%4 == 2
  // 3 is positions 3, 7, 11, 15,..., i.e., nth%4 == 3
  // 1 is positions 4, 8, 12, 16,..., i.e., nth%4 == 0
  // 8 is positions 5, 9, 13, 17,..., i.e., nth%4 == 1
  if(nth == 1) return 4;

  int continued_value[4] = {1, 8, 1, 3};
  return continued_value[nth%4];
}


int continued_fraction_e(int nth){
  if(nth <= 0)
    throw std::invalid_argument("received non-positive value");

  // e = [2; 1, 2, 1, 1, 4, 1, 1, 6, 1,..., 1, 2k, 1,...]
  // Take into account that
  // All values (except first) that are no-1 are in position 3, 6, 9, 12,...
  if(nth == 1) return 2;

  if(nth%3 == 0) return 2*(nth/3);
  else return 1;
}


void calculate_continued_fraction(int nth, unsigned long int* fraction){
  // If the position to be calculated is 0, then finished recursion and
  // return the last fraction
  if(nth == 0)
    return;

  // If the position is equal or greater than 1 continue recursion
  if(nth >= 1){
    //mpz_t valueInNth, newNumerator, newDenominator, ValueTimesNumerator;
    unsigned long int newNumerator, newDenominator;

    // Set valueInNth as the value in the nth position
    //mpz_init_set_si(valueInNth, (long int)continuedFractionE(nth));
    //valueInNth = continuedFractionE(nth);

    // Calculate newNumerator as equal to valueInNth*fraction[0] + fraction[1]
    //mpz_inits(newNumerator, ValueTimesNumerator);
    //mpz_mul(ValueTimesNumerator, fraction[0], valueInNth);
    //mpz_add(newNumerator, ValueTimesNumerator, fraction[1]);
    newNumerator = fraction[0]*continued_fraction_e(nth) + fraction[1];

    // Calculate newDenominator as equal to fraction[0]
    //mpz_init_set(newDenominator, fraction[0]);
    newDenominator = fraction[0];

    // Save the newNumerator and newDenominator
    //mpz_set(fraction[0], newNumerator);
    //mpz_set(fraction[1], newDenominator);
    fraction[0] = newNumerator;
    fraction[1] = newDenominator;

    // Continue with recursion to the next (nth-1) position
    return calculate_continued_fraction(nth-1, fraction);
  }

  // Otherwise throw error
  throw std::invalid_argument("received non-positive value");
}
