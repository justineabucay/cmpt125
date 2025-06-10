# good programming style: a guideline

1. **descriptive naming**: the names of the file, variables, classes + functions should describe what they do

2. **user interaction**: when prompting the user, we must give them clear instructions. also, the output must always be labelled clearly

3. **code**: avoid repeated code fragments and instead, place them into a function/method that we can call. also, we should minimize the use of break + continue in if statements and loops, as it does not allow us to complete the conditions properly

4. **functions + methods**: must only have one purpose -- that is, one action

5. **boolean conditions**: avoid using the following boolean expressions:

        while(1)<br>
        while(!0)<br>
        while(true)<br>
        while(!false)<br>

instead, we can initialize a variable to hold true/false/0/1 and use them as flags

