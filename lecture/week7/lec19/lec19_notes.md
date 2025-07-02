**function: assert** - checks if it is the condition passed as its parameters. if assert() fails or returns false, aborts the execution. 

incremental development
- implement a function one at a time, where the process inv. developing, testing and moving to the next function

**what are structs**
- grp tgt data of diff types to model real-world entities, such as addresses, student record + books

**struct w/ typedef**
- allows for new custom data type

        typedef struct {    // ysing typedef reduces typing and it is easier to read
            char title[100];
            char author[50];
            char subject[30];
            char isbn[20];
            // Additional fields...
        } Book_t;   


        struct Book {   // you must write 'struct' every time you create a new Book
            char title[100];
            char author[50];
            char subject[30];
            char isbn[20];
            // Additional fields...
        }; 

how to store multiple data:
- combine arrays w/ structs, such as the following: arrays of structs( Book_t books[ MAX_BOOKS ] )

basically, you can store any data regardless of data type as long as it is created as the same object:

        // functions using Call By Value Method
        #include <stdio.h>

        struct car {
            char name[30];
            int price;
        };

        void print_car_info(struct car c)
        {
            printf("Name : %s", c.name);
            printf("\nPrice : %d\n", c.price);
        }

        int main()
        {
            struct car c = { "Tata", 1021 };
            print_car_info(c);
            return 0;
        }

you can also return the entire structure like the following example:

        // C program to return a structure from a function
        #include <stdio.h>

        struct student {
            char name[20];
            int age;
            float marks;
        };

        // function to return a structure
        struct student get_student_data()
        {
            struct student s;

            printf("Enter name: ");
            scanf("%s", s.name);
            printf("Enter age: ");
            scanf("%d", &s.age);
            printf("Enter marks: ");
            scanf("%f", &s.marks);

            return s;
        }

        int main()
        {
            // structure variable s1 which has been assigned the
            // returned value of get_student_data
            struct student s1 = get_student_data();
            // displaying the information
            printf("Name: %s\n", s1.name);
            printf("Age: %d\n", s1.age);
            printf("Marks: %.1f\n", s1.marks);

            return 0;
        }