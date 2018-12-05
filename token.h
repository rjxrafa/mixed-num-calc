#ifndef TOKEN_H
#define TOKEN_H
#include "mixednumber.h"
#include <stack>

enum Type {  None, Operator, Operand };

class Token
{

public:
    Token();
    ~Token();

    void setValue(const mixedNumber &m);

    mixedNumber getValue();
    std::string getString();
    Type getType();

    friend
    bool operator>>(std::istream &in, Token &t);
    friend
    bool operator>>(std::string, Token &t);

    friend
    std::ostream & operator<<(std::ostream &out, const Token &t);


private:
    mixedNumber val;
    std::string out;
    Type type = None;
    int precedence = 0;

};

#endif // TOKEN_H
