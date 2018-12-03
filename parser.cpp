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

    if (debug) {std::cout << "Parsing string: " << userInput << std::endl;}
    while (!in.eof())
    {
        in >> temp;
        if (debug) {std::cout << temp << std::endl;}
        if (isdigit(temp[0]))
        {
            ss << temp;
            ss >> tempMixed;
            ss.clear();
            output.push(tempMixed);
        }
        else
        {
            ss << temp;
            operators.push(ss.get());
        }
    }

    return showNumberQueue()+showOperatorStack();
}

std::string Parser::showNumberQueue()
{
    std::queue<mixedNumber> temp;
    std::stringstream ss;
    std::string tempstr;
    while (!output.empty())
    {
        ss << output.front() << " " ;
        temp.push(output.front());
        output.pop();
    }
    output = temp;
    getline(ss, tempstr);
    return tempstr;
}

std::string Parser::showOperatorStack()
{
    std::stack<char> temp;
    std::stringstream ss;
    std::string tempstr;
    while (!operators.empty())
    {
        ss << operators.top()<< " ";
        temp.push(operators.top());
        operators.pop();
    }
    operators = temp;
    getline(ss,tempstr);
    return tempstr;
}
