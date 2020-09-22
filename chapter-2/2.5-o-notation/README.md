## Chapter 2: Algorithms and Data structures

### 2.5. O-Notation

### Exercise 2.3
What are some input sequences that might cause a quicksort implementation to display worst-case behaviour?
Try to find some that provoke the library version into running slowly. 
Automate the process so that you can specify and perform a large number of experiments easily.

*Answer:* My internet search found that bad input for quick sort can be:
- already sorted arrays
- arrays with all values equal
- arrays with all values equal, but one
- arrays sorted in reverse order

Trying this in practice in code proved unresultful, probably because of the small input data.

Doing this with mine, slighly modified algorithm that allowed me to count the number of iterations showed 
that indeed the bigger difference encoutered when comparing the same algorithm with smaller and bigger input 
was that when this input wah in the last 3 categories(arrays with all values equal, arrays with all values 
equal but one, arrays sorted in reverse order)

The implentation can be found in [`quick_sort_worst_cases.c`](quick_sort_worst_cases.c).

### Exercise 2.4
Design and implement an algorithm that will sort an array of *n* integers as slowly as possible.
You have to play fair: the algorithm must make progress and eventually terminate, and the implementation
must not cheat with tricks like time-wasting loops. What is the complexity of your algorithm as a function of *n*?

*Answer:* For this I went with the classis Bubble sort. This is an algorith that takes an element of the 
array, compares it with all the other values in this array to find its place, and then does that for all of
the elements of the array. The complexity of this is *O(n^2)*, because adding one element, would mean *n* more operations.

Another one that could be even slower that this one, would be one that tries all possible combinations to see if an array is sorted.
The complexity of that would be *O(2^n)*, because adding an element, would mean twice as more operations.

The implementation can be found at [`slow_sort.c`](slow_sort.c)