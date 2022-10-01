/**
 * @file fractions_test.cpp
 * @author Daniel Felipe
 * @date 26/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions
 */


#include <catch.hpp>

#include <fractions.h>


SCENARIO( "#is_terminating_decimal" ){

  GIVEN( "Numerator and denominator positives" ){

    WHEN( "construct a terminating decimal fraction" ){

      THEN( "must return true" ){
	REQUIRE(is_terminating_decimal(1, 2) == true);
	REQUIRE(is_terminating_decimal(1, 500) == true);
	REQUIRE(is_terminating_decimal(36, 12) == true);
	REQUIRE(is_terminating_decimal(1479, 20) == true);
      }
    }

    WHEN( "construct a non-terminating decimal fraction" ){

      THEN( "must return false" ){
	REQUIRE(is_terminating_decimal(1, 3) == false);
	REQUIRE(is_terminating_decimal(1, 551) == false);
	REQUIRE(is_terminating_decimal(32, 7) == false);
	REQUIRE(is_terminating_decimal(1479, 31) == false);
      }
    }
  }
}


SCENARIO( "#is_terminating_decimal_2" ){

  GIVEN( "Numerator and denominator positives" ){

    WHEN( "construct a terminating decimal fraction" ){

      THEN( "must return true" ){
	REQUIRE(is_terminating_decimal_2(1, 2) == true);
	REQUIRE(is_terminating_decimal_2(1, 500) == true);
	REQUIRE(is_terminating_decimal_2(36, 12) == true);
	REQUIRE(is_terminating_decimal_2(1479, 20) == true);
      }
    }

    WHEN( "construct a non-terminating decimal fraction" ){

      THEN( "must return false" ){
	REQUIRE(is_terminating_decimal_2(1, 3) == false);
	REQUIRE(is_terminating_decimal_2(1, 551) == false);
	REQUIRE(is_terminating_decimal_2(32, 7) == false);
	REQUIRE(is_terminating_decimal_2(1479, 31) == false);
      }
    }
  }
}


SCENARIO( "#size_decimal_cycle" ){

  GIVEN( "Numerator and denominator positives" ){

    THEN( "return the size of decimal cycle" ){
      REQUIRE(size_decimal_cycle(1, 2) == 0);
      REQUIRE(size_decimal_cycle(32, 7) == 6);
      REQUIRE(size_decimal_cycle(1, 555) == 3);
      REQUIRE(size_decimal_cycle(1479, 31) == 15);
    }
  }
}


SCENARIO( "#continued_fraction_sqrt_2" ){

  GIVEN( "nth positive" ){

    WHEN( "is equal to 1" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_sqrt_2(1) == 1);
      }
    }

    WHEN( "is different to 1" ){

      THEN( "must return 2" ){
	REQUIRE(continued_fraction_sqrt_2(5) == 2);
	REQUIRE(continued_fraction_sqrt_2(13) == 2);
	REQUIRE(continued_fraction_sqrt_2(31) == 2);
	REQUIRE(continued_fraction_sqrt_2(198) == 2);
      }
    }
  }

  GIVEN( "nth less or equal than zero" ){

    THEN( "must throw error" ){
      REQUIRE_THROWS(continued_fraction_sqrt_2(0));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-1));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-7861));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-352));
    }
  }
}


