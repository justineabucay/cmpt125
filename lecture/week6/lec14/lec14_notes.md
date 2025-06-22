# main() function
**ways we can access test data into our program:**
1. user input through a prompt
2. hard-coding the value
3. passing the values through arguments
        
we can pass arguments through the terminal shell using the following command below:

        $ cp original copy

however, we must declare the main() function as the following: 

        int main(int argc, char* argv[]) {} // these arguments make it possible so that our rogram can accept any arguments

we know that argument passed through the main() function will aalways be stored as character arrays (i.e., strings). therefore, we need to convert strings to number data types using the functions below:

        if(argc != 3){...} // expects 3 arguments

        int intNum = aoit(argv[1]); // expects integer
        floar fltNum = atof(argv[2]); // expects float

we can execute the program like the following: ./ar 5 3.14<br>

**review: multi-source files** - makefile includes the following:  

1. create a object file for main() and header file
2. create a object file for all functions 
3. merge the two files above and add executable 

