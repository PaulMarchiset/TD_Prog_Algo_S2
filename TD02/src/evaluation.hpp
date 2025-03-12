#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <cmath>
#include <iostream>

// ----- NPI evaluation -----

std::vector<std::string> split_string(std::string const& s);

bool isOperator(std::string const& s);

float npi_evaluate(std::vector<std::string> const& tokens);

// ----- NPI evaluation with struct and enum -----

enum class Operator { ADD, SUB, MUL, DIV};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

Token make_token(float value);
Token make_token(Operator op);

std::vector<Token> tokenize(std::vector<std::string> const& words);

float npi_evaluate(std::vector<Token> const& tokens);