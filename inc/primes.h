/**
 * @file primes.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 15/09/2022
 * @brief Algorithms associated to prime numbers
 */



#ifndef PRIMES_H
#define PRIMES_H


#include <cstddef>



/**
 * @brief The function check if @p num is prime or not
 * @param num Number to be checked
 * @return True if is prime, otherwise False
 */
bool is_prime(unsigned long int num);


/**
 * @brief The function check if all @p num divisors return a *d+num/d* prime
 * @param num Number to be checked
 * @return True if all @p num divisors give *d+num/d* prime, otherwise False
 */
bool is_rare_prime(unsigned int num);


/**
 * @brief The function check if @p num is prime or not.
 * @param num Odd number to be checked
 * @return True if is prime, False if not
 */
bool is_odd_prime(unsigned int num);


/**
 * @brief Evaluate the Euler's Totient function for the value @p n using the
 * property $\phi(n) = n\prod_{p|n}(1 - 1/p)$ where p is a prime who divides
 * @p n.The algorithm used is a self variation of the last count found in
 * @see https://www.geeksforgeeks.org/eulers-totient-function/
 * @param n Number to be evaluated
 * @return \phi(n)
 */
size_t calculate_euler_totient_function(size_t n);



#endif
