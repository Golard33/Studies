#include <iostream>
#include "company.h"

company_t::company_t(){
    this->name = "undefined";
    this->web = "undefined";
}

string company_t::get_name() const{
    return this->name;
}

string company_t::get_web() const{
    return this->web;
}

void company_t::handle_e() const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_e();
    }
}

void company_t::handle_i() const{
    cout << *this << endl;
}

void company_t::handle_n() const{
    cout << this->get_name() << endl;
}

void company_t::handle_ec(int postal_code) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_ec(postal_code);
    }
}

void company_t::handle_ecge(int postal_code) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_ecge(postal_code);
    }
}

void company_t::handle_ecgt(int postal_code) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_ecgt(postal_code);
    }
}

void company_t::handle_ecle(int postal_code) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_ecle(postal_code);
    }
}

void company_t::handle_eclt(int postal_code) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_eclt(postal_code);
    }
}

void company_t::handle_en(string name) const{
    int i;
    for(i = 0; i < this->envelopes_size(); i++){
        this->envelope_at(i).handle_en(name);
    }
}

void company_t::handle_w() const{
    cout << this->get_web() << endl;
}

envelope_t company_t::envelope_at(int index) const{
    return this->envelopes[index];
}

void company_t::envelopes_push_back(envelope_t envelope){
    this->envelopes.push_back(envelope);
}

int company_t::envelopes_size() const{
    return this->envelopes.size();
}

void company_t::set_name(string name){
    this->name = name;
}

void company_t::set_web(string web){
    this->web = web;
}

ostream &operator<<(ostream &os, const company_t &company){
    int i;
    os << "(" << company.get_name() << ", " << company.get_web() << ", (";
    for(i = 0; i < company.envelopes_size(); i++){
        if(i == company.envelopes_size() - 1){
            cout << company.envelope_at(i) << "))";
        }else{
            cout << company.envelope_at(i) << ", ";
        }
    }
    return os;
}