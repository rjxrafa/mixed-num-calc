#ifndef PARSER_H
#define PARSER_H
#include "mixednumber.h"
#include <stack>

enum parser_ERRORS {};

class parser
{
    public:
        parser();
        parser(const parser& other);
        ~parser();

        friend
        std::istream& operator>>(std::istream &in, std::string& infixExpression);

    private:


};

#endif // PARSER_H
