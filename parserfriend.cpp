#include "parser.h"

void operator>>(Parser &p, std::string& infixExpression)
{ // Extractor operator allows for extraction of stored expression into a given string.
    bool debug = true;
    if (debug) {std::cout << "Stored expression: " << p.storedExpression << std::endl;}
    infixExpression = p.storedExpression;
}

void operator<<(Parser &p, std::string& infixExpression)
{ // Insertion operator allows for insertion of strings into the parser object.
    bool debug = false;
    p.storedExpression = infixExpression;
    if (debug) {std::cout << "Inserting '" << infixExpression << "'" << std::endl;}

    std::stringstream ss(infixExpression);

    while (ss >> p.storedExpression)
    {
        if (debug) {std::cout << "stored: " << p.storedExpression << std::endl;}
        Token temp;
        if(p.storedExpression >> temp)
        {
            if(debug) {std::cout << temp << std::endl;}
            if (temp.getType() == Operand)
                p.tokenQ.push(temp);
            else if (temp.getType() == Operator)
            {
    //            if (!p.opStack.empty())
    //            {
    //                while (p.opStack.top().checkPrecedence() > temp.checkPrecedence())
    //            }
                p.opStack.push(temp);
            }
        }
    }

    while(!p.opStack.empty())
    {
        p.tokenQ.push(p.opStack.top());
        p.opStack.pop();
    }

    std::cout << "starting output: \n";
    while(!p.tokenQ.empty())
    {
        std::cout << p.tokenQ.front() << ' ';
        p.tokenQ.pop();
    }
}
