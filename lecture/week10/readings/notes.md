# C++ OOP

- **OOP** = Object-Oriented Programming -> creating objs, which can hold data and functions that work on that data

## what are classes and objects? 
- <mark>class</mark> defines what an object should look like
- <mark>object</mark> is created based on that class
&nbsp;for example: FRUITS -> APPLE, BANANA + MANGO

## procedural vs. OOP
- **procedural**: writing functions that operate on data
- **OOP**: creating objects that contain <mark>both data and functions</mark>

===

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