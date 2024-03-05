/**
 * @file other_functions.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 02/09/2022
 * @brief
 */


#include <string>
#include <gmp.h>


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
void SRHTP_number(unsigned long int num, unsigned int sum_dig, unsigned long int &sum, unsigned long int limit);


/**
 * @brief Evaluate the Euler's Totient function for the value @p n using the
 * property \phi(n) = n\prod_{p|n}(1 - 1/p) where p is a prime who divides @p n.
 * The algorithm used is a self variation of the last count found in
 * @see https://www.geeksforgeeks.org/eulers-totient-function/
 * @param n Number to be evaluated
 * @return \phi(n)
 */
unsigned int Euler_Totient_Function(unsigned int n);


/**
 * @brief Return the sum of all amicable numbers that are in @p y and are less
 * than @p N.
 * @param y Array containing the sum of divisors less than itself.
 * @param N Upper limit number for the amicable numbers. Also is the @p y 's size.
 * @return Sum of amicable numbers less than @p N.
 */
unsigned int sum_amicable_numbers(unsigned int *y, unsigned int N);


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


/**
 * @brief Boolean function that tell us if @p n2 is S-number.
 * @param n2 Number to be checked.
 * @param n @p n2 square root.
 * @return Boolean.
 */
bool is_S_number(std::string n2, long int n);
