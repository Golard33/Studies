#include <cstdio>
#include <iostream>
#include <pugixml.hpp>
#include <cstdlib>
#include <cstring>
#include "company.h"
#include "envelope-c4.h"
#include "envelope-dl.h"
#include "str2i-error.h"
#include "str2l-error.h"

using namespace std;
using namespace pugi;


#define INT_MIN -21474836 - 1
#define INT_MAX 2147483647
#define LONG_MIN -9223372036854775807 - 1
#define LONG_MAX 9223372036854775807

/*lit le code postal*/
int r_postal_code(xml_node node)
{
    long postal_code;
    char *endPtr;
    postal_code = strtol(node.child_value(), &endPtr, 10);
    /* on verifie que le code postal ne depasse pas la plage de valeurs de long ainsi que la taille*/
    if(*endPtr != '\0' || postal_code >= LONG_MAX || postal_code <= LONG_MIN)
    {
        throw str2l_error(node.child_value());
    }else
    {
        if(postal_code > INT_MAX || postal_code < INT_MIN)
        {
            throw str2i_error(node.child_value());
        }else
        {
            return (int)postal_code;
        }
    }
}

/* on lit l'adresse en fonction des commandes*/
int r_address(xml_node node, address_t *address, char *command){
    int postal_code;
    /*on accede aux elements dans le xml*/
    node = node.first_child();
    address->set_city(node.child_value());
    node = node.next_sibling();
    address->set_country(node.child_value());
    node = node.next_sibling();
    address->set_name(node.child_value());
    node = node.next_sibling();
    try{
        postal_code = r_postal_code(node);
    }catch(exception &e){
        cerr << command << ": an exception occured (" << e.what() << ")\n";
        return 1;
    }
    address->set_postal_code(postal_code);
    node = node.next_sibling();
    address->set_street(node.child_value());
    return 0;
}

/* on lit le format d'une enveloppe */
int r_envelope(xml_node node, envelope_t *envelope, char *command){
    address_t *address;
    node = node.first_child();
    if(!strcmp(node.child_value(), "low")){
        envelope->set_priority(low);
    }else if(!strcmp(node.child_value(), "medium")){
        envelope->set_priority(medium);
    }else if(!strcmp(node.child_value(), "high")){
        envelope->set_priority(high);
    }
    node = node.next_sibling();
    address = new address_t;
    if(r_address(node, address, command)){
        return 1;
    }
    envelope->set_recipient(*address);
    delete address;
    node = node.next_sibling();
    address = new address_t;
    if(r_address(node, address, command)){
        return 1;
    }
    envelope->set_sender(*address);
    delete address;
    return 0;
}

