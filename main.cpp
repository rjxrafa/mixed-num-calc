#include <iostream>
#include "parser.h"

using namespace std;

int main()
{
    Parser a;

//    cout << "Output: " << a.parse("3/2 + 5.2 + 5/2 - 3/1") << endl;
    string temp = "3 3 3";
    a << temp;
    string output;
    a >> output;
    cout << output;

    return 0;
}
