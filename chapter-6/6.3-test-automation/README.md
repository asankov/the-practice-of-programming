# Chapter 6: Testing

## Section 6.3 Test Automation
**Summary**: Executing tests manually is a tedious job.
That's why we need automation - tests that run programatically and check our program for errors.
Automated tests should be easy to run. The easier they are to run, the more often you will run them.
### Automate regression testing
Often, when fixing a bug, we test whether the bug has been fixed, but not whether we have not broken something else.
The most popular type of testing is regression testing - whether all functionalities in the new version work as
they have worked in the old version.

When running such test suite we assume the old version worked correctly. This is not always the case, hence we need to
verify that the test suite is right often.

A good practice is that tests produce output only when they are failing and are otherwise silent.
This, however, is not true every time, so we must apply it with caution.
### Create self-contained tests
The best tests know their own input and output without depending on something externally.

It is even possible to create our own DSL (Domain Specific Language) that describes tests.

For example this is such language for testing `awk` programs:
```awk
try {if ($1 == 1) print "yes"; else print "no"}
1     yes
1.0   yes
1E0   yes
0.1E1 yes
10E-1 yes
01    yes
+1    yes
10E-2 no
10    no
```

It runs what is after `try` with the input from the first column and expects the output of the second column.

When new functionality is added new tests cases should be added as well. Test cases should not be deleted. If a bug is found, first a test case that fails should be written to reproduce the bug, and then the bug should be fixed. From then on, we will know that this bug would not occurr again.

### Exercise 6-5
Design a test suite for `printf`, using as many mechanical aids as possible.
