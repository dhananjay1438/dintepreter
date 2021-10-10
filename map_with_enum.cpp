#include <algorithm>
#include <iostream>
#include <map>
#include <variant>
#include <vector>

// Should not be used increases complexity of code as we have to take care of
// string as well as char and we still have to prase the string letter by leter
// where we still have to use switch statement Works only with c++17
int main(void) {

  enum token_type {
    LEFT_PAREN,
    RIGHT_PAREN,
    SEMICOLON,
    COMMA,
    MINUS,
    PLUS,
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
  // std::map<std::variant<char, std::string>, token_type> map;
  std::map<std::variant<char, std::string>, token_type> map;
  std::vector<token_type> tokens;
  map.insert({'(', token_type::LEFT_PAREN});
  map.insert({')', token_type::RIGHT_PAREN});
  map.insert({';', token_type::SEMICOLON});
  map.insert({',', token_type::COMMA});
  map.insert({'-', token_type::MINUS});
  map.insert({'+', token_type::PLUS});
  map.insert({'.', token_type::DOT});
  map.insert({'/', token_type::SLASH});
  map.insert({'*', token_type::STAR});
  map.insert({'{', token_type::LEFT_BRACE});
  map.insert({'}', token_type::RIGHT_BRACE});
  map.insert({'!', token_type::NOT});
  map.insert({'<', token_type::LESS_THAN});
  map.insert({'>', token_type::GREATER_THAN});
  map.insert({"&&", token_type::AND});
  map.insert({"||", token_type::OR});
  map.insert({">=", token_type::GREATER_THAN_EQUAL});
  map.insert({"<=", token_type::LESS_THAN_EQUAL});
  map.insert({"!=", token_type::NOT_EQUAL});
  map.insert({"for", token_type::FOR});
  map.insert({"while", token_type::WHILE});
  map.insert({"if", token_type::IF});
  map.insert({"else", token_type::ELSE});
  map.insert({"return", token_type::RETURN});
  map.insert({"true", token_type::TRUE});
  map.insert({"false", token_type::FALSE});

  std::string string;
  while (true) {
    std::cin >> string;
    for (auto &ch : string) {
      if (ch == '=') {
        // WE have to check if letter after this is '=' and so on, so its better
        // to use switch
      }
    }
  }
  return 0;
}
