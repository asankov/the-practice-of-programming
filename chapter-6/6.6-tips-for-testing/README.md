# Chapter 6: Testing

## Section 6.6 Tips for Testing

There are a lot of tricks that make the testing easier.

For example, if we are allocating array memory, we can allocate less for testing, instead of trying to produce large amounts of data for testing.

Have a way to reproduce random tests, e.g. store the seed.

Don't write new code until you've fixed all known bugs. The new code can be affected by the bugs.
