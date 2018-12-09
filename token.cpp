#include "token.h"

Token::Token()
{

}

Token::~Token()
{ // Nuke everyone
    val = 0;
    out = "";
    type = None;
}

void Token::setValue(const mixedNumber &m)
{ // Sets the internal value of the token (if applicable)
    type = Operand;
    val  = m;
}

void Token::setPrecedence()
{ // Sets precendece for a given token.
    switch(out[0])
    {
        case '/':
        case '*':
            precedence =  3;
            break;
        case '+':
        case '-':
            precedence =  2;
            break;
        default:
            break;
    }
}

mixedNumber Token::getValue() const
{
    return val;
}

std::string Token::getString()
{ // This value will need to update itself before returning its value
    if (type == Operand)
    {
        std::stringstream ss;
        ss << val;
        out = ss.str();
    }

    return out;
}

Type Token::getType()
{
    return type;
}

int Token::getPrecedence() const
{
    return precedence;
}
