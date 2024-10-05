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

class Token {
  public:
    TokenType type;
    std::string literal;

    Token(TokenType tokenType, std::string lit) {
      type = tokenType;
      literal = lit;
    }
    auto operator<=>(const Token&) const = default;
};
