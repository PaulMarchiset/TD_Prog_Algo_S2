#include "evaluation.hpp"

// ----- Split string in multiple strings -----

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

// ----- Check if string is operand or operator -----

bool isOperator(std::string const& s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^")
        return true;
    return false;
}

// ----- NPI evaluation -----

float npi_evaluate(std::vector<std::string> const& tokens) {
    std::stack<float> stack;
    for (const std::string& token : tokens) {
        if (isOperator(token)) {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            } else if (token == "/") {
                stack.push(a / b);
            } else if (token == "^") {
                stack.push(std::pow(a, b));
            }
        } else {
            stack.push(std::stof(token));
        }
    }
    return stack.top();
}



// -----------------------------------------------
// ----- NPI evaluation with struct and enum -----
// -----------------------------------------------


// ----- Tokenize -----

Token make_token(float value)
{
    return Token{ TokenType::OPERAND, value, Operator::ADD };
}
Token make_token(Operator op)
{
    return Token {TokenType::OPERATOR, 0.f, op};
}

std::vector<Token> tokenize(std::vector<std::string> const& words) {
    std::vector<Token> tokens;
    for (const std::string& word : words) {
        if (isOperator(word)) {
            if (word == "+") {
                tokens.push_back(make_token(Operator::ADD));
            } else if (word == "-") {
                tokens.push_back(make_token(Operator::SUB));
            } else if (word == "*") {
                tokens.push_back(make_token(Operator::MUL));
            } else if (word == "/") {
                tokens.push_back(make_token(Operator::DIV));
            }
        } else {
            tokens.push_back(make_token(std::stof(word)));
        }
    }
    return tokens;
}


// ----- NPI evaluation -----

float npi_evaluate(std::vector<Token> const& tokens) {
    std::stack<float> stack;
    for (const Token& token : tokens) {
        if (TokenType::OPERATOR == token.type) {
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            switch (token.op)
            {
            case Operator::ADD:
                stack.push(a + b);
                break;
            case Operator::SUB:
                stack.push(a - b);
                break;
            case Operator::MUL:
                stack.push(a * b);
                break;
            case Operator::DIV:
                stack.push(a / b);
                break;
            default:
                break;
            }
        }
        else {
            stack.push(token.value);
        }
    }
    return stack.top();
}