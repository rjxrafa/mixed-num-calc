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
        ~Parser();

        friend
        void operator>>(Parser &p, std::string& infixExpression);
        friend
        void operator<<(Parser &p, std::string& infixExpression);

    private:
        std::string storedExpression = "";
        std::stack<Token> opStack;
        std::queue<Token> tokenQ;

};

#endif // PARSER_H
