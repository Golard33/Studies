#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include "envelope.h"
using namespace std;

class company_t{
    vector<envelope_t> envelopes;
    string name;
    string web;
    public:
        company_t();
        string get_name() const;
        string get_web() const;
        void handle_e() const;
        void handle_i() const;
        void handle_n() const;
        void handle_ec(int postal_code) const;
        void handle_ecge(int postal_code) const;
        void handle_ecgt(int postal_code) const;
        void handle_ecle(int postal_code) const;
        void handle_eclt(int postal_code) const;
        void handle_en(string name) const;
        void handle_w() const;
        envelope_t envelope_at(int index) const;
        void envelopes_push_back(envelope_t envelope);
        int envelopes_size() const;
        void set_name(string name);
        void set_web(string web);
};

ostream &operator<<(ostream &os, const company_t &company);

#endif