/**
 * @file fractions.h
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 26/09/2022
 * @brief
 */


#ifndef FRACTIONS_H
#define FRACTIONS_H


/**
 * @brief Check if the fraction @p numerator / * @p denominator is a terminating
 * decimal. For example, 1/6 = 0.1(6) is a non-terminating decimal because has
 * a cycle. In the case 1/7 = 0.(142857) we get a non-terminating decimal. And
 * 1/4 = 0.25 is a terminating decimal, is not periodical and finite.
 * @param numerator Fraction's numerator
 * @param denominator Fraction's numerator
 * @return True if is terminating decimal, False if not.
 */
bool is_terminating_decimal(unsigned long int numerator, unsigned long int denominator);


/**
 * @brief Check if the fraction @p numerator / * @p denominator is a terminating
 * decimal. For example, 1/6 = 0.1(6) is a non-terminating decimal because has
 * a cycle. In the case 1/7 = 0.(142857) we get a non-terminating decimal. And
 * 1/4 = 0.25 is a terminating decimal, is not periodical and finite.
 * This algrithm use the fact that if the denominator is only divisible by 2
 * and/or 5 then is terminating decimal.
 * @param numerator Fraction's numerator
 * @param denominator Fraction's numerator
 * @return True if is terminating decimal, False if not.
 */
bool is_terminating_decimal_2(unsigned long int numerator, unsigned long int denominator);


/**
 * @brief Calculate the length of decimal cycle of the fraction @p numerator /
 * @p denominator. For example, in 1/6 = 0.1(6) the length is 1 because is only
 * 6. In the case 1/7 = 0.(142857) the length is 6. And in the case 1/4 = 0.25
 * the result is 0 because there is no-cycle, is not periodical.
 * @param numerator Fraction's numerator
 * @param denominator Fraction's numerator
 * @return Size of cycle
 */
unsigned int size_decimal_cycle(unsigned int numerator, unsigned int denominator);


/**
 * @brief The function calculated the n-th position on the continued fraction of
 * sqrt(2)
 * @param nth The nth position on the continued fraction representation
 * @return The value in the @nth position
 */
int continued_fraction_sqrt_2(int nth);


/**
 * @brief The function calculated the n-th position on the continued fraction of
 * sqrt(23)
 * @param nth The nth position on the continued fraction representation
 * @return The value in the @nth position
 */
int continued_fraction_sqrt_23(int nth);


/**
 * @brief The function calculated the n-th position on the continued fraction of e
 * @param nth The nth position on the continued fraction representation
 * @return The value in the @nth position
 */
int continued_fraction_e(int nth);


/**
 * @brief Is a recursive function that calculate the numerator and denominator of
 * the continued fraction sum starting in the @p nth position
 * @param nth The nth position on the continued fraction representation
 * @param fraction Is an array with the actual values of numerator and denominator
 */
void calculate_continued_fraction(int nth, unsigned long int* fraction);


#endif
