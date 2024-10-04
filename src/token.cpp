
enum class Token {
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

constexpr const char* getTokenLiteral(Token type) {
  switch(type) {
    case Token::ILLEGAL: return "ILLEGAL";
    case Token::FILEEND: return "EOF";
    case Token::NEWLINE: return "\n";
    case Token::DEFINE: return "def";
    case Token::DO: return "do";
    case Token::END: return "end";
    case Token::IDENT: return "IDENT"; // Identifie
    case Token::INT: return "INT"; //Integer litera
    case Token::ASSIGN: return "=";
    case Token::PLUS: return "+";
    case Token::LPAREN: return "(";
    case Token::RPAREN: return ")";
    default: return "ILLEGAL";
  }
}
