/**
 * @file divisors.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 26/09/2022
 * @brief
 */


#ifndef DIVISORS_H
#define DIVISORS_H

#include <cstddef>
#include <vector>


/**
 * @brief Return the GCD (Greates Common Divisor) or HCF (Highest Common Factor)
 * usign Euclides algorithm
 * @param m First number
 * @param n Second number
 * @return GCD of @p m and @p n
 */
size_t gcd_euclides(size_t m, size_t n);


/**
 * @brief Return the GCD (Greates Common Divisor) or HCF (Highest Common Factor)
 * usign Stein's algorithm or binary GCD algorithm
 * @param m First number
 * @param n Second number
 * @return GCD of @p m and @p n
 */
size_t gcd_stein(size_t m, size_t n);


/**
 * @brief Return the number of divisors of @p num.
 * @param num Number for which divisors are sought.
 * @return Number of divisors.
 */
size_t num_divisors(size_t num);


/**
 * @brief Return the sum of @p num 's divisors less than @p num.
 * @param num Number for which sum of divisors is done.
 * @return Sum of divisors less than @p num.
 */
size_t sum_divisors(size_t num);


/**
 * @brief Return a vector with all prime divisors of @p num
 * @param num Number to be find its prime divisors
 * @return Vector with all, and unique, primes divisors of @p num
 */
std::vector<size_t> get_prime_divisors_vector(size_t num);


#endif
