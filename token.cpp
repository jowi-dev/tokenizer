
using TokenType = std::string;

struct Token {
  TokenType Type;
  std::string Literal;
};

constexpr TokenType ILLEGAL = "ILLEGAL";
constexpr TokenType EOF = "EOF";
constexpr TokenType NEWLINE = "\n";

constexpr TokenType DEFINE = "def";
constexpr TokenType DO = "do";
constexpr TokenType END = "end";

constexpr TokenType IDENT = "IDENT"; // Identifier
constexpr TokenType INT = "INT"; //Integer literal

constexpr TokenType ASSIGN = "=";
constexpr TokenType PLUS = "+";
constexpr TokenType LPAREN = "(";
constexpr TokenType RPAREN = ")";
