/**
 * @file other_functions.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 02/09/2022
 * @brief
 */


#include <string>
#include <gmp.h>


/**
 * @brief Transform @p num in base2. The transformation is using bitiwse
 * operator. Check the link to learn it
 * @see https://www.learncpp.com/cpp-tutorial/bitwise-operators/
 * @param num Base10 number
 * @return @p num in Base2
 */
std::string base10_to_base2(unsigned int num);


/**
 * @brief Check if the string @p s is
 * @param s String to be checked
 * @return True if @p s is palindrome, False if not
 */
bool string_is_palindrome(std::string s);


/**
 * @brief This function save the prime decomposition in the array @p myarray
 * if it is not saved yet. It is an cumulative array.
 * The algorithm used is a self variation of the last count found in
 * @see https://www.geeksforgeeks.org/eulers-totient-function/
 * @param n Number to be done the decomposition
 * @param myarray Array where the decomposition is saved. The index zero
 * corresponds to number 2, one to 3 and then.
 */
void Cummulative_Prime_Decomposition(unsigned int n, unsigned int *myarray);
