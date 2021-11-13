#include<iostream>
using namespace std;

//Abstract Product class
class Product{
    public:
    virtual void display()=0;
};
//concrete Product class's
class car:public Product{
    public:
    car(){ cout << "Car Product\n";}
    virtual void display(){ cout <<"New Car is created \n";}
};
class bike:public Product{
    public:
    bike(){ cout << "Bike Product\n";}
    virtual void display(){ cout <<"New bike is created \n";}
};
class plain:public Product{
    public:
    plain(){ cout << "Plain Product\n";}
    virtual void display(){ cout <<"New Plain is created \n";}
};
//Factory Class
class FactoryToy{
    public:
    static Product* create_toy(int type){ //Factory Method
        Product *T_obj;
        if(type == 1)
            T_obj = new car;
        if(type == 2)
            T_obj = new bike;
        if(type == 3)
            T_obj = new plain;
        
        return T_obj;
    }
};

//Client code
int main()
{
    //vehicle *V_obj;
    int type;
    while(1){
        cout << "1 : car 2:Bike 3:Plain 0 : Exit\n";
        cin >> type;
        Product *p_obj = FactoryToy::create_toy(type);
        
        if(p_obj){
            p_obj->display();
            delete p_obj;
        }
    }
    return 0;
}
