# Chapter 5: Debugging

## Section 5.3: No Clues, Hard Bugs

**Summary:** If you have no idea why a bug is happenning, life gets tough.
This chapter lists some techniques for making your life easier by showing you how to make your bugs discovarable.
Such clues are:

- **Make the bug reproducible** - make it so that the bug appears every time. Research the input and conditions that trigger the bug and use them
  when debugging.
- **Divide and conquer** - when you find that input, bottle it down to the smallest possible input that triggers the bug.
  See what part of your program interacts with this input and focus on that. Also, focus on the latest changes of the program.
- **Study the numerology of failures** - sometimes a pattern in numbers can be the source of the bug. Numbers like 1024, 2048, etc.
- **Display output to localize your search** - if you are not sure what is happening where, or which part of the code you're reaching and which not,
  it's ok to put debug messages like: `got here` or `can't get here` and scan the output of the program for them.
  Also, be consistent in the way you print values like pointers and learn their format to get maximum information from this output.
- **Write self-checking code** - write code that checks some conditions of your program and does something based on that, e.g. print something, exit, etc. Also, find a way to keep this code as part of your program for the next time such a bug occurs. You may comment out this code, or hide it under a debugging flag if you don't want to be executed every time.
- **Write a log file** - stream your output to a log file, and later search there for patterns, reasons for failure, etc. Also, be sure to flush your buffers on exit, so that no output is lost.
- **Draw a picture** - visualize your data in a picture, graphic, chart to get a visual output of your program.
- **Use tools** - use all the tools at your disposal to the maximum. Tools like `grep`, `diff`, VCS, shell scripts, etc.
  Also, write small programs to validate your assumptions about the programming language you use.
- **Keep records** - during long debugging sessions take notes to keep track of what you have tried. This way knowledge is saved for the time a similar bug appears. Also, you will be sure what you have tried and what not.
