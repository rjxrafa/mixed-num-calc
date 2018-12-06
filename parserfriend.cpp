#include "parser.h"

void operator>>(Parser &p, std::string& infixExpression)
{ // Extractor operator allows for extraction of stored expression into a given string.
    bool debug = true;
    if (debug) {std::cout << "Stored expression: " << p.storedExpression << std::endl;}
    infixExpression = p.storedExpression;
}

void operator<<(Parser &p, std::string& infixExpression)
{ // Insertion operator allows for insertion of strings into the parser object.
    bool debug = true;
    int count = 0;
    p.storedExpression = infixExpression;
    if (debug) {std::cout << "Inserting '" << infixExpression << "'" << std::endl;}

    std::stringstream ss(infixExpression);

    while (ss >> p.storedExpression)
    {
        if (debug) {std::cout << "stored: " << p.storedExpression << std::endl;}
        Token temp;
        //grabs a token
        if(p.storedExpression >> temp)
        {
            if(debug) {std::cout << temp << std::endl;}
            //if number add to queue

            if (temp.getType() == Operand)
            {
                count++;
                if(count == 2)
                {
                    if(p.tokenQ.back().getValue().getNum() == 0
                            || p.tokenQ.back().getValue().getDenom() != 1
                            || temp.getValue().getDenom() <= temp.getValue().getNum()
                            || temp.getValue().getNum() < 0
                            || temp.getValue().getDenom() < 0)
                        throw INVALIDEXPRESSION;
                    if(p.tokenQ.back().getValue() < 0)
                    {
                        mixedNumber fix = temp.getValue();
                        fix *= -1;
                        temp.setValue(fix);
                    }
                    mixedNumber sum = p.tokenQ.back().getValue();
                    sum += temp.getValue();
                    p.tokenQ.back().setValue(sum);
                }
                else
                    p.tokenQ.push(temp);
            }

            //if operator
            else if (temp.getType() == Operator)
            {
                count = 0;
                if(p.opStack.empty())
                    p.opStack.push(temp);
                else
                {
                    //while there is an op at the top of the stack
                    //with greater precedence, pop ops onto the output queue
                    //and push temp into opstack
                    while(!p.opStack.empty() &&
                          p.opStack.top().getPrecedence() >= temp.getPrecedence()
                          && p.opStack.top().getString() != "(")
                    {
                        p.tokenQ.push(p.opStack.top());
                        p.opStack.pop();
                    }
                    p.opStack.push(temp);
                }
            }
            else if(temp.getType() == Parenthesis)
            {
                //if token is left bracket, push it onto the op stack
                if(temp.getString() == "(")
                    p.opStack.push(temp);
                else if(temp.getString() == ")")
                {
                    //while the operator at the top of the op stack is not a left bracked
                    //pop op from the op stack onto the output queue
                    while(!p.opStack.empty() && p.opStack.top().getString() != "(")
                    {
                        p.tokenQ.push(p.opStack.top());
                        p.opStack.pop();
                    }
                    if(!p.opStack.empty())
                    {
                        p.opStack.pop();
                    }
                 }
            }
        }
        else
            throw INVALIDEXPRESSION;
    }

    while(!p.opStack.empty())
    {
        p.tokenQ.push(p.opStack.top());
        p.opStack.pop();
    }

    std::cout << "The postfix conversion is: \n";
    while(!p.tokenQ.empty())
    {
        std::cout << p.tokenQ.front() << ' ';
        p.tokenQ.pop();
    }
}
