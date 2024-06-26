/**
 * @file special_numbers.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 17/09/2022
 * @brief
 */

#include <cstddef>


/**
 * @brief A *Harshad number* is a number that is divisible by the sum of its
 * digits.
 * @param num Number to be tested as a Harshad number.
 * @return True if is a Harshad number, False otherwise.
 */
bool is_Harshad_number(unsigned long int num);


/**
 * @brief A *strong Harshad number* is a Harshad number that, when divided by
 * the sum of its digits, results in a prime.
 * @param num Number to be tested as a strong Harshad number.
 * @return True if is a strong Harshad number, False otherwise.
 */
bool is_strong_Harshad_number(unsigned long int num);


/**
 * @brief A *right truncatable Harshad number* is a Harshad number that, when
 * is deleted its last digit to the right, the resulting number is Harshad too.
 * @param num Number to be tested as a right truncatable Harshad number.
 * @return True if is a right truncatable Harshad number, False otherwise.
 */
bool is_right_truncatable_Harshad_number(size_t num);


/**
 * @brief A *strong right truncatable Harshad number* is a number that, while
 * truncating the last digit, generates and strong and right truncatable Harshad
 * number.
 * @param num Number to be tested as a strong right truncatable Harshad number.
 * @return True if is a strong right truncatable Harshad number, False otherwise.
 */
bool is_strong_right_truncatable_Harshad_number(unsigned long int num);


/**
 * @brief A *S-number* is a natural number @p n that is a perfect square, and its
 * square root can be obtained by splitting the decimal representation of @p n
 * into 2 or more numbers then adding the numbers.
 * @param n Number to be checked.
 * @return True if @p n is S-number, False otherwise.
 */
bool is_S_number(size_t n);


/**
 * @brief A couple of numbers @p n and @p m are considered *amicable* if the sum
 * proper divisors of @p n is equal to @p m, and the sum of proper divisors (all
 * divisors except itself) of @p m is equal to @p n.
 * Note: If S(x) is the function to calculate sum of proper divisors, then for
 * @p n and @p m amicables we get S(n)+n = S(m)+m because S(n)=m and S(m)=n, and then
 * m+n=n+m. So it just necessary to check if the sum of all divisors of @p n and
 * @p m are equal.
 * @param n First number to be checked.
 * @param m Second number to be checked.
 * @return True if @p n is S-number, False otherwise.
 */
bool are_amicable_numbers(size_t n, size_t m);
