# Chapter 9: Notation

Notation is the way we express things.

It could be a natural language, a programming language or a DSL.
This chapter talks about the importancy for choosing the right "notation" for your problem.

## 9.1 Formatting Data

The way we format the data is dependent on notation, so choosing the right notation is important for solving the problem efficiently.

The format specifiers for the `printf` function in C are notation themselves and they give us an easy way to express intention (like print a char, print a number, print a number with 2 decimal points, etc.)

### Exercise 9-1

Modify pack and unpack to transmit signed values correctly, even between machines with different sizes for short and long. How should you modify the format strings to specify a signed data item? How can you test the code to check, for example, that it correctly transfers a -1 from a computer with 32-bit longs to one with 64-bit longs?

### Exercise 9-2

Extend pack and unpack to handle strings; one possibility is to include the length of the string in the format string. Extend them to handle repeated items with a count. How does this interact with the encoding of strings?

### Exercise 9-3

The table of function pointers in the C program above is at the heart of C++'s virtual function mechanism. Rewrite pack and unpack and receive in C++ to take advantage of this notational convenience.

### Exercise 9-4

Write a command-line version of printf that prints its second and subsequent arguments in the format given by its first argument. Some shells already provide this as a built-in.

### Exercise 9-5

Write a function that implements the format specifications found in spreadsheet programs or in Java's DecimalFormat class, which display numbers according to patterns that indicate mandatory and optional digits, location of decimal points and commas, and so on.
To illustrate, the format

```text
##,##0.00
```

specifies a number with two decimal places, at least one digit to the left of the decimal point, a comma after the thousands digit, and blank-filling up to the ten-thousands place.
It would represent 12345.67 as 12, 345.67 and .4 as \_\_\_\_0.40 (using underscores to stand for blanks).
For a full specification, look at the definition of Decimal Format or a spreadsheet program.

## 9.2 Regular Expressions

Regular Expressions are another powerful notation that allows us to express patterns of text that we want to match.

### Exercise 9-6

How does the performance of match compare to strstr when searching for plain text?

### Exercise 9-7

Write a non-recursive version of matchhere and compare its performance to the recursive version.

### Exercise 9-8

Add some options to grep. Popular ones include -v to invert the sense of the match, -i to do case-insensitive matching of alphabetics, and -n to include line numbers in the output. How should the line numbers be printed? Should they be printed on the same line as the matching text? "

### Exercise 9-9

Add the + (one or more) and ? (zero or one) operators to match. The pattern a+bb? matches one or more a's followed by one or two b's.

### Exercise 9-10

The current implementation of match turns off the special meaning of ^ and $ if they don't begin or end the expression, and of \* if it doesn't immediately follow a literal character or a period. A more conventional design is to quote a metacharacter by preceding it with a backslash. Fix match to handle backslashes this
way.

### Exercise 9-11

Add character classes to match. Character classes specify a match for any one of the characters in the brackets. They can be made more convenient by adding ranges, for example [a-z] to match any lower-case letter, and inverting the sense, for example [^0-9] to match any character except a digit. • Exercise 9-12. Change match to use the leftmost-longest version of matchstar, and modify it to return the character positions of the beginning and end of the matched text. Use that to build a program gres that is like grep but prints every input line after substituting new text for text that matches the pattern, as in % gres 'homoiousian' 'homoousian' mission.stmt

## 9.3 Programmable Tools

Combining notations and programming tools we can create other tools and workflows that can do specialised jobs for us.

## 9.4 Interpreters, Compilers and Virtual Machines

The notation of a machine is the machine language.
This means that whatever notation we choose to write our program we would need to transform it into machine language, before the computer can execute it.

That can happen in few ways:

- via a compiler - a tool that compiles our program, e.g. turning it into an executable
- via an interpreter - a tool that interprets our program line-by-line
- via a virtual machine - an intermediary level between the machine and our code that executes our program

All of the approaches have pros and cons which we need to consider between picking the one appropriate for our job.

Usually, compiled code is faster that interpreted one, but compilation takes time, and a compiled program runs only on the CPU architecture and OS for which it is compiled.
If we want to run it on another CPU/OS we need to recompile it.

Interpreters allows us to run the same code on every machine, but it can be slower that compilation.

Virtual machine (like the Java Virtual Machine) are a good middle-ground between the two, but they add additional overhead to the system.

## 9.5 Programs that Write Programs

We can write programs that write programs (this is actually what compilers are).

Or we can create our DSL and write a program that write code based on instructions written in this DSL.

### Exercise 9-15

One of the old chestnuts of computing is to write a program that when executed will reproduce itself exactly, in source form.
This is a neat special case of a program that writes a program.
Give it a try in some of your favorite languages.

## 9.6 Using Macros to Generate Code

We need to be careful with overusing macros in C, but they can something be useful for generating code.

For example, this macro is a function that executed our code multiple times and prints the execution time.

```c
#define LOOP(CODE) {                  \
    t0 = clock();                     \
    for (i = 0; i < n; i++) { CODE; } \
    printf("%7d", clock() - t0);      \
}
```

and can be used like this:

```c
LOOP(f1 = f2)
LOOP(f1 = f2 + f3)
LOOP(f1 = f2 - f3)
```

### Exercise 9-16

Exercise 7-7 involved writing a program to measure the cost of various operations in C++.
Use the ideas of this section to create another version of the program.

### Exercise 9-17

Exercise 7-8 involved doing a cost model for Java, which has no macro capability. Solve the problem by writing another program, in whatever language (or languages) you choose, that writes the Java version and automates the timing runs.

## 9.7 Compilation on the Fly

Also called Just-In-Time (JIT).

This can be useful and fast, because it saves compilation time and compiles only the parts that is sure will run.
Also, it can produce compile-time optimizations like ommiting devision by zero checks (when sure that the divisor is not 0).

### Exercise 9-18

The on-the-fly compiler generates faster code if it can replace expressions that contain only constants, such as `max (3\*3, 4/2)`, by their value.
Once it has recognized such an expression, how should it compute its value?

### Exercise 9-19

How would you test an on-the-fly compiler?

## Supplementary Reading

- _The Unix Programming Environment_ by Brian Kernighan and Rob Pike
- _TEX: The Program_ by Don Knuth
- _A Retargetable C Compiler: Design and Implementation_ by Chris Fraser and David Hanson
- _The Java Virtual Machine Specification_ by Tim Lindholm and Frank Yellin
- _Communication of the ACM_
- _Mastering Regular Expressions_ by Jeffrey E.F. Friedl
- _Hardware/Software Tradeoffs for Bitmap Graphics on the Blit_ in _Software - Practice and Experience_ (magazine)
