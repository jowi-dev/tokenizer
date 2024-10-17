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

constexpr std::array<char, 5> specialCharacters = {'=', '+', '(', ')', ','};
//for tracking special characters, will grow over time
bool isSpecial(char token) {
  for(auto it = specialCharacters.begin(); it != specialCharacters.end(); ++it){
    if ( token == *it ) return true;
  }
  return false;
}

bool isLiteral (char token) {
  return  (token & ~32) - 'A' < 26 || token == '_';
}
bool isLiteral(std::string token) {
  std::regex pattern("[A-Za-z_]");
  std::regex anti_pattern("[0-9+\()=,]");
  return std::regex_search(token, pattern) && !std::regex_search(token, anti_pattern);
}

TokenType getTokenType(std::string literal) {
  if(literal == "def") return TokenType::DEFINE; 
  if(literal == "do") return TokenType::DO; 
  if(literal == "end") return TokenType::END; 
  if(literal == "=") return TokenType::ASSIGN; 
  if(literal == "+") return TokenType::PLUS; 
  if(literal == "(") return TokenType::LPAREN; 
  if(literal == ")") return TokenType::RPAREN; 
  if(literal == ",") return TokenType::COMMA; 
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
  for(size_t i = 0; i < words.size(); i++){
    // If the string contains non-alpha characters or special characters that are not _, we need to parse by character
    if(!isLiteral(words[i]) && !isInteger(words[i]) && words[i].length() > 1) {
      // start position of identifier
      int start_pos = 0;
      for(size_t j = 0; j < words[i].length(); j++){
        //if the current character is non-alpha, it is a token type we can parse
        if(isSpecial(words[i][j])){
          std::string term;
          term.push_back(words[i][j]);
          TokenType type = getTokenType(term);
          Token* token = new Token(type, term);
          parsed.push_back(*token);

          //the position of the next potential identifier is after this term
          start_pos = j+1;
        } 
        //peak the next term to see if it is alpha. if not, we have reached the end of the identifier
        else if(isSpecial(words[i][j+1]) || (j == (words[i].length() - 1))){
          std::string term = words[i].substr(start_pos, (j-start_pos) + 1);
          TokenType type = getTokenType(term);
          Token* token = new Token(type, term);
          parsed.push_back(*token);
        } 
        //If neither term hits, we are still in an identifier
      }
    } else {
        TokenType type = getTokenType(words[i]);
        Token* token = new Token(type, words[i]);
        parsed.push_back(*token);
    }
  }

  //string.split whitespace
  //for each member of the split up string 
  //get the token, peak the next one if necessary

  return parsed;
}



