#include <iostream>
#include "calculate.h"
#include "parser.h"
#include "token.h"
#include <regex>
using namespace std;

void introduction();
void getInput(istream& in, string inputfile, string& savefile);
void executeArguments(int argc, char*argv[]);
void recordFile(std::string filename, std::string postfix);


int main(int argc, char *argv[])
{
    introduction();
//    executeArguments(argc, argv);
    string  inputname = "", savefile = "";
    while(1)
    {
        try {    
            getInput(cin, inputname, savefile);
        }
        catch (fraction_ERRORS e)
        {
            switch(e)
            {
            case DIVBYZERO :
                std::cout << "Division by zero" << std::endl;
                break;
            case INVALIDFRACTION:
                std::cout << "Invalid fraction was entered" << std::endl;
                break;
            }
        }
        catch (mixedNumber_ERRORS f)
        {
            switch(f)
            {
            case INVALIDMIXED :
                std::cout << "Improper Mixed Number" << std::endl;
                break;
            }
        }
        catch (...) {
            cout << "\nAn unknown error has occured.";
        }
    }

    return 0;
}

void introduction()
{
    string border(80, '*');

    cout << border << endl;
    cout << "This Program is called ." << endl;
    cout << border << endl;
}

//void executeArguments(int argc, char*argv[])
//{
//    if (argc == 2)
//    {
//        ifstream in;
//        string filename;

//        filename = argv[1];
//        if(filename.find('.') > filename.size())
//            filename+= ".spt";
//        in.open(filename);
//        if((in.fail()))
//        {
//          std::cout << "The input file does not exist!" << std::endl;
//        }
//        else
//        {
//            getInput(in, filename);
//        }
//    }
//    if (argc >= 3)
//    {
//        cout << "Too many command line arguments.\nExiting program..\n\n";
//        exit(1);
//    }

//}

void getInput(istream& in, string inputfile, string &savefile)
{
    string userInput;
    string postfix;
    if(&in == &cin)
    {
        cout << "\nPlease enter a desired expression:" << endl;

    }
    getline(in,userInput);
    if(userInput.empty())
    {
        std::cout << "SEE YA!" <<std::endl;
        std::exit(1);
    }
    Parser a;
    a << userInput;
    a >> postfix;

    if(&in == &cin)
        cout << "your postfix expression is " << postfix;
//    else
//        recordFile(savefile, postfix);

//        cout << "\nPlease enter a postfix expression: " << endl;
//        string temp2;
//        getline(cin, temp2);
//        Calculate b;
//        b << temp2;
}

//void recordFile(std::string filename, std::string postfix)
//{
//    ofstream out;
//    std::ifstream in;
//    using namespace std;

//    if(filename.empty())
//        cout <<

//    if(filename.find('.') > filename.size())
//        filename += ".spt";

//    out.open(filename,ios_base::app);

//    out << postfix << endl;

//    out.close();
//}
