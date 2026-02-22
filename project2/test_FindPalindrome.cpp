#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

/* Provided test cases */

TEST_CASE("Test recursion", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test recursion 2", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("Borrow"));
	REQUIRE(b.add("or"));
	REQUIRE(b.add("Rob"));
	REQUIRE(b.number() == 1);
}

TEST_CASE("Test recursion 3", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("Murder"));
	REQUIRE(b.add("for"));
	REQUIRE(b.add("a"));
	REQUIRE(b.add("jar"));
	REQUIRE(b.add("of"));
	REQUIRE(b.add("red"));
	REQUIRE(b.add("rum"));	
	REQUIRE(b.number() == 2);
}

