#include "calculate.h"

void operator>>(Calculate &c, std::string& postfixExpression)
{
    bool debug = true;
    if (debug) {std::cout << "Stored expression: " << c.storedExpression << std::endl;}

    postfixExpression = c.storedExpression;
}

void operator<<(Calculate &c, std::string& postfixExpression)
{
    bool debug = false;
    c.storedExpression = postfixExpression;
    if(debug) {std::cout << "Calculating '" << postfixExpression << "'" << std::endl;}

    std::stringstream ss(postfixExpression);

    while(ss >> c.storedExpression)
    {
        if(debug) {std::cout << "stored: " << c.storedExpression << std::endl;}
        Token temp;

        if(c.storedExpression >> temp)
        {
            if(debug) {std::cout << "temp: " << temp << std::endl;}

            if(temp.getType() == Operand)
                c.operands.push(temp);
            if(temp.getType() == Operator)
            {
                mixedNumber firstOperand, secondOperand, result;

                firstOperand = c.operands.top().getValue();
                c.operands.pop();
                secondOperand = c.operands.top().getValue();
                c.operands.pop();

                if(temp.getString() == "+")
                {
                    result = secondOperand + firstOperand;
                    temp.setValue(result);
                    c.operands.push(temp);
                }
                else if(temp.getString() == "-")
                {
                    result = secondOperand - firstOperand;
                    temp.setValue(result);
                    c.operands.push(temp);
                }
                else if(temp.getString() == "*")
                {
                    result = secondOperand * firstOperand;
                    temp.setValue(result);
                    c.operands.push(temp);
                }
                else if(temp.getString() == "/")
                {
                    result = secondOperand / firstOperand;
                    temp.setValue(result);
                    c.operands.push(temp);
                }
            }
        }
    }
    while(!c.operands.empty())
    {
        std::cout << "The evalution of this expression is: "<< c.operands.top() << ' ';
        c.operands.pop();
    }
}
