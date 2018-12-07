#ifndef TOKEN_H
#define TOKEN_H
#include "mixednumber.h"
#include <stack>

enum Type { None, Operator, Operand, Parenthesis };

class Token
{

public:
    Token();
    ~Token();

    void setValue(const mixedNumber &m);
    void setPrecedence();

    mixedNumber getValue() const;
    std::string getString();
    int getPrecedence() const;

    Type getType();

    friend
    bool operator>>(std::istream &in, Token &t);
    friend
    bool operator>>(std::string &s, Token &t);
    friend
    std::ostream &operator<<(std::ostream &out, Token& t);

    friend
    std::ostream & operator<<(std::ostream &out, const Token &t);


private:
    mixedNumber val;
    std::string out;
    Type type = None;
    int precedence = 0;

};

#endif // TOKEN_H
