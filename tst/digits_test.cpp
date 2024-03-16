/**
 * @file digits_test.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 21/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions for digits
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


SCENARIO( "#is_palindrome" ){

  GIVEN( "An integer positive number" ){

    WHEN( "it is a palindrome number" ){

      THEN( "must return true"){
	REQUIRE(is_palindrome(12321) == true);
	REQUIRE(is_palindrome(1221) == true);
	REQUIRE(is_palindrome(98766789) == true);
	REQUIRE(is_palindrome(101) == true);
      }
    }

    WHEN( "it is not a palindrome number" ){

      THEN( "must return false"){
	REQUIRE(is_palindrome(1321) == false);
	REQUIRE(is_palindrome(12681) == false);
	REQUIRE(is_palindrome(99769976) == false);
	REQUIRE(is_palindrome(10) == false);
      }
    }
  }
}


SCENARIO( "#reverse" ){

  GIVEN( "An integer positive number" ){

    THEN( "must return it's reverse number"){
      REQUIRE(reverse(12000) == 21);
      REQUIRE(reverse(1221) == 1221);
      REQUIRE(reverse(98398872) == 27889389);
      REQUIRE(reverse(101011) == 110101);
    }
  }
}


SCENARIO( "#sum_digits" ){

  GIVEN( "A positive number" ){

    THEN( "must return the sum of its digits" ){
      REQUIRE(sum_digits(1234) == 10);
      REQUIRE(sum_digits(778899) == 48);
      REQUIRE(sum_digits(1333579) == 31);
      REQUIRE(sum_digits(268) == 16);
    }
  }
}


SCENARIO( "#sum_digits_string" ){

  GIVEN( "A string of numbers" ){

    THEN( "must return the sum of its digits" ){
      REQUIRE(sum_digits_string("1234") == 10);
      REQUIRE(sum_digits_string("778899") == 48);
      REQUIRE(sum_digits_string("1333579") == 31);
      REQUIRE(sum_digits_string("268") == 16);
    }
  }
}
