#include <catch2/catch_test_macros.hpp>


#include "lexer.cpp"


TEST_CASE("SMOKE TEST", "[main]") {
  REQUIRE(true);
}

TEST_CASE("= returns ASSIGN TokenType", "[lexer]")  {
  REQUIRE(getTokenType("=") == Token::ASSIGN);
}
