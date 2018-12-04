#include <iostream>
#include "parser.h"

using namespace std;

int main()
{
    Parser a;
    cout << "Output: " << a.parse("( 3/5 + 5 ) / ( 8 + -1 )") << endl;
//    string temp = "3 3 3";
//    string output;

    return 0;
}
