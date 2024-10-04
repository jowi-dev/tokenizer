#include <string>
#include <sstream>

#include "./token.cpp"



bool isInteger(std::string literal) {
  int num;
  std::istringstream iss(literal);
  if (iss >> num) return true;
  return false;
}

Token getTokenType(std::string literal) {
  if(literal == "def") return Token::DEFINE; 
  if(literal == "do") return Token::DO; 
  if(literal == "end") return Token::END; 
  if(literal == "=") return Token::ASSIGN; 
  if(literal == "+") return Token::PLUS; 
  if(literal == "(") return Token::LPAREN; 
  if(literal == ")") return Token::RPAREN; 
  if(isInteger(literal)) return Token::INT; 

  // Identifier..?
  //if(literal == "") return Token::END; 
  return Token::ILLEGAL;
}

