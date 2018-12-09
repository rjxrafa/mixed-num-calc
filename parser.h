#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include "token.h"
#include "error.h"
#include <stack>
#include <queue>

class Parser
{
    public:
        Parser();
        ~Parser();
        std::string getString() const;
        void parse(const std::string &infixExpression);
        void parseCheck(); // Checks for valid expression.

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
