#include "mixednumber.h"

std::ostream& operator<<( std::ostream &out, const mixedNumber &m)
{
     int whole = m.num/m.denom, numerator = m.num % m.denom;
     if(numerator == 0)
         out<<whole;
     else
         if(whole == 0)
             out<<numerator<<"/"<<m.denom;
        else
             out<<whole<<char(0)<<abs(numerator)<<"/"<<m.denom;
     // We use a char(0) which is a null character to denote a space. This is primarily for use
     // in our parser class, which needs to differentiate between a space between tokens and
     // a space between mixed numbers.
     return out;
}

std::istream& operator>>( std::istream &in, mixedNumber &m)
{ // Need to add cin logic? // need to add getline logic?
    fraction temp_whole, temp_mixed;

    std::stringstream ss;
    std::string possibleMixed;
    if(&in == &std::cin)
    { //This means that the program is reading from the console
        if(in>>possibleMixed)
        {
            if(possibleMixed.find_first_not_of("-+0123456789./") < possibleMixed.size())
                throw Error("Invalid mixed number input.");
            ss<<possibleMixed;
            ss>>m;
        }
    }
    else{
        if (in >> temp_whole)
            if (in.peek() == ' ')
            {
                while(in.peek() == ' ')
                { //deletes extraneous spaces
                   in.get();
                }
                in >> temp_mixed;
                if ((temp_mixed.getDenom() <= temp_mixed.getNum()) ||
                    (temp_mixed.getDenom() < 0) ||
                    (temp_mixed.getNum()<0))
                    throw Error("Invalid mixed number input.");
            }

        if(temp_whole < 0)
            temp_mixed *= -1;

        if(in.fail())
        {
            m=temp_whole;
            in.clear();
        }
        else
            m = (temp_whole += temp_mixed);
        return in;
        }
    return in;
}
