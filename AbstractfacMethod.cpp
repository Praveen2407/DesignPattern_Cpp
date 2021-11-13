/******************************************************************************

    Abstract Factory Method

*******************************************************************************/

#include <iostream>

using namespace std;

//Abstract Product class
class vehicle{
    public:
    virtual void display()=0;
};
//concrete Product class's
class twoWheller:public vehicle{
    public:
    virtual void display(){
        cout << "Two Wheller is created\n";
    }
};
class threeWheller:public vehicle{
    public:
    virtual void display(){
        cout << "Three Wheller is created\n";
    }
};

//Abstract Client
class Generator{
    
    vehicle *v;
    public:
    //Abstract Factory Method
    virtual vehicle *create_Vechicle() = 0;
    //Abstract Method
    vehicle *NewVehicle(){
        cout << "Creating New vehicle\n";
        v = create_Vechicle();
        return v;
    }
};

class twoWhellerGen:public Generator{
    public:
    virtual vehicle *create_Vechicle(){
        return new twoWheller;
    }
};
class threeWhellerGen:public Generator{
    public:
    virtual vehicle *create_Vechicle(){
        return new threeWheller;
    }
};


int main()
{
    vehicle *V_obj;
    Generator *G_obj; //Product
    
    G_obj = new threeWhellerGen(); //con Product
    V_obj = G_obj->NewVehicle(); //Abs method
    V_obj->display();

    G_obj = new twoWhellerGen();
    V_obj = G_obj->NewVehicle();
    V_obj->display();
    return 0;
}
