#include <iostream>
#include <string>
#include <stdio.h>
#include <memory>
#include "childAnimal.h"
using namespace std; 

int main() {
    std::unique_ptr<Mammal> myZoo[100];
    int c = 0, i=0, j=0;
    string _name;
    string _color;
    do {
        cout <<"Select Animal to send to Zoo" << endl;
        cout << "(1) Dog" <<endl;
        cout << "(2) Cat" <<endl;
        cout << "(3) Lion" <<endl;
        cout << "(4) Move all animals" <<endl;
        cout << "(5) Quit" <<endl;
        cin >> c;
        switch(c){
            case 1:
                cout<<"Name?"<<endl;
                cin >> _name;
                myZoo[i] = std::make_unique<Dog>(_name, White);
                i++;
                break;
            case 2:
                cout<<"Name?"<<endl;
                cin >> _name;
                myZoo[i] = std::make_unique<Cat>(_name, Black);
                i++;
                break;
            case 3:
                cout<<"Name?"<<endl;
                cin >> _name;
                myZoo[i] = std::make_unique<Lion>(_name, White);
                i++;
                break;
            case 4:
                for (j=0; j<i;j++){
                    myZoo[j]->eat();
                    myZoo[j]->move();
                    myZoo[j]->speak();
                }
                break;
            case 5:
                break;
            default:
                cout<<"Wrong number. Enter Again"<<endl;
                c=0;
                break;
        }



    }while (c!=5);





    return 0;
}