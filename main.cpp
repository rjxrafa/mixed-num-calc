#include <iostream>
#include "parser.h"

using namespace std;

int main()
{
    Parser a;

    cout << "Output: " << a.parse("3/2 + 5.2 + 5/2 - 3/1") << endl;

    return 0;
}
