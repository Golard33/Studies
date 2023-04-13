#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class address_t{
    string city;
    string country;
    string name;
    int postal_code;
    string street;
    public:
        address_t();
        string get_city() const;
        string get_country() const;
        string get_name() const;
        int get_postal_code() const;
        string get_street() const;
        void set_city(string city);
        void set_country(string country);
        void set_name(string name);
        void set_postal_code(int postal_code);
        void set_street(string street);
};

ostream &operator<<(ostream &os, const address_t &address);

#endif
