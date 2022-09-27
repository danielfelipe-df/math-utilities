/**
 * @file divisors_test.cpp
 * @author Daniel Felipe
 * @date 26/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions
 */


#include <catch.hpp>

#include <divisors.h>


SCENARIO( "#gcd_euclides" ){

  GIVEN( "Two positive numbers" ){

    WHEN( "are relative primes" ){

      THEN( "must return 1" ){
	REQUIRE(gcd_euclides(10, 13) == 1);
	REQUIRE(gcd_euclides(101, 3) == 1);
	REQUIRE(gcd_euclides(5, 26) == 1);
	REQUIRE(gcd_euclides(1479, 2) == 1);
      }
    }

    WHEN( "are not-relative primes" ){

      THEN( "must return gcd" ){
	REQUIRE(gcd_euclides(2, 8) == 2);
	REQUIRE(gcd_euclides(105, 60) == 15);
	REQUIRE(gcd_euclides(33, 33) == 33);
	REQUIRE(gcd_euclides(18, 27) == 9);
      }
    }
  }
}


SCENARIO( "#gcd_stein" ){

  GIVEN( "Two positive numbers" ){

    WHEN( "are relative primes" ){

      THEN( "must return 1" ){
	REQUIRE(gcd_stein(10, 13) == 1);
	REQUIRE(gcd_stein(101, 3) == 1);
	REQUIRE(gcd_stein(5, 26) == 1);
	REQUIRE(gcd_stein(1479, 2) == 1);
      }
    }

    WHEN( "are not-relative primes" ){

      THEN( "must return gcd" ){
	REQUIRE(gcd_stein(2, 8) == 2);
	REQUIRE(gcd_stein(105, 60) == 15);
	REQUIRE(gcd_stein(33, 33) == 33);
	REQUIRE(gcd_stein(18, 27) == 9);
      }
    }
  }
}


SCENARIO( "#num_divisors" ){

  GIVEN( "A positive number" ){

    THEN( "must return count of divisors" ){
      REQUIRE(num_divisors(2) == 2);
      REQUIRE(num_divisors(15) == 4);
      REQUIRE(num_divisors(96) == 12);
      REQUIRE(num_divisors(103) == 2);
    }
  }
}


SCENARIO( "#sum_divisors" ){

  GIVEN( "A positive number" ){

    THEN( "must return sum of divisors" ){
      REQUIRE(sum_divisors(2) == 3);
      REQUIRE(sum_divisors(15) == 24);
      REQUIRE(sum_divisors(48) == 124);
      REQUIRE(sum_divisors(67) == 68);
    }
  }
}
