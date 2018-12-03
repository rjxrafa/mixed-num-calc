#include "parser.h"

std::istream& operator>>(std::istream &in, std::string& infixExpression)
{
    std::cout << ">> fired";
    return in;
}

std::istream& operator<<(std::istream &in, std::string& infixExpression)
{
    std::cout << ">> fired";
    return in;
}

