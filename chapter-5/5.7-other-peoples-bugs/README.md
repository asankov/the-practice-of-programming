# Chapter 5: Debugging

## Section 5.7 Other People's Bugs
**Summary:** When working on software build by other people (which is most often the case), it is inevitable to have to fix bugs, introduced by other people.
In that case, every lessons introduced so far apply, among other things.

It is important to understand the structure of the program and how things work. Tools like `grep` and IDEs help with this.
It is also important to understand the history of the code. Places where changes were made frequently are often a sign that the code there is poorly understood or the requirements have changed ofter, both of which could be a cause for buggy code.

When tracking errors in a program you don't have the source for it's important to remember few things:
- make sure you are testing with the latest version, because the bug you have found may be fixed in a newer version
- find an easy way to reproduce it, so that you could point that out to the maintainers
- make sure that the problem is real, and that the program is indeed not meant to behave that way
