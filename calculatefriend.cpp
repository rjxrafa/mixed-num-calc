#include "calculate.h"

void operator>>(Calculate &c, std::string& postfixExpression)
{
    bool debug = false;
    if (debug) {std::cout << "\nStored expression: " << c.storedExpression << std::endl;}
    postfixExpression = c.storedExpression;
}

void operator<<(Calculate &c, std::string& postfixExpression)
{
    bool debug = false;
    std::string token;
    if(debug) {std::cout << "\nCalculating '" << postfixExpression << "'" << std::endl;}


    std::stringstream ss(postfixExpression);
    std::stringstream aa;

    while(ss >> token)
    {
        if(debug) {std::cout << "\nStored: " << c.storedExpression << std::endl;}
        Token temp;

        if(token.find_first_of('\0') < token.size())
        {
            token[token.find_first_of('\0')] = ' ';
            mixedNumber a ,b,c;
            aa.clear();
            aa >> token;
            aa << a;
            aa << b;
            c = a + b;
            temp.setValue(c);
        }
        if(token >> temp || temp.getString() != "")
        {
            if(debug) {std::cout << "\nTemp: " << temp << std::endl;}

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
        std::cout << "= "<< c.operands.top() << ' ';
        c.operands.pop();
    }
    std::cout << std::endl<< std::endl;
}
