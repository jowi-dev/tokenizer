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
  RPAREN,
  COUNT
};

// Array of strings corresponding to enum values
constexpr std::array<std::string_view, static_cast<size_t>(TokenType::COUNT)> TokenNames = {
  "ILLEGAL", 
  "FILEEND",
  "NEWLINE", 
  "DEFINE",
  "DO", 
  "END",
  "IDENT" ,
  "INT",
  "ASSIGN" ,
  "PLUS" ,
  "LPAREN" ,
  "RPAREN" 
};
// Function to convert enum to string
std::string TokenToString(TokenType token) {
    return std::string(TokenNames[static_cast<size_t>(token)]);
}

class Token {
  public:
    TokenType type;
    std::string literal;

    Token(TokenType tokenType, std::string lit) {
      type = tokenType;
      literal = lit;
    }
    auto operator<=>(const Token&) const = default;

    std::string toString(){
      return TokenToString(this->type);
    }
};
