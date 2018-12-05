#include <iostream>
#include "parser.h"
#include "token.h"
#include <regex>
using namespace std;

int main()
{
//    Parser a;
//    cout << "Output: " << a.parse("( 3/5 + 5 ) / ( 8 + -1 )") << endl;
//    string temp = "3 3 3";
//    string output;

    while (1)
    {
        try
        {
            Token a;
            string temp;
            cin >> temp;
            std::stringstream ss(temp);
            ss >> a;
            cin.clear();
            cout << "\nVal: " << a.getValue()
                 << "\nType:" << a.getType()
                 << "\nString:" << a.getString()
                 << endl;
        } catch (...)
        {
            cout << "\nAn unknown error has occured.\n";
        }
    }

//    std::regex m ("((\\+|\\-)?(\\d+)((\\/\\d+)|(\\.\\d+)|( \\d+/\\d+))?)"); // MixedNum search
//    std::smatch matches;
////    std::regex m ("[-*\\+/]"); // Operator search

////    string temp = "*";
////    cout << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////     temp = "/";
////    cout << endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////     temp = "^";
////    cout << endl<< std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////     temp = "+";
////    cout << endl<< std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////     temp = "*";
////    cout << endl<< std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////    temp = "-";
////   cout << endl<< std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
////   temp = "-4";
////  cout << endl<< std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;


//    string temp = "3 -2/3 ";
//    cout << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "3 2/3";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "2/3";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "-3 2/3";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "5.2";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "-5.2";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "-3 -3";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "5x";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "5-";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "5-3";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "55";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;
//    temp = "55/55";
//    cout << std::endl << std::boolalpha << temp << ": "<< (std::regex_match(temp, matches, m)) ? true : false;



    return 0;
}
