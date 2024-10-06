#include <catch2/catch_test_macros.hpp>


#include "../src/lexer.cpp"


TEST_CASE("Function Header: def", "[lexer]")  {
  REQUIRE(getTokenType("def") == TokenType::DEFINE);
}

TEST_CASE("Statement Start: do", "[lexer]")  {
  REQUIRE(getTokenType("do") == TokenType::DO);
}

TEST_CASE("Statement Finish: end", "[lexer]")  {
  REQUIRE(getTokenType("end") == TokenType::END);
}

TEST_CASE("Variable Naming: [A-Za-z_]", "[lexer]")  {
  REQUIRE(getTokenType("helloWorld") == TokenType::IDENT);
}

TEST_CASE("Literal: [0-9]", "[lexer]")  {
  REQUIRE(getTokenType("856") == TokenType::INT);
}

TEST_CASE("Assignment: =", "[lexer]")  {
  REQUIRE(getTokenType("=") == TokenType::ASSIGN);
}

TEST_CASE("Addition: +", "[lexer]")  {
  REQUIRE(getTokenType("+") == TokenType::PLUS);
}

TEST_CASE("Delimiter Open: (", "[lexer]")  {
  REQUIRE(getTokenType("(") == TokenType::LPAREN);
}

TEST_CASE("Delimiter Close: )", "[lexer]")  {
  REQUIRE(getTokenType(")") == TokenType::RPAREN);
}

TEST_CASE("Splits an expression into a string of tokens", "[lexer]") {
  std::vector<std::string> result = {"the", "brown", "cow"};
  REQUIRE(split("the brown cow", ' ') == result);
}

TEST_CASE("express the list of strings as Token", "[lexer]") {
  std::string input = "myvar = 856";

  Token* token1 = new Token(TokenType::IDENT, "myvar");
  Token* token2 = new Token(TokenType::ASSIGN, "=");
  Token* token3 = new Token(TokenType::INT, "856");


  std::vector<Token> result = {*token1, *token2, *token3};
  auto output = tokenize(input);
  for(int i = 0; i<3; i++) {
    REQUIRE(output[i] == result[i]);
  }
}

TEST_CASE("input is not whitespace sensitive", "[lexer]") {
  std::string input = "myvar=856";

  Token* token1 = new Token(TokenType::IDENT, "myvar");
  Token* token2 = new Token(TokenType::ASSIGN, "=");
  Token* token3 = new Token(TokenType::INT, "856");


  std::vector<Token> result = {*token1, *token2, *token3};
  auto output = tokenize(input);
  for(int i = 0; i<3; i++) {
    REQUIRE(output[i] == result[i]);
  }
}
