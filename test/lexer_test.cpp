#include <catch2/catch_test_macros.hpp>


#include "../src/lexer.cpp"


TEST_CASE("Function Header: def", "[lexer]")  {
  REQUIRE(getTokenType("def") == Token::DEFINE);
}

TEST_CASE("Statement Start: do", "[lexer]")  {
  REQUIRE(getTokenType("do") == Token::DO);
}

TEST_CASE("Statement Finish: end", "[lexer]")  {
  REQUIRE(getTokenType("do") == Token::END);
}

TEST_CASE("Variable Naming: [A-Za-z_]", "[lexer]")  {
  REQUIRE(getTokenType("helloWorld") == Token::IDENT);
}

TEST_CASE("Literal: [0-9]", "[lexer]")  {
  REQUIRE(getTokenType("856") == Token::INT);
}

TEST_CASE("Assignment: =", "[lexer]")  {
  REQUIRE(getTokenType("=") == Token::ASSIGN);
}

TEST_CASE("Addition: +", "[lexer]")  {
  REQUIRE(getTokenType("+") == Token::PLUS);
}

TEST_CASE("Delimiter Open: (", "[lexer]")  {
  REQUIRE(getTokenType("(") == Token::LPAREN);
}

TEST_CASE("Delimiter Close: )", "[lexer]")  {
  REQUIRE(getTokenType(")") == Token::RPAREN);
}
