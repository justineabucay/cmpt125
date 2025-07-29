# C++ OOP

- **OOP** = Object-Oriented Programming -> creating objs, which can hold data and functions that work on that data

## what are classes and objects? 
- <mark>class</mark> defines what an object should look like
- <mark>object</mark> is created based on that class
&nbsp;for example: FRUITS -> APPLE, BANANA + MANGO

## procedural vs. OOP
- **procedural**: writing functions that operate on data
- **OOP**: creating objects that contain <mark>both data and functions</mark>


# C++ Classes + Objects

## classes/objects
an example of classes and objects in real life: 
&nbsp; car (obj) has attributes, like weight and colour. and methods, like brake and drive. 

in this case, attributes and methods are bariables and mfunctions that belong to a class. the class is data type that we define and can use throughout our program. it also serves as the blueprint for creating objects.  

## create a class

```C++
    class MyClass {
        public:                 // access specifier
            int myNum;          // attribute
            string myString;    // attribute
    }
```

the <mark>access specifies</mark> specifies class members are accessible from outside the class. 

## create an object

```C++
    int main(){
        myClass myObj;          // create an object

        // access attributes + set values
        myObj.myNum = 15; 
        myObj.myString = "Some text"; 

        // print attribute values
        cout << myObj.myNum << "\n"; 
        cout << myObj.myString << "\n";
        return 0;
    }
```

you can also create multiple objects using the same data type

## challenge 
```C++ 
    class Book{
        public:         
            string title; 
            string author; 
            int year; 
    }

    int main(){
        Book b1; 
        Book b2; 

        b1.title = "the name of the first book";
        b1.author = "some guy";
        b1.year = 1990;

        b2.title = "the name of the second book"; 
        b2.author = "some other guy";
        b2.year = 1290; 

        cout << b1.title << " " << b1.author << " " << b1.year << "\n"; 
        cout << b2.title << " " << b2.author << " " << b2.year << "\n"; 
    return 0; 
    }
```


# header and implementation files
classes are made up of a header file and an implementation file, with the same name but different extentions.  that is, header file has .h extension, and implementation file has .cpp extension. 

header: class definition = class name, the name of its data members and declaration of each of its methods. 

on the other hand, implementation file: implementation of these class methods.  

both files should contain the same class documentation;
that is, header comment block and description for each method

# C++ Class Methods
## class methods

there are two ways to define functions:
- inside class
- outside class

### define a method inside class

```C++ 
class MyClass {        // The class
  public:              // Access specifier
    void myMethod() {  // Method/function defined inside the class
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
```



### define a method outside class

we can first declare the method inside the class and define it later

```C++ 
class MyClass {        // The class
  public:              // Access specifier
    void myMethod();   // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod() {
  cout << "Hello World!";
}

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
```

## parameters

you can pass values to methods like functions

```C++ 
#include <iostream>
using namespace std;

class Car {
  public:
    int speed(int maxSpeed);
};

int Car::speed(int maxSpeed) {
  return maxSpeed;
}

int main() {
  Car myObj; // Create an object of Car
  cout << myObj.speed(200); // Call the method with an argument
  return 0;
}
```

**TO COMPILE YOUR PROGRAM: g++ filename.cpp -o output**


# Constructors
**constructor**: a special method that is automatically called when an object of a class is created. 

**rules to know about constructors**
- must have the same name as the class
- no return type
- declared public
- automatically called when object is create

```C++ 
class MyClass {     // The class
  public:           // Access specifier
    MyClass() {     // Constructor
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;    // Create an object of MyClass (this will call the constructor)
  return 0;
}
```

## constructor with parameters

```C++ 
class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z) { // Constructor with parameters
      brand = x;
      model = y;
      year = z;
    }
};

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}
```

## constructor defined outside of class
```C++ 
class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z); // Constructor declaration
};

// Constructor definition outside the class
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}
```

# destructor
we need a destructor to desctoy objects of a class. a destructor is a method that has the same name as the class and is followed by a tilde.  

it is responsible for deallocating memory that an object uses. if we do not implement a destructor, the compiler will automatically create one. it is okay to rely on this destructor when we do not use dynamically allocated memory.  

when we use dynamically allocated heap memory, we must use a destructor. when we call delete on an object, we must include a destructor as part of the execution of delete. 

```C++ 
class Person {
    string name;
    public:
        Person(string n) : name(n) {
            cout << "Person " << name << " created\n";
        }
        
        ~Person() {  // Destructor called during delete
            cout << "Person " << name << " destroyed\n";
        }
};

// Usage
Person* p = new Person("Alice");
delete p;  // Prints: "Person Alice destroyed"
p = nullptr;  // Prevent accidental reuse
```

# C++ Access Specifiers
## access specifiers
**mark specifiers** cntrol how the members of a class can be accessed. they help protect data and organize code, so that only the right parts can be seen or changed.  

## using access specifiers
**here are 3 access specifiers**
- public: can be accessed from outside of class
- private: can only be accessed from inside of class
- protected: can be accessed from inside or inherited classes
