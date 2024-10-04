#include <string>

enum class TokenType {
  ILLEGAL, 
  FILEEND,
  NEWLINE, 
  // Keywords
  DEFINE,
  DO, 
  END,
  // Identifiers and Literals
  IDENT ,
  INT ,
  // Operators
  ASSIGN ,
  PLUS ,
  // Delimiters
  LPAREN ,
  RPAREN 
};

constexpr const char* getTokenLiteral(TokenType type) {
  switch(type) {
    case TokenType::ILLEGAL: return "ILLEGAL";
    case TokenType::FILEEND: return "EOF";
    case TokenType::NEWLINE: return "\n";
    case TokenType::DEFINE: return "def";
    case TokenType::DO: return "do";
    case TokenType::END: return "end";
    case TokenType::IDENT: return "IDENT"; // Identifie
    case TokenType::INT: return "INT"; //Integer litera
    case TokenType::ASSIGN: return "=";
    case TokenType::PLUS: return "+";
    case TokenType::LPAREN: return "(";
    case TokenType::RPAREN: return ")";
    default: return "ILLEGAL";
  }
}

class Token {

  TokenType type;
  std::string literal;

  Token(TokenType tokenType, std::string lit) {
    type = tokenType;
    literal = lit;
  }

};
