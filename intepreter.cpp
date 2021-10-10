#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

int main(void) {

  enum token_type {
    LEFT_PAREN,
    RIGHT_PAREN,
    SEMICOLON,
    COMMA,
    MINUS,
    DECREMENT,
    PLUS,
    INCREMENT,
    DOT,
    SLASH,
    STAR,
    LEFT_BRACE,
    RIGHT_BRACE,

    IDENTIFIER,
    STRING,
    INT,

    // Keywords of sort

    AND,
    OR,
    IF,
    ELSE,
    FOR,
    WHILE,
    RETURN,
    PRINT,
    TRUE,
    FALSE,
    VAR,

    LESS_THAN,
    GREATER_THAN,
    EQUAL,
    NOT,

    LESS_THAN_EQUAL,
    GREATER_THAN_EQUAL,
    EQUAl_EQUAL,
    NOT_EQUAL,

    _EOF
  };

  std::string file_contents;
  std::ifstream file("code.dp");
  if (file.fail()) {
    std::cout << "Cannot open the file\n";
    return EXIT_FAILURE;
  }
  std::vector<token_type> tokens;
  std::stringstream buffer;
  buffer << file.rdbuf();
  file_contents = buffer.str();
  buffer.clear();
  int line = 1;

  for (size_t i = 0; i < file_contents.size(); i++) {
    char ch = file_contents[i];
    char next = '\0';
    if (i != file_contents.size() - 1) {
      next = file_contents[i + 1];
    }
    switch (ch) {
      // Ignore these cases
    case '\n':
      line++;
      break;
    case ' ':
    case '\r':
    case '\t':
      break;
      // Single char token
    case '(':
      tokens.push_back(RIGHT_PAREN);
      break;
    case ')':
      tokens.push_back(LEFT_PAREN);
      break;
    case '{':
      tokens.push_back(LEFT_BRACE);
      break;
    case '}':
      tokens.push_back(RIGHT_BRACE);
      break;
    case '+':
      if (next == '+') {
        tokens.push_back(INCREMENT);
        i++;
      } else {
        tokens.push_back(PLUS);
      }
      break;
    case '-':
      if (next == '-') {
        tokens.push_back(DECREMENT);
        i++;
      } else {
        tokens.push_back(MINUS);
      }
      break;
    case '*':
      tokens.push_back(STAR);
      break;
    case '/':
      tokens.push_back(SLASH);
      break;
    case ';':
      tokens.push_back(SEMICOLON);
      break;
    case ',':
      tokens.push_back(COMMA);
      break;
    case '.':
      tokens.push_back(DOT);
      break;
      // Operators
    case '!':
      if (next == '=') {
        tokens.push_back(NOT_EQUAL);
        i++;
      } else {
        tokens.push_back(NOT);
      }
      break;
    case '>':
      if (next == '=') {
        tokens.push_back(GREATER_THAN_EQUAL);
        i++;
      } else {
        tokens.push_back(GREATER_THAN);
      }
      break;
    case '<':
      if (next == '=') {
        tokens.push_back(LESS_THAN_EQUAL);
        i++;
      } else {
        tokens.push_back(LESS_THAN);
      }
      tokens.push_back(DOT);
      break;
    case '=':
      if (next == '=') {
        tokens.push_back(EQUAl_EQUAL);
        i++;
      } else {
        tokens.push_back(EQUAL);
      }
      break;
    case '"':
      while (file_contents[++i] != '"' && i < file_contents.size() - 1)
        ;
      if (i == file_contents.size()) {
        std::cout << "Error : " << line << " String is not quoted properly";
      } else {
        tokens.push_back(STRING);
      }
      break;
    default:
      if (std::isalpha(ch)) {
        while (std::isalpha(file_contents[i + 1])) {
          i++;
        }
        tokens.push_back(IDENTIFIER);
      } else if (std::isdigit(ch)) {
        while (std::isdigit(file_contents[i + 1])) {
          std::cout << file_contents[i] << " ";
          i++;
        }
        if (file_contents[i] == '.') {
          while (std::isdigit(file_contents[i + 1])) {
            i++;
          }
        }
        tokens.push_back(INT);
      } else {
        std::cout << "Error at line : " << line
                  << " Unexpected character: " << ch << "\n";
      }
    }
  }
  for (auto &token : tokens) {
    std::cout << token << " ";
  }
  return 0;
}