int main(int argc, char *argv[]){
    int i, Char, end, postal_code;
    char *command, *arg, ccmd[20], *endPtr;
    xml_document doc;
    xml_parse_result rslt;
    xml_node node, node2;
    xml_attribute attr;
    company_t *company;
    envelope_c4_t *c4;
    envelope_dl_t *dl;
    /*Verifie qu'il y a bien un seul argument*/
    if(argc != 2){
        cerr << argv[0] << ": invalid number of arguments\n";
        return 1;
    }
    /*Verifie s'il y a bien un document correct lisible*/
    rslt = doc.load_file(argv[1]);
    if(!rslt){
        cerr << argv[0] << ": unable to parse the document\n";
        return 1;
    }
    company = new company_t;
    node = doc.child("company");
    /*Verifie que les donnes sont du bon types*/
    if(!node){
        cerr << argv[0] << ": invalid type of data\n";
        return 1;
    }
    company->set_name(node.first_attribute().value());
    for(node = node.first_child(); node; node = node.next_sibling()){
        if(!strcmp(node.name(),"envelopes")){
            for(node2 = node.first_child(); node2; node2 = node2.next_sibling()){
                attr = node2.first_attribute();
                if(!strcmp(attr.value(),"c4")){
                    c4 = new envelope_c4_t;
                    if(r_envelope(node2,c4,argv[0])){
                        return 1;
                    }
                    company->envelopes_push_back(*c4);
                    delete c4;
                }else if(!strcmp(attr.value(),"dl")){
                    dl = new envelope_dl_t;
                    if(r_envelope(node2,dl,argv[0])){
                        return 1;
                    }
                    company->envelopes_push_back(*dl);
                    delete dl;
                }
            }
        }
        if(!strcmp(node.name(),"web")){
            company->set_web(node.child_value());
        }
    }
    end = 0;
    while(!end)
    {
        cout << "EDP> ";
        Char = 0;
        /* on recupere la commande dans le terminal*/
        fgets(ccmd, 20, stdin);
        if(ccmd[strlen(ccmd) - 1] != '\n'){
            while(getchar() != '\n');
            Char = 1;
        }
        command = &ccmd[0];
        ccmd[strlen(ccmd) - 1] = '\0';
        for(i = 0; i < (int)strlen(ccmd) && arg == NULL; i++){
            if(ccmd[i] == ' '){
                ccmd[i] = '\0';
                if(ccmd[i + 1] != '\0'){
                    arg = &ccmd[i + 1];
                }
            }
        }
        if(!Char){
            if(!strcmp(command, "h")){
                    cout << "e: prints the envelopes\n"
                    << "ec CODE: prints the envelopes with the sender postal code equal to CODE\n"
                    << "ecge CODE: prints the envelopes with the sender postal code greater than or equal to CODE\n"
                    << "ecgt CODE: prints the envelopes with the sender postal code greater than CODE\n"
                    << "ecle CODE: prints the envelopes with the sender postal code less than or equal to CODE\n"
                    << "eclt CODE: prints the envelopes with the sender postal code less than CODE\n"
                    << "en NAME: prints the envelopes with the sender name containing NAME\n"
                    << "h: prints this help\n"
                    << "i: prints information about the company\n"
                    << "n: prints the company name\n"
                    << "q: quits EDP\n"
                    << "v: prints the EDP version\n"
                    << "w: prints the company web address\n";

            }else if(!strcmp(command, "q")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the q command\n";
                }else{
                    end = 1;
                }
            }else if(!strcmp(command, "v")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the v command\n";
                }else{
                    cout << "EDP (Envelope Delivery Program) 20222104.\n\n"
                    << "Copyright (C) 2022 Florian Robin and Lucas Marquez.\n\n"
                    << "Written by Florian Robin <florian.robin@univ-pau.fr> and Lucas Marquez <lucas.marquez@univ-pau.fr> .\n";
                }
            }else if(!strcmp(command, "i")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the i command\n";
                }else{
                    cout << *company << endl;
                }
            }else if(!strcmp(command, "n")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the n command\n";
                }else{
                    company->handle_n();
                }
            }else if(!strcmp(command, "e")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the e command\n";
                }else{
                    company->handle_e();
                }
            }else if(!strcmp(command, "w")){
                if(arg != NULL){
                    cout << argv[0] << ": too many parameters for the w command\n";
                }else{
                    company->handle_w();
                }
            }else if(!strcmp(command, "en")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the en command\n";
                }else{
                    company->handle_en(arg);
                }
            }else if(!strcmp(command, "ec")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the ec command\n";
                }else{
                    postal_code = (int)strtol(arg, &endPtr, 10);
                    if(*endPtr == '\0' && postal_code < INT_MAX && postal_code > INT_MIN){
                        company->handle_ec(postal_code);
                    }else{
                        cout << argv[0] << ": invalid parameter for the ec command\n";
                    }
                }
            }else if(!strcmp(command, "ecge")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the ecge command\n";
                }else{
                    postal_code = (int)strtol(arg, &endPtr, 10);
                    if(*endPtr == '\0' && postal_code < INT_MAX && postal_code > INT_MIN){
                        company->handle_ecge(postal_code);
                    }else{
                        cout << argv[0] << ": invalid parameter for the ecge command\n";
                    }
                }
            }else if(!strcmp(command, "ecgt")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the ecgt command\n";
                }else{
                    postal_code = (int)strtol(arg, &endPtr, 10);
                    if(*endPtr == '\0' && postal_code < INT_MAX && postal_code > INT_MIN){
                        company->handle_ecgt(postal_code);
                    }else{
                        cout << argv[0] << ": invalid parameter for the ecgt command\n";
                    }
                }
            }else if(!strcmp(command, "ecle")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the ecle command\n";
                }else{
                    postal_code = (int)strtol(arg, &endPtr, 10);
                    if(*endPtr == '\0' && postal_code < INT_MAX && postal_code > INT_MIN){
                        company->handle_ecle(postal_code);
                    }else{
                        cout << argv[0] << ": invalid parameter for the ecle command\n";
                    }
                }
            }else if(!strcmp(command, "eclt")){
                if(arg == NULL){
                    cout << argv[0] << ": missing parameter for the eclt command\n";
                }else{
                    postal_code = (int)strtol(arg, &endPtr, 10);
                    if(*endPtr == '\0' && postal_code < INT_MAX && postal_code > INT_MIN){
                        company->handle_eclt(postal_code);
                    }else{
                        cout << argv[0] << ": invalid parameter for the eclt command\n";
                    }
                }
            }else{
                cout << argv[0] << ": invalid command\n";
            }
            }else{
           cout << argv[0] << ": too many characters for the command\n";
        }
        command = NULL;
        arg = NULL;
    }
    return 0;
}