SCENARIO( "#continued_fraction_sqrt_23" ){

  GIVEN( "nth positive" ){

    WHEN( "is equal to 1" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_sqrt_23(1) == 4);
      }
    }

    WHEN( "is nth%4 == 0" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_sqrt_23(4) == 1);
	REQUIRE(continued_fraction_sqrt_23(16) == 1);
	REQUIRE(continued_fraction_sqrt_23(84) == 1);
	REQUIRE(continued_fraction_sqrt_23(872) == 1);
      }
    }

    WHEN( "is nth%4 == 1" ){

      THEN( "must return 8" ){
	REQUIRE(continued_fraction_sqrt_23(5) == 8);
	REQUIRE(continued_fraction_sqrt_23(21) == 8);
	REQUIRE(continued_fraction_sqrt_23(101) == 8);
	REQUIRE(continued_fraction_sqrt_23(909) == 8);
      }
    }

    WHEN( "is nth%4 == 2" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_sqrt_23(2) == 1);
	REQUIRE(continued_fraction_sqrt_23(10) == 1);
	REQUIRE(continued_fraction_sqrt_23(74) == 1);
	REQUIRE(continued_fraction_sqrt_23(638) == 1);
      }
    }

    WHEN( "is nth%4 == 3" ){

      THEN( "must return 3" ){
	REQUIRE(continued_fraction_sqrt_23(7) == 3);
	REQUIRE(continued_fraction_sqrt_23(19) == 3);
	REQUIRE(continued_fraction_sqrt_23(95) == 3);
	REQUIRE(continued_fraction_sqrt_23(731) == 3);
      }
    }
  }

  GIVEN( "nth less or equal than zero" ){

    THEN( "must throw error" ){
      REQUIRE_THROWS(continued_fraction_sqrt_2(0));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-1));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-7861));
      REQUIRE_THROWS(continued_fraction_sqrt_2(-352));
    }
  }
}


SCENARIO( "#continued_fraction_e" ){

  GIVEN( "nth positive" ){

    WHEN( "is equal to 1" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_e(1) == 2);
      }
    }

    WHEN( "is divisble by 3" ){

      THEN( "must return 2*(nth/3)" ){
	REQUIRE(continued_fraction_e(3) == 2*(3/3));
	REQUIRE(continued_fraction_e(33) == 2*(33/3));
	REQUIRE(continued_fraction_e(312) == 2*(312/3));
	REQUIRE(continued_fraction_e(555) == 2*(555/3));
      }
    }

    WHEN( "is not divisble by 3" ){

      THEN( "must return 1" ){
	REQUIRE(continued_fraction_e(2) == 1);
	REQUIRE(continued_fraction_e(301) == 1);
	REQUIRE(continued_fraction_e(412) == 1);
	REQUIRE(continued_fraction_e(803) == 1);
      }
    }
  }

  GIVEN( "nth less or equal than zero" ){

    THEN( "must throw error" ){
      REQUIRE_THROWS(continued_fraction_e(0));
      REQUIRE_THROWS(continued_fraction_e(-1));
      REQUIRE_THROWS(continued_fraction_e(-7861));
      REQUIRE_THROWS(continued_fraction_e(-352));
    }
  }
}


SCENARIO( "#calculate_continued_fraction" ){

  GIVEN( "nth equal to zero" ){
    unsigned long int fraction[2] = {0, 2};

    THEN( "must return same fraction" ){
      calculate_continued_fraction(0, fraction);
      REQUIRE(fraction[0] == 0);
      REQUIRE(fraction[1] == 2);
    }
  }

  GIVEN( "nth positive" ){

    THEN( "must calculate the continued fraction" ){
      unsigned long int fractionResult1[2] = {1, 0};
      calculate_continued_fraction(1, fractionResult1);
      REQUIRE(fractionResult1[0] == 2);
      REQUIRE(fractionResult1[1] == 1);

      unsigned long int fractionResult10[2] = {1, 0};
      calculate_continued_fraction(10, fractionResult10);
      REQUIRE(fractionResult10[0] == 1457);
      REQUIRE(fractionResult10[1] == 536);
    }
  }

  GIVEN( "nth less than zero" ){
    unsigned long int fraction[2] = {3, 5};

    THEN( "must throw error" ){
      REQUIRE_THROWS(calculate_continued_fraction(-1, fraction));
      REQUIRE_THROWS(calculate_continued_fraction(-7861, fraction));
      REQUIRE_THROWS(calculate_continued_fraction(-352, fraction));
    }
  }
}
