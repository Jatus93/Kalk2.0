#ifndef ILLEGALColorEXCEPTION_H
#define ILLEGALColorEXCEPTION_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
using namespace std;
class IllegalColorException: public runtime_error{
public:
    IllegalColorException(std::string e):runtime_error (e){}
};

#endif // ILLEGALColorEXCEPTION_H