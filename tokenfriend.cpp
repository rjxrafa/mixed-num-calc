#include "token.h"
#include <regex>

bool operator>>(std::istream &in, Token &t)
{   // This operator will only receive one token at a time. Parser class should handle multiple tokens.
    // Usig regex, we check for a mixedNum match. Else we check for operator match.

    // MixedNum pattern
    std::regex m ("(((\\+|\\-)?(\\d+)((/\\d+)|(\\.\\d+)|(\\s\\d+/\\d+))?)|(\\+|\\-)?(\\.\\d+))");
    //+-optional, d+ more than one digit, | allows variations
    // / for fraciton, . for decimal, s stands for whitespace, this allows us for mixed number. ? means optional

    // Operator pattern
    std::regex o ("[-*\\+/\\(\\)]");

    std::string s;
    getline(in,s);

    // If string matches our regex, it is a fraction
    if (std::regex_match(s, m))
    {
        std::stringstream temp(s);
        temp >> t.val; // Store value
        t.type = Operand; // Change type
        temp << t.val; // We store it back as a mixNum output
        t.out = temp.str(); // Storing mixedNum string
    }
    else if (std::regex_match(s,o))
    {
        std::stringstream temp(s);
        temp >> t.out;
        if(t.out == "(" || t.out == ")")
            t.type = Parenthesis;
        else
        {
            t.type = Operator;
            t.setPrecedence();
        }
    }
    else
        return false;

    return true;
}

bool operator>>(std::string &s, Token &t)
{ // This overloaded operator will allow us to build tokens from strings
    std::regex m ("(((\\+|\\-)?(\\d+)((/\\d+)|(\\.\\d+)|(\\s\\d+/\\d+))?)|(\\+|\\-)?(\\.\\d+))"); // MixedNum pattern
    std::regex o ("[-*\\+/\\(\\)]"); // Operator pattern

    // If string matches our regex, it is a fraction
    if (std::regex_match(s, m))
    {
        std::stringstream temp(s);
        temp >> t.val; // Store value
        t.type = Operand; // Change type
        temp << t.val;
        t.out = temp.str(); // Storing mixedNum string
    }
    else if (std::regex_match(s,o))
    {
        std::stringstream temp(s);
        temp >> t.out;
        if(t.out == "(" || t.out == ")")
            t.type = Parenthesis;
        else
        {
            t.type = Operator;
            t.setPrecedence();
        }
    }
    else
        return false;

    return true;
}

std::ostream &operator<<(std::ostream &out, Token& t)
{ // Outputs operator/operand
    if (t.type == Operator)
        out << t.out;
    else if (t.type == Operand)
        out << t.val;
    return out;
}
