## Chapter 3: Design and Implementation

### 3.1 The Markov Chain Algorithm
**Summary:** We are going to use the Markov Chain Algorithm to write a program that generates text, based on an input text.
The Markov Chain Algorithm can be summarised to the following steps:
```
set w1 and w2 to the first two words in the text
print w1 and w2
loop:
    randomly choose w3, one of the successors of w1 w2 in the text
    print w3
    replace w1 and w2 with w2 and w3
    repeat loop
```