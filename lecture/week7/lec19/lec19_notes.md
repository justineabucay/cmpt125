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