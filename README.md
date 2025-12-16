Custom String Library

Log:

We're building a custom string library that some basic functionalities such as:
compare strings, get lenght, add to string, alter string, and more.

We're working with Opaque Structs and abstraction for this project. A basic struct in C would allow any user 
to alter the data members in our string struct. So instead, we will be creating a header file 
where our struct lives as well as the some function declarations. Separately in a .c file, we will
define our struct and our functions which will be inaccessible for users. 