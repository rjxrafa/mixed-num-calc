#include "token.h"

Token::Token()
{

}

Token::~Token()
{
    val = 0;
    out = "";
    type = None;
}

void Token::setValue(const mixedNumber &m)
{
    type = Operand;
    val  = m;
}

void Token::setPrecedence()
{
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

std::string Token::getString() const
{
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
