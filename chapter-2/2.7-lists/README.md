## Chapter 2: Algorithms and Data Structures

### 2.7 Lists

#### Exercise 2-7
Implement some of the other list operations: copy, merge, split, insert before of after specific item.
How do the two insertion operations differ in difficulty? How much can you use the routines we've written,
and how much must you create yourself?

*Answer:* The solution can be found in [`chapter-2/2.7-lists/lists.c`](lists.c).
- Copying - the `copy` function. That is simply straight forward as it initializes a new list and start adding
copies of the element of the old list to the new one. For the purpose we can reuse the `newitem` function,
which create a new element.
- Merge - the `merge` function. In this we reuse `copy` to make copies of both lists and then just add them
together via the `addend` function. Neat.
- Insert before - the `insert_before` function. This one is a bit trickier, because there are 2 cases:
    - when the element we want to insert before is the first one - in this case, we make a copy to the original list,
    point the `next` field of the new element to this copy, and then point the original list pointer to the pointer of the new element.
    - when the element we want to insert before is not the first one - in this case we point the `next` field of the new element to the `next` field of previous element of the list (of which we hold a copy), and then point the previous element of the list, of the new element. In both cases we don't reuse any of the existing functionality.
- Insert after - the `insert_after` function. In this we iterate over the elements of the passed list, until we find the matching one.
The make this point to the next from the original list, and the previous one points to the new element to be inserted.
In this function we don't reuse any of the other ones, because it's just pointer changes and comparisons.

#### Exercise 2-8
Write recursive and iterative versions of `reverse`, which reverses a list. 
Do not create new list items; re-use the existing ones.

*Answer:* The solution can be found in [`chapter-2/2.7-lists/reverse.c`](reverse.c)

#### Exercise 2-9
Write a generic List type for C. The easiest way is to have each list item hold a `void*` that points to the data.
Do the same for C++ by defining a template and for Java by defining a class that holds lists of type Object.
What are the strenght and weaknesses of the various languages for this job?

*Answer:* The solutions can be found at [`generic_lists`](generic_lists).
- The C solution is really weird, because in order to achieve generic list, we must use `void*`.
That means that the type-checking responsibility is switched from the compiler, to the consumer of the list.
Also, while trying it off it produces some warning of the sort `[-Wincompatible-pointer-types]`.
So it should be compiled with flags to ignore this warning. All in all, I think that it is better if the
consumers would implement their own list, instead of using this generic one.
- C++ solution - TODO
- Java solution - in Java this is pretty much implemented with `List<T>` and all of its implementations,
so I'd rather not spend time reimplementing those or implementing wrappers around them.