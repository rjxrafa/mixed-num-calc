#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include <stack>
#include <queue>

enum parser_ERRORS {};

class Parser
{
    public:
        Parser();
        Parser(const Parser& other);
        ~Parser();
        std::string parse(const std::string userInput);
        std::string showNumberQueue();
        std::string showOperatorStack();

        friend
        std::istream& operator>>(std::istream &in, std::string& infixExpression);
        friend
        std::istream& operator<<(std::istream &in, std::string& infixExpression);

    private:
        std::stack<char> operators;
        std::queue<mixedNumber> output;

};

#endif // PARSER_H
