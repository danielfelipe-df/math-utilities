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
