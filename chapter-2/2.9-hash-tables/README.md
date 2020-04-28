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