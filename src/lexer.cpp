#include <string>

#include "./token.cpp"


Token getTokenType(std::string literal) {
  if(literal == "=") return Token::ASSIGN; 
  return Token::ILLEGAL;
}
