/**
 * @file special_numbers_test.cpp
 * @author Daniel Felipe <danielfoc@protonmail.com>
 * @date 06/03/2024
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <special_numbers.h>


SCENARIO( "#is_Harshad_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is a Harshad number" ){

      THEN( "must return true " ){
	REQUIRE(is_Harshad_number(2) == true);
	REQUIRE(is_Harshad_number(171) == true);
	REQUIRE(is_Harshad_number(12751220) == true);
	REQUIRE(is_Harshad_number(131052) == true);
      }
    }


    WHEN( "it is not a Harshad number" ){

      THEN( "must return false " ){
	REQUIRE(is_Harshad_number(11) == false);
	REQUIRE(is_Harshad_number(138) == false);
	REQUIRE(is_Harshad_number(5165) == false);
	REQUIRE(is_Harshad_number(7896003) == false);
      }
    }
  }
}


SCENARIO( "#is_strong_Harshad_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is a strong Harshad number" ){

      THEN( "must return true" ){
	REQUIRE(is_strong_Harshad_number(201) == true);
	REQUIRE(is_strong_Harshad_number(171) == true);
	REQUIRE(is_strong_Harshad_number(13194) == true);
	REQUIRE(is_strong_Harshad_number(198) == true);
      }
    }


    WHEN( "it is not a strong Harshad number" ){

      THEN( "must return false" ){
	REQUIRE(is_strong_Harshad_number(2) == false);
	REQUIRE(is_strong_Harshad_number(12751220) == false);
	REQUIRE(is_strong_Harshad_number(5165) == false);
	REQUIRE(is_strong_Harshad_number(7896003) == false);
      }
    }
  }
}



SCENARIO( "#is_right_truncatable_Harshad_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is a right truncatable Harshad number" ){

      THEN( "must return true" ){
	REQUIRE(is_right_truncatable_Harshad_number(201) == true);
	REQUIRE(is_right_truncatable_Harshad_number(2478) == true);
	REQUIRE(is_right_truncatable_Harshad_number(84063) == true);
	REQUIRE(is_right_truncatable_Harshad_number(4002038) == true);
      }
    }


    WHEN( "it is not a right truncatable Harshad number" ){

      THEN( "must return false" ){
	REQUIRE(is_right_truncatable_Harshad_number(11) == false);
	REQUIRE(is_right_truncatable_Harshad_number(12751220) == false);
	REQUIRE(is_right_truncatable_Harshad_number(89790) == false);
	REQUIRE(is_right_truncatable_Harshad_number(400237) == false);
      }
    }
  }
}



SCENARIO( "#is_strong_right_truncatable_Harshad_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is a strong right truncatable Harshad number" ){

      THEN( "must return true" ){
	REQUIRE(is_right_truncatable_Harshad_number(201) == true);
	REQUIRE(is_right_truncatable_Harshad_number(8406) == true);
	REQUIRE(is_right_truncatable_Harshad_number(40806) == true);
	REQUIRE(is_right_truncatable_Harshad_number(2408041) == true);
      }
    }


    WHEN( "it is not a strong right truncatable Harshad number" ){

      THEN( "must return false" ){
	REQUIRE(is_right_truncatable_Harshad_number(211) == false);
	REQUIRE(is_right_truncatable_Harshad_number(12751220) == false);
	REQUIRE(is_right_truncatable_Harshad_number(89790) == false);
	REQUIRE(is_right_truncatable_Harshad_number(400237) == false);
      }
    }
  }
}



SCENARIO( "#is_S_number" ){

  GIVEN( "A positive number" ){

    WHEN( "it is a S number" ){

      THEN( "must return true" ){
	REQUIRE(is_S_number(81) == true);
	REQUIRE(is_S_number(6724) == true);
	REQUIRE(is_S_number(8281) == true);
	REQUIRE(is_S_number(9801) == true);
      }
    }


    WHEN( "it is not a S number" ){

      THEN( "must return false" ){
	REQUIRE(is_S_number(144) == false);
	REQUIRE(is_S_number(87683) == false);
	REQUIRE(is_S_number(897) == false);
	REQUIRE(is_S_number(400237) == false);
      }
    }
  }
}
