#ifndef STR2I_ERROR_H
#define STR2I_ERROR_H
#include <string>
using namespace std;

class str2i_error: public exception{
    string str;
    public:
        str2i_error(string str);
        ~str2i_error() throw();
        const char *what() const throw();
};

#endif
