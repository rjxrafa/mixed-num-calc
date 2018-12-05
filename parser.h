#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include "token.h"
#include <stack>
#include <queue>

enum parser_ERRORS {};

class Parser
{
    public:
        Parser();
        Parser(const Parser& other); // potentially unneeded
        ~Parser();
        std::string parse(const std::string userInput);
        std::string outputNumberQueue();
        std::string outputOperatorStack();
        int precedence(char token);
        bool isOp(char token);

        friend
        void operator>>(Parser &p, std::string& infixExpression);
        friend
        void operator<<(Parser &p, std::string& infixExpression);

    private:
        std::stack<char> operators;
        std::queue<mixedNumber> output;
        std::string storedExpression = "";
        std::stack<Token> opStack;
        std::queue<Token> tokenQ;

};

#endif // PARSER_H
