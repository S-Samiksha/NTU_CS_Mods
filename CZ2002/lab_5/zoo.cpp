#include <iostream>
#include <string>
using namespace std; 

enum COLOR { Green, Blue, White, Black, Brown } ;
class Animal {
    public :
        virtual void speak()=0;
        virtual void move()=0;
        virtual ~Animal(){cout<< "Animal Destructed..."<<endl;}
    protected :
        string _name;
        COLOR _color;
        string _owner;
        Animal(string n, COLOR c, string o): _name(n), _color(c), _owner(o){}
       
};

class Mammal: public Animal{
    public:
        Mammal(string n, COLOR c, string o):Animal(n,c,o){
            switch(c){
            case 0:
                cout << "constructing Animal object "<< n << " of the color Green" <<endl;
                break;
            case 1:
                cout << "constructing Animal object "<< n << " of the color Blue" <<endl;
                break;
            case 2:
                cout << "constructing Animal object "<< n << " of the color White " <<endl;
                break;
            case 3:
                cout << "constructing Animal object "<< n << " of the color Black" <<endl;
                break;
            case 4: 
                cout << "constructing Animal object "<< n << " of the color Brown" <<endl;
                break;
            default:
                 cout << "constructing Animal object "<< n << " of the color unknown color" <<endl;
                 break;
        }

    
        }// should be able to access the methods 

        void eat() const{
            cout<<"Mammal eat "<<endl;
        }
        void speak() {
            cout << "Mammal speaks "<< endl ;
        }
        void move(){
            cout<<"Mammal move"<<endl;
        }
        ~Mammal(){cout<< "Mammal Destructed..."<<endl;}

};

class Dog: public Mammal{
    public:
        Dog(string n, COLOR c, string o):Mammal(n, c, o){
            cout << "The Owner is " << o <<endl;
        }// should be able to access the methods 

        void eat() const{
            cout<<"Dog eat "<<endl;
        }
        void speak() {
            cout << "Dog woof "<< endl ;
        }
        void move(){
            cout<<"Dog move"<<endl;
        }
        ~Dog(){cout<< "Dog Destructed..."<<endl;}

};
class Cat: public Mammal{
    public:
        Cat(string n, COLOR c, string o):Mammal(n, c, o){
            cout << "The Owner is " << o <<endl;
        }// should be able to access the methods 

        void eat() const{
            cout<<"Cat eat "<<endl;
        }
        void speak() {
            cout << "Cat Meow "<< endl ;
        }
        void move(){
            cout<<"Cat Move"<<endl;
        }
        ~Cat(){cout<< "Cat Destructed..."<<endl;}

};
class Lion: public Mammal{
    public:
        Dog(string n, COLOR c, string o):Mammal(n, c, o){
            cout << "The Owner is " << o <<endl;
        }// should be able to access the methods 

        void eat() const{
            cout<<"Lion eat "<<endl;
        }
        void speak() {
            cout << "Lion Roar "<< endl ;
        }
        void move(){
            cout<<"Lion move"<<endl;
        }
        ~Lion(){cout<< "Lion Destructed..."<<endl;}

};

int main() {
    

}