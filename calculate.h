#ifndef CALCULATE_H
#define CALCULATE_H
#include "parser.h"
#include <string>
#include <stack>
#include <map>

class Calculate
{
    public:
        Calculate();
        ~Calculate();

        friend
        void operator>>(Calculate &c, std::string& postfixExpression);
        friend
        void operator<<(Calculate &c, std::string& postfixExpression);


   private:
        std::string storedExpression = "";
        std::stack<Token> operators;
        std::stack<Token> operands;        
};

#endif // CALCULATE_H
