#include <cstdio> // for printf

class vehicles_t{
    float fuel;
    float fuel_cons;
    float fuel_max;
    char* name;
    public :
        void initialize_vehicles(float fuel,float fuel_cons,float fuel_max,char* name){
            this->fuel=fuel;
            this->fuel_cons=fuel_cons;
            this->fuel_max=fuel_max;
            this->name=name;
        };

        float get_fuel() const{
            return this->fuel;
        };

         float get_fuel_cons() const{
            return this->fuel_cons;
        };

         float get_fuel_max() const{
            return this->fuel_max;
        };

         char* get_name() const{
            return this->name;
        };
        bool move(float km=1){
            float consome=this->fuel_cons/km;
            if(km<0 or this->fuel<consome){
                printf("Unable to move the car (%1.0f km)\n",km);
                return false;

            }
            else{
                this->fuel-=consome;
                printf("Car moved (%0.1f km)\n",km);
                return true;
            }
        };
        bool refuel(float l){
            if(l+this->fuel>this->fuel_max or l<0){
                return false;
            }
            else{
                this->fuel+=l;
                return true;
            }
        };

        virtual void print(){};

};

class car_t : vehicles_t{
    bool hand_brake_enabled;
    public :
        void initialize_car(float fuel,float fuel_cons,float fuel_max,char* name,bool hand_brake_enabled){
            initialize_vehicles(fuel,fuel_cons,fuel_max,name);
            this->hand_brake_enabled=hand_brake_enabled;
        }
        void set_hand_brake(bool hand_brake_enabled){
            this->hand_brake_enabled=hand_brake_enabled;
        }
        bool get_hand_brake(){
            return this->hand_brake_enabled;
        }
        bool move(float km=1){
            if(this->hand_brake_enabled==true){
                printf("Unable to move the car (%1.0f km)\n",km);
                return false;
            }
            else{
                vehicles_t::move(km);
                return true;
            }
        };

        void print(){
            printf("Car (%s,%0.2f/%0.2f 1, %0.2f 1/100 km, hand brake : %d \n",get_name(),get_fuel(),get_fuel_max(),get_fuel_cons(),get_hand_brake());
        };
};

int main(){
    car_t Mercedez, BMW;
    Mercedez.initialize_car(1.7,11.0,2.1,const_cast<char*>("Mercedes A-Class"),false);
    Mercedez.print();
    Mercedez.move(1);
    Mercedez.print();
    Mercedez.move(100);
    Mercedez.print();

    BMW.initialize_car(57.20,11.30,65.0,const_cast<char*>("(BMW X4"),false);
    BMW.print();
    BMW.move(1);
    BMW.print();
    BMW.move(100);
    BMW.print();
    BMW.set_hand_brake(true);
    BMW.print();
    BMW.move(100);
    BMW.print();
    Mercedez.print();
    BMW.print();




}
