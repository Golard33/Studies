#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <string>
#include "address.h"
using namespace std;

enum priority_t{
    undefined,
    high,
    low,
    medium
};

class envelope_t{
    private:
        priority_t priority;
        address_t recipient;
        address_t sender;
    protected:
        int height;
        int width;
    public:
        envelope_t();
        int get_height() const;
        priority_t get_priority() const;
        address_t get_recipient() const;
        address_t get_sender() const;
        int get_width() const;
        void handle_e() const;
        void handle_ec(int postal_code) const;
        void handle_ecge(int postal_code) const;
        void handle_ecgt(int postal_code) const;
        void handle_ecle(int postal_code) const;
        void handle_eclt(int postal_code) const;
        void handle_en(string name) const;
        void set_priority(priority_t priority);
        void set_recipient(address_t recipient);
        void set_sender(address_t sender);
};

ostream &operator<<(ostream &os, const envelope_t &envelope);

#endif