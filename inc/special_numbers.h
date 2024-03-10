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
 * is deleted its last digit to the right, the resulting number is Hardshad too.
 * @param num Number to be tested as a right truncatable Harshad number.
 * @return True if is a right truncatable Harshad number, False otherwise.
 */
bool is_right_truncatable_Harshad_number(size_t num);


/**
 * @brief A *right truncatable Harshad number* is a number that, while
 * recursively truncating the last digit, always results in a Harshard number.
 * In this algorithm we construct the greaters Harshad numbers from a Harshad
 * number given. If @p num is 1, then 12 is constructed. When a right
 * truncatable Harshard number is found, then we check if is SRHTP number. Then
 * add it to @p sum.
 * @param num Number to be tested as a right truncatable Harshad number.
 * @param sum_digit The sum digit of @p num.
 * @param sum Variable where we save the sum of SRHTP numbers.
 * @param limit Variable give the upper limit of Harshad numbers.
 * @return True if is a right truncatable Harshad number, False otherwise.
 */
//void SRHTP_number(unsigned long int num, unsigned int sum_dig, unsigned long int &sum, unsigned long int limit);
