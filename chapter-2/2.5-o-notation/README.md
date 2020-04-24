## Chapter 2: Algorithms and Data structures

### 2.5. The O-Notation

#### Exercise 2.3
What are some input sequences that might cause a quicksort implementation to display worst-case behaviour?
Try to find some that provoke the library version into running slowly. 
Automate the process so that you can specify and perform a large number of experiments easily.

*Answer:* My internet search found that bad input for quick sort can be:
- already sorted arrays
- arrays with all values equal
- arrays with all values equal, but one
- arrays sorted in reverse order

Trying this in practice in code proved unresultful, probably because of the small input data.

Doing this with mine, slighly modified algorithm that allowed me to count the number of iterations showed that indeed the bigger difference encoutered when comparing the same algorithm with smaller and bigger input was that when this input wah in the last 3 categories(arrays with all values equal, arrays with all values equal but one, arrays sorted in reverse order)