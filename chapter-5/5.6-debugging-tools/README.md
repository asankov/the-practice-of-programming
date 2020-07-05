# Chapter 5: Debugging

## Section 5.6 Debugging Tools
**Summary:** There are more debugging tools than a debugger.
One such would be a program that reads a compiled program and output its meaningful content.
This way if we are getting an error message, but don't know where that is comming from we can do:
```
$ strings *.exe *.dll | grep 'some error message'
```
For the implementation, see [`strings.c`](strings.c)
