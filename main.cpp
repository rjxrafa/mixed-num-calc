#include <iostream>
#include "calculate.h"
#include "parser.h"
#include "token.h"
#include "error.h"

using namespace std;

void introduction();
void getInput(istream& in, string &savefile);
void executeArguments(int argc, char*argv[]);
void recordFile(std::string savefile, std::string postfix);

int main(int argc, char *argv[])
{
    introduction();
    executeArguments(argc, argv);
    string savefile = "";
    while(1)
    {
        try {
            getInput(cin, savefile);
        }
        catch (exception &e) {
            cout << std::endl << e.what() << std::endl;
        }
        catch (...) {
            cout << std::endl << "An unknown error has occured." << std::endl;
        }
    }
}

void introduction()
{
    string border(60, '*');

    cout << border << endl;
    cout << "This Program is called ." << endl;
    cout << border << endl;
}

void executeArguments(int argc, char*argv[])
{
    if (argc == 2)
    {
        ifstream in, in2;
        ofstream out;
        string inputfile, savefile;
        char ans;

        inputfile = argv[1];
        if(inputfile.find('.') > inputfile.size())
            inputfile+= ".spt";
        in.open(inputfile);
        if((in.fail()))
        {
          std::cout << "The input file does not exist!" << std::endl;
          std::exit(1);
        }
        cout << inputfile << " is a command line argument and was opened" << endl;

        cout << "Where do you wish to save these conversions? " << endl;
        cin >> savefile;
        if(savefile.find('.') > savefile.size())
            savefile += ".spt";
        in2.open(savefile);
        in2.close();
        if(in2.fail())
            out.open(savefile);
        else
        {
            in2.clear();
            std::cout<<"That file exists!!"<< std::endl;
            std::cout<<"Do you wish to overwrite it?" << std::endl;
            std::cin >> ans;

            char symbol;
            do
            {
                std::cin.get(symbol);
            } while (symbol != '\n');

            if(ans == 'Y' || ans == 'y')
                out.open(savefile);
            else
            {
                std::cout << "You chose not to overwrite." << std::endl;
                return;
            }
        }
        in2.close();
        out.close();

        while(!in.eof())
        {
            getInput(in, savefile);
        }
        cout << "Your conversions were written onto the desired file\nTHANK YOU" << endl;
        exit(1);
    }
    if (argc >= 3)
    {
        cout << "Too many command line arguments.\nExiting program..\n\n";
        exit(1);
    }

}

void getInput(istream& in, string &savefile)
{
    Parser a;
    Calculate b;
    string userInput;
    string postfix;
    string evaluation;

    if(&in == &cin)
    {
        cout << "\nPlease enter a desired expression:" << endl;

    }
    getline(in,userInput);
    if(userInput.empty())
    {
        std::cout << "\nSEE YA!" <<std::endl;
        std::exit(1);
    }

    a << userInput;
    a >> postfix;

    if(&in == &cin)
        cout << "\nYour postfix expression is " << postfix << std::endl;
    else
        recordFile(savefile, postfix);

    b << postfix;
//    b >> evaluation;

//    cout << "\nThe evaluation of this postfix expression is: " << evaluation << endl;

}

void recordFile(std::string savefile, std::string postfix)
{
    ofstream out;
    std::ifstream in;
    using namespace std;

    out.open(savefile,ios_base::app);

    out << postfix << endl;

    out.close();
}
