# Chapter 1: Style

## 1.3 Consistency and Idioms

### Exercise 1-7

Rewrite these C/C++ excerpts more clearly:

```c
if (istty(stdin)) ;
else if (istty(stdout)) ;
    else if (istty(stderr)) ;
        else return(0);
```

```c
if (retval != SUCCESS)
{
    return (retval);
}
/* All went well! */
return SUCCESS;
```

```c
for (k = 0; k++ < 5; x += dx)
    scanf("%lf", &dx);
```

_Answer:_

```c
if (istty(stdin)) {}
else if (istty(stdout)) {}
else if (istty(stderr)) {}
else
    return (0);
```

Here, I just added parantheses around the empty bodies of the if conditions and corrected the indentation. This should be enough to easy readability.

```c
return retval;
```

Here, the return value is always `retval`, so there is no sense in checking it, since no other action is executed anyway.

```c
for (k = 0; k < 5; k++)
    scanf("%lf", &dx);
    x += dx;
```

Here, I moved the incrementation of `k` to the last part of the `for` loop definition, as this is the idiomatic choice.
Moreove, I moved `x += dx` into the body of the for loop, since this way is even clearer where `dx` is coming from and what happens with `x`. Also, now the `for` loop looks like the standart `for` that a seasoned programmer would recognise at a glance.

### Exercise 1-8

Identify the errors in this Java fragment and repair it by rewriting with an idiomatic loop.

```java
int count = 0;
while (count < total) {
    count++;
    if (this.getName(count) == nametable.userName()) {
        return (true);
    }
}
```

_Answer:_

```java
for (int count = 0; count < total; count++) {
    if (this.getName(count) == nametable.userName()) {
        return (true);
    }
}
```

Not much to explain here. Making the loop idiomatic makes the code much easier to read and understand.
