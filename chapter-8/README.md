# Chapter 8: Portability

Portability is when our program can run in different environments.

This is desired, because we never know how and where our program is going to be run.

This chapter describes a few important things to consider when thinking about portability.

## 8.1 Language

Most languages (like C and C++) define a standard.
If we comply with that standard, we can expect that our program will be able to run in many places, be complied by different compilers, etc.

However, that is not always true.
Sometimes the standards are ambigious, or just not respected by the compilers.

For example, the ANSI C standard does not define the actual size of the datatypes, so we should not assume that a char will always be 8 bits.

## 8.2 Headers and Libraries

Headers and Libraries are an extension of the programming languages.

When using a language, we can assume that its standard language will be always available, but there might be rare cases where that is not true.
In these cases, it's better to make this a problem of our consumers, instead of putting huge effort to mitigate this on our side.

In the header files we can include directives to instruct the environment when to include some code and when not, but we should not overcomplicate this as it can become unmaintainable.

## 8.3 Program Organization

This chapter discusses different approaches to avoid `#ifdef`-hell, e.g. too many environment conditional statements in header files.

Approaches include things like using only features available on all systems **(intersection)**, or using all features available on any platform **(union)** and having complex installation logic/headers that include different pieces of code based on the environment.

### Exercise 8-1

Investigate how your compiler handles code contained within a conditional block like

```c
const int DEBUG = 0;
/* or enum { DEBUG = 0 }; */
/* or final boolean DEBUG = false; */

if (DEBUG) {
    // some code
}
```

Under what circumstances does it check syntax?
When does it generate code?
If you have access to more than one compiler, how do the results compare?

## 8.4 Isolation

A good way to organize our programs is to have environment-specific code in different files, e.g. (`unix.c`, `windows.c`, `mac.c`, etc.) and a central place where we control the inclusion of these files based on environment properties.

We can define an interface that will be used by our code, and depending on the system we can include the appropriate file that implements this interface for the given system.

## 8.5 Data Exchange

Text is a good medium for data exchange, because it's portable.

However, even with text there are sometimes portability issues, like encoding or different line-endings (LF vs CRLF).

### Exercise 8-2

Write a program to remove spurious carriage returns from a file.
Write a second program to add them by replacing each newline with a carriage return and newline.
How would you test these programs?

## 8.6 Byte Order

Sometimes we want to use binary data.

A big issue that comes up with binary data is the way different machine represent byte-sized data.

Some use big-endian and some use little-endian.

For example, this order of bytes that represents a 4-bytes integer:

| 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 11  | 22  | 33  | 44  |

is interpreted as `0x11223344` on a big-endian machine, and as `0x44332211` on a little-endian machine.

To see byte order in action, try this program:

```c
/* byte order: display bytes of a long */
int main(void) {
    unsigned long x;
    unsigned char *p;
    int i;

    /* 11 22 33 44 => big-endian */
    /* 44 33 22 11 => little-endian */
    /* x = 0x1122334455667788UL for 64-bit long */

    x = 0x11223344UL;
    p = (unsigned char *) &x;
    for (i = 0; i < sizeof(long); i++)
        printf("%x ", *p++);
    printf("\n");
    return 0;
}
```

On a 32-bit big-endian machine the output is:

```text
11 22 33 44
```

but on a little-endian machine it is:

```text
44 33 22 11
```

and on the PDP-11 (a vintage 16-bit machine still used in embedded systems) it is:

```text
22 11 44 33
```

This problem can be mitigated if:

- the two-sized between which data is exchange explicitly agree on the order of the bytes transmitted
- or we use a fixed byte order for the data exchange (this requires to transmit the data byte to byte, which may be slow and expensive)

Higher-level languages like Java don't have this problem, because they hide the byte-order completely.

## 8.7 Portability and Upgrade

One of the issues of portability is when we upgrade the software - we might introduce a feature that is not portable and does not work on all supported systems.

Another issue is **backwards-compatibility** - we need to make sure that the new changes we are adding do not break the existing use-cases of our program.

## 8.8 Internationalization

A program can be used by many people, using many language and data formats.
We should not assume a given encoding (for example, ASCII) or a given date format (for example, MM/DD/YYYY).

The Unicode character sets tries to mitigate this problem by supporting all languages in a single character set.
However, Unicode uses 16 bits per character, which is more than a byte.
Hence, we have the little-endian/big-endian problem again.
This is mitigated by encodings like UTF-8, which is also backwards-compatible with ASCII (because it uses the same 8-bits for the same ASCII characters).

## 8.9 Summary

Writing portable code is a good thing to strive for, but it is not always easy to do so.

There are two approaches to portable code - **union** and **intersection**.
**Union** is using all available features on each platforms by using things like conditional compilations.
**Intersection** is using only features available on ALL platform, and extracting all platform-specific code in separate files.

In the long run, the benfits of the intersection approach outweight the drawbacks.

## Supplementary Reading

- The C Programming Language by Brian Kernighan and Dennis Ritchie
- C: A Reference Manual by Sam Harbison and Guy Steele
- The Java Language Specification by James Gosling, Bill Joy and Guy Steele
- Advanced Programming in Unix Environment by Rich Stevens
- "On holy wars and a plea for peace" by Danny Cohen (article)
