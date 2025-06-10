# general notes from week 1
- all variables must be declared before they can be executed
    - a declaration consists of a type name and the variable

            int lower, upper, step; 

- the range of data types (i.e., int or float) vary depending on the computer you are using
- assignment statment sets the variables to their initial values.
- proper indentation is important -- it could determine the logical structure of your program. also, it makes your code easy to read. 
- the function printf expects a declaration of a type name like '%d' for integers in its first argument. the syntax is as follows:
        printf(format string [, input list']); 
where format string specifies the text to output, which includes a character string and format specifier that usually begins with %. the format specifier are to be replaced by text representing the values of the second argument

**variable declaration:** 
        data_type variable_name = initialization value;
where the data type dictates the amt of memory assigned to the variable, the kind of value that can be stored and the range of possible values that can be stored in this variable<br>
the value of a variable can change but its data type cannot

*we cannot hard code values -- we must either write them as constants or ask the user for the values through a prompt* 

**function call:** 
- arguments: <mark>the values are passed to a function when we call the function<mark>, which are usually placed within the ()

**width specification in printf**

        %d decimal integer
        %6d decimal integer, at least 6 characters wide
        %f floating point
        %f 6f floating point, at least 6 characters wide
        %.2f floating point, 2 characters after decimal point
        %6.2f floating point, at least 6 wide and 2 after decimal point

----
