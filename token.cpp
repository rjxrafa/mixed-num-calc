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

mixedNumber Token::getValue()
{
    return val;
}

std::string Token::getString()
{
    return out;
}

Type Token::getType()
{
    return type;
}
