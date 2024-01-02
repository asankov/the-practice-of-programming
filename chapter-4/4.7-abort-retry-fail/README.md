# Chapter 4: Interfaces

## Section 4.7 Abort, Retry, Fail?

**Summary:** Handling errors is an important part of building a library/writing a program.
Functions should have a way to signal to the consumer that something went wrong.
This could be done via the return value of the function, or an exception (is such are available in the language of choice).
A good rule of thumb is to catch errors at a low level, and handle them at a high one. This would mean
that libraries should not try to handle errors themselves, but rather return them to the consumer,
so that he can choose the best way to do that.
Also, exceptions should be used for really exceptional situations, and not for control flow.
