#include "parser.h"
#include <string>
using namespace std;
Parser::Parser()
{

}

Parser::~Parser()
{

}

std::string Parser::getString() const
{
    return storedExpression;
}

void Parser::parse(const std::string &infixExpression)
{
    bool debug = true;
    int count = 0; // Count keeps track of a token count based on type of token
    // Used for checking for mixed numbers and invalid operators
    std::stringstream ss(infixExpression);

    std::string token;
    while (ss >> token)
    {
        if (debug) {std::cout << "stored: " << token << std::endl;}
        Token temp;
        // Grabs a token
        if(token >> temp)
        {
            if(debug) {std::cout << temp << std::endl;}
            // If number add to queue

            if (temp.getType() == Operand)
            {
                count++;
                if(count == 2)
                {
                    if(tokenQ.back().getValue().getNum() == 0
                            || tokenQ.back().getValue().getDenom() != 1
                            || temp.getValue().getDenom() <= temp.getValue().getNum()
                            || temp.getValue().getNum() < 0
                            || temp.getValue().getDenom() < 0)
                        throw INVALIDEXPRESSION;
                    if(tokenQ.back().getValue() < 0)
                    {
                        mixedNumber fix = temp.getValue();
                        fix *= -1;
                        temp.setValue(fix);
                    }
                    mixedNumber sum = tokenQ.back().getValue();
                    sum += temp.getValue();
                    tokenQ.back().setValue(sum);
                }
                else
                    tokenQ.push(temp);
            }

            //if operator
            else if (temp.getType() == Operator)
            {
                count = 0;
                if(opStack.empty())
                    opStack.push(temp);
                else
                {
                    //while there is an op at the top of the stack
                    //with greater precedence, pop ops onto the output queue
                    //and push temp into opstack
                    while(!opStack.empty() &&
                          opStack.top().getPrecedence() >= temp.getPrecedence()
                          && opStack.top().getString() != "(")
                    {
                        tokenQ.push(opStack.top());
                        opStack.pop();
                    }
                    opStack.push(temp);
                }
            }
            else if(temp.getType() == Parenthesis)
            {
                //if token is left bracket, push it onto the op stack
                if(temp.getString() == "(")
                    opStack.push(temp);
                else if(temp.getString() == ")")
                {
                    //while the operator at the top of the op stack is not a left bracked
                    //pop op from the op stack onto the output queue
                    while(!opStack.empty() && opStack.top().getString() != "(")
                    {
                        tokenQ.push(opStack.top());
                        opStack.pop();
                    }
                    if(!opStack.empty())
                    {
                        opStack.pop();
                    }
                 }
            }
        }
        else
            throw INVALIDEXPRESSION;
    }

    while(!opStack.empty())
    {
        tokenQ.push(opStack.top());
        opStack.pop();
    }

    while(!tokenQ.empty())
    {
        storedExpression += tokenQ.front().getString() + ' ';
        tokenQ.pop();
    }

    if (debug) { std::cout << "The postfix conversion is: \n" + storedExpression;}
}
