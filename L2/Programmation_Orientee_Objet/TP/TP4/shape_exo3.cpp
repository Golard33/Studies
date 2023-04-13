#include <cstdio>

class shape_t{
  float width;
  float height;
  public:
    shape_t(float width, float height): width(width), height(height)
    {}
    virtual float get_area() const = 0; // Méthode virtuelle pure
    float get_width() const {return this->width;}
    float get_height() const {return this->height;}
    virtual void print(){
      printf("Shape (width: %.2f, height: %.2f)\n", this->width, this->height);
    }
    virtual ~shape_t(){}
};
class rectangle_t: public shape_t{
  public:
    rectangle_t(float width, float height): shape_t(width, height)
    {}
    float get_area() const {return (this->get_width()*this->get_height());} //Redefinition de la méthode virtuelle pure get_area
    void print(){
      printf("Rectangle (width: %.2f, height: %.2f, area: %.2f)\n", this->get_width(), this->get_height(), this->get_area());
    }
};

class circle_t: public shape_t{
  public:
    circle_t(float diameter): shape_t(diameter, diameter)
    {}
    float get_area() const {return ((this->get_width()/2.0*this->get_height()/2.0)*3.14);} //Redefintion de la méthode virtuelle pure get_area
    void print(){
      printf("Circle (width: %.2f, height: %.2f, area: %.2f)\n", this->get_width(), this->get_height(), this->get_area());
    }
};

class musical_instrument_t{
  float frequency;
  public:
    musical_instrument_t(float frequency) : frequency(frequency)
    {}

    float get_frequency(){
      return this->frequency;
    };
    void set_frequency(float frequency){
      this->frequency=frequency;
    };
};


class triangle_t: public shape_t,public musical_instrument_t{
  public:
    triangle_t(float width, float height,float frequency): shape_t(width, height) , musical_instrument_t(frequency)
    {}
    float get_area() const {return ((this->get_width()*this->get_height())/2.0);} //Redefinition de la méthode virtuelle pure get_area
    void print(){
      printf("Triangle (width: %.2f, height: %.2f, area: %.2f, frequency : %0.2f Hz)\n", this->get_width(), this->get_height(), this->get_area(),this->get_frequency());
    }
};





int main(){
  //shape_t *shape = new shape(2.50, 3.60); Impossible car shape_t contient une méthode virtuelle pure
  shape_t *rectangle = new rectangle_t(10.0, 20.0);
  shape_t *triangle = new triangle_t(30.0, 30.0,1047.0);
  shape_t *circle = new circle_t(40.0);
  rectangle->print();
  triangle->print();
  circle->print();
  delete rectangle;
  delete triangle;
  delete circle;
  return 0;
}
