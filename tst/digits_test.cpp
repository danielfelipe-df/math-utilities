/**
 * @file digits_test.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 21/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <digits.h>


SCENARIO( "#is_increasing_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is an increasing number" ){

      THEN( "must return true" ){
	REQUIRE(is_increasing_number(1234) == true);
	REQUIRE(is_increasing_number(778899) == true);
	REQUIRE(is_increasing_number(1333579) == true);
	REQUIRE(is_increasing_number(2468) == true);
      }
    }

    WHEN( "it is a decreasing number" ){

      THEN( "must return false" ){
	REQUIRE(is_increasing_number(4321) == false);
	REQUIRE(is_increasing_number(998877) == false);
	REQUIRE(is_increasing_number(9753331) == false);
	REQUIRE(is_increasing_number(8642) == false);
      }
    }

    WHEN( "it is a bouncy number" ){

      THEN( "must return false" ){
	REQUIRE(is_increasing_number(1243) == false);
	REQUIRE(is_increasing_number(99879) == false);
	REQUIRE(is_increasing_number(1323569) == false);
	REQUIRE(is_increasing_number(2438) == false);
      }
    }
  }
}


SCENARIO( "#is_decreasing_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is an decreasing number" ){

      THEN( "must return false" ){
	REQUIRE(is_decreasing_number(1234) == false);
	REQUIRE(is_decreasing_number(778899) == false);
	REQUIRE(is_decreasing_number(1333579) == false);
	REQUIRE(is_decreasing_number(2468) == false);
      }
    }

    WHEN( "it is a decreasing number" ){

      THEN( "must return true" ){
	REQUIRE(is_decreasing_number(4321) == true);
	REQUIRE(is_decreasing_number(998877) == true);
	REQUIRE(is_decreasing_number(9753331) == true);
	REQUIRE(is_decreasing_number(8642) == true);
      }
    }

    WHEN( "it is a bouncy number" ){

      THEN( "must return false" ){
	REQUIRE(is_decreasing_number(1243) == false);
	REQUIRE(is_decreasing_number(99879) == false);
	REQUIRE(is_decreasing_number(1323569) == false);
	REQUIRE(is_decreasing_number(2438) == false);
      }
    }
  }
}


SCENARIO( "#is_bouncy_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is an increasing number" ){

      THEN( "must return false" ){
	REQUIRE(is_bouncy_number(1234) == false);
	REQUIRE(is_bouncy_number(778899) == false);
	REQUIRE(is_bouncy_number(1333579) == false);
	REQUIRE(is_bouncy_number(2468) == false);
      }
    }

    WHEN( "it is a decreasing number" ){

      THEN( "must return false" ){
	REQUIRE(is_bouncy_number(4321) == false);
	REQUIRE(is_bouncy_number(998877) == false);
	REQUIRE(is_bouncy_number(9753331) == false);
	REQUIRE(is_bouncy_number(8642) == false);
      }
    }

    WHEN( "it is a bouncy number" ){

      THEN( "must return true" ){
	REQUIRE(is_bouncy_number(1243) == true);
	REQUIRE(is_bouncy_number(99879) == true);
	REQUIRE(is_bouncy_number(1323569) == true);
	REQUIRE(is_bouncy_number(2438) == true);
      }
    }
  }
}
