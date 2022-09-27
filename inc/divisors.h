/**
 * @file divisors.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 26/09/2022
 * @brief
 */


#ifndef DIVISORS_H
#define DIVISORS_H


/**
 * @brief Return the GCD (Greates Common Divisor) or HCF (Highest Common Factor)
 * usign Euclides algorithm
 * @param m First number
 * @param n Second number
 * @return GCD of @p m and @p n
 */
unsigned int gcd_euclides(unsigned int m, unsigned int n);


/**
 * @brief Return the GCD (Greates Common Divisor) or HCF (Highest Common Factor)
 * usign Stein's algorithm or binary GCD algorithm
 * @param m First number
 * @param n Second number
 * @return GCD of @p m and @p n
 */
unsigned int gcd_stein(unsigned int m, unsigned int n);


/**
 * @brief Return the number of divisors of @p num.
 * @param num Number for which divisors are sought.
 * @return Number of divisors.
 */
unsigned int num_divisors(unsigned int num);


/**
 * @brief Return the sum of @p num 's divisors less than @p num.
 * @param num Number for which sum of divisors is done.
 * @return Sum of divisors less than @p num.
 */
unsigned int sum_divisors(unsigned int num);


#endif
