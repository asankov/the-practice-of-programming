## Chapter 3: Design and Implementation

### Section 3.5 Java
**Summary:** Let's rewrite these stuff in [Java](Markov.java)!

**BONUS:** Refactor the Java code to use up-to-data structures and practices:
- Generics - `Map<Prefix, Vector<String>>` instead of `Hashtable`
- Remove use of deprecated constructor of `StreamTokenizer`
- Static constructor, instead of constructors with fields that differ from the fields of the class

Changes applied in [this commit](https://github.com/asankov/the-practice-of-programming/commit/793994dae973f3d4d9a14224fb511f9d6fe9de82).

#### Exercise 3-4
Revise the Java version of `markov` to use an array instead of a `Vector` for the prefix in the `State` class.

*Answer:* An array makes more sense than `Vector`, because the size is fixed and known when the object is instantiated.
Therefore, we don't need data struct that can grow and shrink dinamically.

Changes applied in [this commit](https://github.com/asankov/the-practice-of-programming/commit/a1530955650425780da796e8d04a42ceacdf275c).