/**
 * @file primes_test.cpp
 * @author Daniel Felipe
 * @date 15/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <primes.h>


SCENARIO( "#is_prime" ){

  GIVEN( "A positive number" ){

    WHEN( "it is 2" ){

      THEN( "must return true " ){
	REQUIRE(is_prime(2) == true);
      }
    }

    WHEN( "it is even greater than 2" ){

      THEN( "must return false " ){
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(8) == false);
	REQUIRE(is_prime(5065) == false);
	REQUIRE(is_prime(78966) == false);
      }
    }

    WHEN( "it is a prime number" ){

      THEN( "must return true" ){
	REQUIRE(is_prime(13) == true);
	REQUIRE(is_prime(643) == true);
	REQUIRE(is_prime(5653) == true);
	REQUIRE(is_prime(7919) == true);
      }
    }

    WHEN( "it is not a prime number" ){

      THEN( "must return false" ){
	REQUIRE(is_prime(15) == false);
	REQUIRE(is_prime(651) == false);
	REQUIRE(is_prime(7917) == false);
	REQUIRE(is_prime(791913) == false);
      }
    }
  }
}


SCENARIO( "#is_rare_prime" ){

  GIVEN( "A positive number"){

    WHEN( "it is a 'rare' prime" ){

      THEN( "must return true" ){
	REQUIRE(is_rare_prime(30) == true);
      }
    }

    WHEN( "it is not a 'rare' prime" ){

      THEN( "must return false" ){
	REQUIRE(is_rare_prime(31) == false);
      }
    }
  }
}


SCENARIO( "#is_odd_prime" ){

  GIVEN( "A positive odd_number" ){

    WHEN( "it is a prime number" ){

      THEN( "must return true" ){
	REQUIRE(is_odd_prime(13) == true);
	REQUIRE(is_odd_prime(643) == true);
	REQUIRE(is_odd_prime(5653) == true);
	REQUIRE(is_odd_prime(7919) == true);
      }
    }

    WHEN( "it is not a prime number" ){

      THEN( "must return false" ){
	REQUIRE(is_odd_prime(15) == false);
	REQUIRE(is_odd_prime(651) == false);
	REQUIRE(is_odd_prime(7917) == false);
	REQUIRE(is_odd_prime(791913) == false);
      }
    }
  }
}



SCENARIO( "#calculate_euler_totient_function" ){

  GIVEN( "A positive number" ){

    THEN( "must return the value of euler totient function" ){
      REQUIRE(calculate_euler_totient_function(53) == 52);
      REQUIRE(calculate_euler_totient_function(798988) == 378432);
      REQUIRE(calculate_euler_totient_function(10000) == 4000);
      REQUIRE(calculate_euler_totient_function(7392879200) == 2534699520);
    }
  }
}
