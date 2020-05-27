## Chapter 5: Debugging

### Section 5.2 Good Clues, Easy Bugs
**Summary:** Solving bugs is like a murder mystery, where you are also the killer.
Many bugs are easy to solve, if you know where to look for the right clues to their root cause.
Such clues are:
- Look for familiar patterns - look for familiar patterns of code, wher you've already made the same mistake
- Examine the most recent changes - compare the program with the previous version. If you can't reproduce the problem in the older version, then it was introduces recently and you only need to look at your latest changes.
- Don't make the same mistake twice - when you've fixed a bug, think of whether there is a place in which you may have made the same mistake. If yes, go there and fix it
- Debug it now, not later - when you encounter a problem, debug it sooner, rather than later
- Get a stack trace - a good feature of debuggers is to show you the stack trace. All the function call that were made before the error occurred.
- Read before typing - resist the urge to start changing stuff in the code and see if the problem goes away. Instead, take a good look at the code, print it if you must, or take a break from it. Doing nany of those things has a better change of resolving the problem that changing random stuff.
- Explain your code to someone else - basically rubber-duck debugging

