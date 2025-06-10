
**creating make filess**
the reason why we need to use makefiles because we might have to compile multiple projects at the same time. however, it is possible to write all the files needed to compile in the terminal. a make files contains a set of commands that keep our files organized.

what it includes: 
- main.c, where it keeps all the function calls and must include the header file 
-funcs.c, where this file contains any relevant functions (such as larger and smaller) and must also include the header file
-funcs.h is the header file, where it includes all the function declaration 
- make file contains all our commands

to clean: 
    rm -f fc *.o 
where -f stands for "force", meaning rm will forcibly delete the file named fc and all files ending in .o without any prompts

-Wall: stands for "warning all" and enables warning messages when compiling the program 

**compiling multi-source files**
- #include:  copies the contents of the indicated files into the source file
    if we do not add the indicated file at the top of main.c, we will receive a warning, complaining that the functions are not properly declared


**header files**
- header files contains function declarations from a header file we have made or from libraries linked to our program, like the main library. 
- they sometimes declare global variables.