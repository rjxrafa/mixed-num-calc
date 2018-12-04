#include "parser.h"

Parser::Parser()
{

}

Parser::Parser(const Parser& other)
{

}

Parser::~Parser()
{

}

std::string Parser::parse(const std::string userInput)
{ // This function will take any string and parse it as a RPN string.
    std::stringstream in(userInput), ss;
    std::string temp;
    mixedNumber tempMixed;
    bool debug = true;

    //quick and dirty shunting yard, let's make this
    //nicer lol

    if (debug) {std::cout << "Parsing string: " << userInput << std::endl;}
    while (!in.eof())
    {
        in >> temp;
        if (debug) {std::cout << temp << std::endl;}
        if (isdigit(temp[0])) // *BUG*: Will be unable to take in decimals that start with . (e.g. .5)
        {
            ss << temp;
            ss >> tempMixed;

            ss << tempMixed;
            getline(ss,temp);
            ss.clear();

            storedExpression += temp;
            storedExpression += " ";

        }
        else if (isOp(temp[0]))
        {
            //for -2.
            //repeat of top, gotta clean this
            if(isdigit(temp[1]))
            {
                ss << temp;
                ss >> tempMixed;

                ss << tempMixed;
                getline(ss,temp);
                ss.clear();

                storedExpression += temp;
                storedExpression += " ";
            }
            else
            {
                ss << temp;
                if(operators.empty())
                    operators.push(ss.get());
                else
                {
                    while(operators.top() != '(' && precedence(operators.top()) > precedence(temp[0]) && !(operators.empty()))
                    {
                        storedExpression += operators.top();
                        storedExpression += " ";
                        operators.pop();
                    }
                    operators.push(ss.get());
                }
                ss.clear();
            }
        }
        else if(temp[0] == '(')
        {
            operators.push(temp[0]);
        }
        else if(temp[0] == ')')
        {
            while(!operators.empty() && operators.top() != '(')
            {
                storedExpression += operators.top();
                storedExpression += " ";
                operators.pop();
            }
            if (!operators.empty())
            {
                operators.pop();
            }
        }
    }
    while(!(operators.empty()))
    {
        storedExpression += operators.top();
        storedExpression += " ";

        operators.pop();
    }

    return storedExpression;/*outputNumberQueue()+outputOperatorStack()*/;
}

//std::string Parser::outputNumberQueue()
//{
//    std::queue<mixedNumber> temp;
//    std::stringstream ss;
//    std::string tempstr;
//    while (!output.empty())
//    {
//        ss << output.front() << " " ;
//        temp.push(output.front());
//        output.pop();
//    }
//    output = temp;
//    getline(ss, tempstr);
//    return tempstr;
//}

//std::string Parser::outputOperatorStack()
//{
//    std::stack<char> temp;
//    std::stringstream ss;
//    std::string tempstr;
//    while (!operators.empty())
//    {
//        ss << operators.top()<< " ";
//        temp.push(operators.top());
//        operators.pop();
//    }
//    operators = temp;
//    getline(ss,tempstr);
//    return tempstr;
//}

int Parser::precedence(char token)
{
    switch(token)
    {
        case '/':
            return 3;
        case '*':
            return 3;
        case '+':
            return 2;
        case '-':
            return 2;
    }
}

bool Parser::isOp(char token)
{
    if(token == '/' || token == '*' || token == '+' || token == '-')
        return true;
    else
        return false;
}
