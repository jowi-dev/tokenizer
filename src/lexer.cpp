#include <string>
#include <sstream>
#include <vector>

#include "./token.cpp"



bool isInteger(std::string literal) {
  int num;
  std::istringstream iss(literal);
  if (iss >> num) return true;
  return false;
}

TokenType getTokenType(std::string literal) {
  if(literal == "def") return TokenType::DEFINE; 
  if(literal == "do") return TokenType::DO; 
  if(literal == "end") return TokenType::END; 
  if(literal == "=") return TokenType::ASSIGN; 
  if(literal == "+") return TokenType::PLUS; 
  if(literal == "(") return TokenType::LPAREN; 
  if(literal == ")") return TokenType::RPAREN; 
  if(isInteger(literal)) return TokenType::INT; 

  // Identifier..?
  //if(literal == "") return Token::IDENT; 
  return TokenType::ILLEGAL;
}

std::vector<Token> parseTokens(std::string expression) {
  std::vector<Token> parsed;

  //string.split whitespace
  //for each member of the split up string 
  //get the token, peak the next one if necessary

  return parsed;
}
