#include <string>
#include <stdio.h>
#include <memory>
using namespace std; 

enum COLOR { Green, Blue, White, Black, Brown } ;    
class Animal {
    public :
    Animal(string n, COLOR c) : _name(n), _color(c) {    
    }
    ~Animal() {
    cout << "destructing Animal object "<< _name << endl ;
    }
    virtual void speak()=0;
    virtual void move()=0;
    virtual void eat()=0;
    private :
    string _name;
    COLOR _color ;
};

class Mammal: public Animal{
    public:
        Mammal(string n, COLOR c):Animal(n, c){
        }// should be able to access the methods 
        void eat() {
            cout<<"Mammal eat "<<endl;
        }
        void speak(){
            cout << "Mammal speaks "<< endl ;
        }
        void move() {
            cout <<"Mammal Moves"<<endl;
        }
        ~Mammal() {
            cout << "destructing Mammal object "<< endl ;
            }

};

