#include <string>
#include <stdio.h>
#include <memory>
#include "Animal.h"
using namespace std; 


class Dog: public Mammal{
    public:
        Dog(string n, COLOR c):Mammal(n, c){
        }// should be able to access the methods 
        void speak() {
            cout << "Dog Woofs"<< endl ;
        }
        void move() {
            cout<< "Dog Runs" <<endl;
        }
        void eat() {
            cout<< "Dog licks" <<endl;
        }
        ~Dog() {
            cout << "destructing Dog object "<< endl ;
            }
        

};
class Cat: public Mammal{
    public:
        Cat(string n, COLOR c):Mammal(n, c){
        }// should be able to access the methods 
        void speak() {
            cout << "Cat Meows "<< endl ;
        }
        void move() {
            cout<< "Cat Stretch" <<endl;
        }
        void eat() {
            cout<< "Cat licks" <<endl;
        }
        ~Cat() {
            cout << "destructing Cat object "<< endl ;
            }
        

};
class Lion: public Mammal{
    public:
        Lion(string n, COLOR c):Mammal(n, c){
        }// should be able to access the methods 
        void speak() {
            cout << "Lion Roars "<< endl ;
        }
        void move() {
            cout<< "Lion Pounces" <<endl;
        }
        void eat() {
            cout<< "Lion devours" <<endl;
        }
        ~Lion() {
            cout << "destructing Lion object "<< endl ;
            }
        

};
