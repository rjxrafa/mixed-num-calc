#include "parser.h"

void operator>>(Parser &p, std::string& infixExpression)
{ // Extractor operator allows for extraction of stored expression into a given string.
    bool debug = false;
    if (debug) {std::cout << "Stored expression: " << p.storedExpression << std::endl;}
    infixExpression = p.storedExpression;
}

void operator<<(Parser &p, std::string& infixExpression)
{ // Insertion operator allows for insertion of strings into the parser object.
    bool debug = false;
    if (debug) {std::cout << "Inserting '" << infixExpression << "'" << std::endl;}
    p.parse(infixExpression);
}
