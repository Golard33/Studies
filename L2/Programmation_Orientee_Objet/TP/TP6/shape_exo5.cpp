#include <cstdio>
#include <iostream>

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
    shape_t &operator++(){
      ++this->width;
      ++this->height;
      return *this;
    }
    shape_t &operator--(){
      --this->width;
      --this->height;
      return *this;
    }
};

class rectangle_t: public shape_t{
  public:
    rectangle_t(float width, float height): shape_t(width, height)
    {}
    float get_area() const {return (this->get_width()*this->get_height());} //Redefinition de la méthode virtuelle pure get_area
    void print(){
      printf("Rectangle (width: %.2f, height: %.2f, area: %.2f)\n", this->get_width(), this->get_height(), this->get_area());
    }
    rectangle_t operator++(int){
      rectangle_t r = *this;
      ++*static_cast<shape_t*>(this); //Upcast vers shape_t puis appel de l'operateur préfixé
      return r;
    }
    rectangle_t operator--(int){
      rectangle_t r = *this;
      --*static_cast<shape_t*>(this); //Upcast vers shape_t puis appel de l'operateur préfixé
      return r;
    }
};

class triangle_t: public shape_t{
  public:
    triangle_t(float width, float height): shape_t(width, height)
    {}
    float get_area() const {return ((this->get_width()*this->get_height())/2.0);} //Redefinition de la méthode virtuelle pure get_area
    void print(){
      printf("Triangle (width: %.2f, height: %.2f, area: %.2f)\n", this->get_width(), this->get_height(), this->get_area());
    }
    triangle_t operator++(int){
      triangle_t t = *this;
      ++*static_cast<shape_t*>(this); //Upcast vers shape_t puis appel de l'operateur préfixé
      return t;
    }
    triangle_t operator--(int){
      triangle_t t = *this;
      --*static_cast<shape_t*>(this); //Upcast vers shape_t puis appel de l'operateur préfixé
      return t;
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

int main(){
  //shape_t *shape = new shape(2.50, 3.60); Impossible car shape_t contient une méthode virtuelle pure
  shape_t *rectangle = new rectangle_t(10.0, 20.0);
  shape_t *triangle = new triangle_t(30.0, 30.0);
  shape_t *circle = new circle_t(40.0);

  rectangle_t *ptr1 = dynamic_cast<rectangle_t*>(rectangle); //Downcast vers rectangle_t
  if(ptr1==NULL){ //Ne pas oublier la verif...
    fprintf(stderr, "Downcast failure: Cannot switch from shape_t to rectangle_t");
    return 1;
  }

  triangle_t *ptr2 = dynamic_cast<triangle_t*>(triangle); //Downcast vers triangle_t
  if(ptr2==NULL){
    fprintf(stderr, "Downcast failure: Cannot switch from shape_t to triangle_t");
    return 1;
  }

  std::cout << "(++*rectangle).get_width(): " << (++*rectangle).get_width() << std::endl;
  std::cout << "(--*triangle).get_width(): " << (--*triangle).get_width() << std::endl;

  std::cout << "((*ptr1)++).get_width(): " << ((*ptr1)++).get_width() << std::endl;
  std::cout << "((*ptr2)--).get_width(): " << ((*ptr2)--).get_width() << std::endl;

  rectangle->print();
  triangle->print();
  circle->print();
  delete rectangle;
  delete triangle;
  delete circle;
  return 0;
}
