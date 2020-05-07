## Chapter 3: Design and Implementation

### 3.2 Data Structure Alternatives
**Summary:** While choosing data structures for our program we need to take into account a few things:
- which structure fits naturally for the work that must be done
- how big of an input we are expecting
- what is the desired speed we want our program to run with

Taking all these things into account we have chosen to go with a hash table.
The prefix will be the key, and the suffix will be the value.
Each prefix is a fixed-size set of words (we have decided to go with 2).
Each suffix is a list of words.
For now we will represent the words as strings.