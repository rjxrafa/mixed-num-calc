#ifndef ERROR_H
#define ERROR_H
#include <exception>

class Error : public std::exception
{ // Implementation courtesy of
  // https://www.lynda.com/C-tutorials/Reporting-errors-exceptions/182674/366572-4.html
  // This implementation allows for us to pass errors as a string and throw them back using what();
    const char * message = nullptr;
    Error() {};
public:
    Error(const char * s) throw() : message(s) {}
    const char * what() const throw() {return message;}
};

#endif // ERROR_H
