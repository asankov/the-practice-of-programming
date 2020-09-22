## Chapter 1: Style

### 1.5 Magic Numbers
**Summary:** Magic numbers should be extracted into constants/enum to easy readability and to prevent having to change a lot of code if something changes (for example an array size).

### Exercise 1-10
How would you rewrite these definitions to minimize potential errors?
```c
#define FT2METER  0.3048
#define METER2FT  3.28084
#define MI2FT     5280.0
#define MI2KM     1.609344
#define SQMI2SQKM 2.589988
```
*Answer:*
```c
const long FT2METER = 0.3048;
const long METER2FT = 1/FT2METER;
const long MI2KM = 1.609344;
const long MI2FT = MI2KM * 1000 * METER2FT;
const long SQMI2SQKM = MI2KM * MI2KM;
```
The first option to look at when defining constants should be the `enum`. However, this won't work here, because in C/C++ enum values can only be integers.
The next option is `const`. This allows us to define only 2 of them and compute the other 3 based on these 2 values.
This computation is cheep, since it would be executed only once - at compile time.
This is safer than hardcoding all the values by hand.
Macros should not be used for constants, because according to the book, they may change the lexical structure of a program.