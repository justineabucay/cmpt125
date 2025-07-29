#include <iostream> 
using namespace std; 

class Dog{
    public: 
        void bark(string sound){
            cout << sound << "\n";      // print out sound
        }
};

int main(){
    Dog pet; 
    pet.bark("bark!");
    return 0;
}