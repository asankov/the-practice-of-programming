## Chapter 2: Algorithms and Data Structures

### Section 2.9 Hash Tables

#### Exercise 2.14
Our hash function is an excellent general-purpose hash for strings.
Nonetheless, peculiar data might cause poor behaviour. Contruct a data set that causes
our hash function to perform badly. Is it easier to find a bad set for different values
of `NHASH`?

*Answer*: My experiment was to try out URL, since that was mentioned in the book as possible problematic input.
I tried with 8 URLs. In the beggining when `NHASH` was way bigger that the number of inputs (500 > 8), there
were no collisions. However, when I set `NHASH` to something small collisions started popping. 
For `NHASH=8` (the same number of inputs) there were 4 collisions. Even for `NHASH=16` (twice the number of inputs) there were 2 collisions, which was not good. So my guess is that input of that sort would be 
problematic for this algorigthm. And, of course, the smaller `NHASH` is, the bigger a possibility for collisions.

#### Exercise 2.15
Write a function to access the successive eleents of the hash table in sorted order.

*Skipping this one, because I am not sure what exactly should be done here.*

#### Exercise 2.16
Change `lookup` so that if the average list length becomes more than `x`, the array is grown automatically
by a factor of `y` and the hash table is rebuilt.

*Answer:* You can find the solution at [`lookup.c`](lookup.c). This one was tricky as there were some gotchas
around the resizing of the map. In the end I managed to do it in the following way:
- if the average length is bigger that the desired one, create an array of all the elements in the map
- set all of the elements of the map to NULL
- resize the map (`realloc`)
- recalculate the hash of all the elements in the array and insert them into the map
That are a lot of iterations, but I am not sure if I can come up with a more elegant solution.

#### Exercise 2.17
Design a hash function for storing the coordinates of points in 2-dimensions. How easily does your function
adapt to changes in the type of the coordinates, for example from integer to folating point or
from Cartesian to polar coordinates, or to changes from 2 to higher dimensions?

*Answer:* You can find the solution at [`coordinates.c`](coordinates.c).
The hash function for coordinates takes into account four things:
- the `x` part of the coordinates
- the `y` part of the coordinates
- the sum of `x` and `y`
- the absolute difference of `x` and `y`
These four are multiplied by four prime numbers and added together to compute the final hash.

I decided that having the four factors is more collision-save than just the `x` and `y`, because
this way if two combinations of `x` and `y` for which`(31 * x1) + (37 * y1) == (31 * x2) + (37 * y2)`
yield the same value, taking into account the sum and the difference would prevent them from having the same hash.

The current implementation does not care whether `x` or `y` are going to be `int`, `float`, `double` or something else. They can be anything that can be multiplied by `int`.

As for Cartesian to polar - if the coordinates are numbers, the hash function will deal with them just fine.

Finally, if we were to add a third point - `z`, then the `hash` function will have to be enhanced to take it into account as well.

