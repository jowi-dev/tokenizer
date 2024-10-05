#include <string>
#include <sstream>
#include <vector>
#include <regex>

#include "./token.cpp"



bool isInteger(std::string literal) {
  int num;
  std::istringstream iss(literal);
  if (iss >> num) return true;
  return false;
}

bool isLiteral(std::string token) {
  std::regex pattern("[A-Za-z_]");
  return std::regex_search(token, pattern);
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
  if(isLiteral(literal)) return TokenType::IDENT;

  return TokenType::ILLEGAL;
}

std::vector<std::string> split(const std::string& expression, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(expression);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<Token> tokenize(std::string expression) {
  std::vector<Token> parsed;
  std::vector<std::string> words = split(expression, ' ');
  for(int i = 0; i < words.size(); i++){
    TokenType type = getTokenType(words[i]);
    Token* token = new Token(type, words[i]);
    parsed.push_back(*token);
  }

  //string.split whitespace
  //for each member of the split up string 
  //get the token, peak the next one if necessary

  return parsed;
}
