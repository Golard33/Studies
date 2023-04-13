#ifndef STR2L_ERROR_H
#define STR2L_ERROR_H
#include <string>
using namespace std;

class str2l_error: public exception{
    string str;
    public:
        str2l_error(string str);
        ~str2l_error() throw();
        const char *what() const throw();
};

#endif