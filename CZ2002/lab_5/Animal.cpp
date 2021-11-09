#include <iostream>
#include <string>
using namespace std; 

enum COLOR { Green, Blue, White, Black, Brown } ;
class Animal {
    public :
    Animal(string n, COLOR c) : _name(n), _color(c) {
        switch(_color){
            case 0:
                cout << "Constructing Animal object "<< _name << " of the color Green" <<endl;
                break;
            case 1:
                cout << "Constructing Animal object "<< _name << " of the color Blue" <<endl;
                break;
            case 2:
                cout << "Constructing Animal object "<< _name << " of the color White " <<endl;
                break;
            case 3:
                cout << "Constructing Animal object "<< _name << " of the color Black" <<endl;
                break;
            case 4: 
                cout << "Constructing Animal object "<< _name << " of the color Brown" <<endl;
                break;
            default:
                 cout << "Constructing Animal object "<< _name << " of the color unknown color" <<endl;
                 break;
        }
    
    }
    ~Animal() {
    cout << "destructing Animal object "<< _name << endl ;
    }
    virtual void speak()=0;
    virtual void move()=0;
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

class Dog: public Mammal{
    public:
        Dog(string n, COLOR c, string Owner):Mammal(n, c), _Owner(Owner){
            cout << "The Owner is " << _Owner <<endl;
        }// should be able to access the methods 
        void speak() {
            cout << "Dog Woofs "<< endl ;
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
        

    private:
        string _Owner;
};


int main() {
    //cout<<"Section 3.1.2 Overload the Animal constructor by another constructor which will intialize the name and the color"<<endl;
    //Animal a("Lovely", Blue);
    //a.move();
    //a.speak();
    //cout<< "Section 3.2.1 Create Mammal subclass inheriting from Animal class" <<endl;
    //Mammal m("Mammy", Green);
    //m.move();
    //m.speak();
    //m.eat();
    //cout<< "Section 3.2.2 Create Dog subclass inheriting from Mammal class" <<endl;
    //cout << "call speak function and move function, additionally change speak to woof, and add virtual function" << endl;
    //cout <<"Section 3.2.4 pure method with =0 addition (final answer)" <<endl;
    //Dog d("Doggy", Black, "Samiksha");
    //d.move();
    //d.speak();
    //d.eat();
    cout << "Section 3.3.3 Polymorphism: Build a Zoo Virtual Function Magic" << endl;
    //Animal *animalptr = new Dog("Lassie", White, "Andy");
    //animalptr->move();
    //animalptr->speak();
    //animalptr->~Animal();
    Dog dogi("Lassie", White, "Andy");

    Mammal *aniPtr = &dogi ;
    Mammal &aniRef = dogi ;
    Mammal aniVal = dogi ;
    aniPtr->speak() ;
    aniRef.speak() ;
    aniVal.speak() ;

    cout << "Program exiting .... "<< endl ;


    return 0;
}