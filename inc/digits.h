/**
 * @file digits.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 21/09/2022
 * @brief Header file of file which are mainly related to digits
 */


#ifndef DIGITS_H
#define DIGITS_H


#include <string>


/**
 * @brief The function check if @p num is an increasing number (the digits,
 * from left to right, are always equal or greater)
 * @param num Number to be checked
 * @return True if it is an increasing number, otherwise False
 */
bool is_increasing_number(size_t num);


/**
 * @brief The function check if @p num is a decreasing number (the digits,
 * from left to right, are always equal or smaller)
 * @param num Number to be checked
 * @return True if it is a decreasing number, otherwise False
 */
bool is_decreasing_number(size_t num);


/**
 * @brief The function check if @p num is a bouncy number, i.e., neither
 * increasing nor decreasing number.
 * @param num Number to be checked.
 * @return True if it is a bouncy number, otherwise False
 */
bool is_bouncy_number(size_t num);


/**
 * @brief Check if @p num is palindrome
 * @param num Number to be checked
 * @return True if @p num is palindrome, False if not
 */
bool is_palindrome(size_t num);


/**
 * @brief Return the reverse of @p num
 * @param num Number to be reversed
 * @return @p num but reversed
 */
size_t reverse(size_t num);


/**
 * @brief Sum digits via decomposition of the number
 * @param num Number to be summed
 * @return Sum of @p num digits
 */
size_t sum_digits(size_t num);


/**
 * @brief Sum digits via ASCII code
 * @param num String number to be summed
 * @return Sum of @p num digits
 */
size_t sum_digits_string(std::string num);


#endif
