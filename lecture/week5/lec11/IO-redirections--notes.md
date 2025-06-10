**I/O redirections**
- it allows us to route the stdin + stdout away from the console and into a file
    e.g., ./hello > myfile.txt,  which creates a new file and writes the output from the program into this new file
    we can look into this file by using the command: cat myfile.txt

to take content of a text file:
    ./gb < grades.txt

to sort the items of a text file: 
    sort < beatles.txt

to sort and write the output of a program:
    sort < beeatles.txt > sorted.txt