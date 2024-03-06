/**
 * @file primes.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 15/09/2022
 * @brief Algorithms associated to prime numbers
 */

#ifndef PRIMES_H
#define PRIMES_H


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


#endif
