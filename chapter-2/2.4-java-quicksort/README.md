# Chapter 2: Algorithms and Data structures

## 2.4. A Java Quicksort

### Exercise 2.2

Our Java quicksort does a fair amount of type conversion as items are cast from their original type (like Integer) to Object and back again.
Experiment with a version of QuickSort.sort that uses the specific type being sorted, to estimate what
performance penalty is incurred by type conversions.

_Answer:_ Results from executing the following code were:

- ObjectQuickSorter took 5 ms
- GenericQuickSorter<Integer> took 13 ms
- IntegerQuickSorter took 3 ms

Therefore, the generic sorter is the slowest one and the type specific one (IntegerQuickSorter) is the quickest one.
The difference between IntegerQuickSorter and ObjectQuickSorter is much smaller that the difference between these two and GenericQuickSorter.

All implementations can be found at [`Main.java`](Main.java)
