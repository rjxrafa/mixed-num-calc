#include "token.h"
#include <regex>

bool operator>>(std::istream &in, Token &t)
{  // This operator will only receive one token at a time. Parser class should handle multiple tokens.
    // Usig regex, we check for a mixedNum match. Else we check for operator match.

    std::regex m ("((\\+|\\-)?(\\d+)((\\d+)|(\\.\\d+)|( \\d+/\\d+))?)"); // MixedNum search
    std::smatch matches;
    std::regex o ("[-*\\+/]"); // Operator search

    std::string s;
    getline(in,s);

    // If string matches our regex, it is a fraction
    if (std::regex_match(s, m))
    {
        std::stringstream temp(s);
        temp >> t.val; // Store value
        t.type = Operand; // Change type
        t.out = s; // Store string output
    }
    else if (std::regex_match(s,o))
    {
        std::stringstream temp(s);
        temp >> t.out;

        switch(t.out[0])
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
    else
        return false;

    return true;
}
