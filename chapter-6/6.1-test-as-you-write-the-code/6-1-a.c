#include <stdio.h>

int test(int in, int exp);
int factorial(int n);

int main()
{
    int res = 0;
    res += test(0, 1);
    res += test(-1, 0);
    res += test(1, 1);

    if (res != 0)
    {
        printf("❌ %d tests failed\n", res);
    }
    else
    {
        printf("✅ all tests passed\n");
    }

    return res;
}

int test(int in, int exp)
{
    int actual = factorial(in);
    if (actual != exp)
        return 1;
    return 0;
}

// factorial: we see that with faulty input, 0, -1, etc.
// we get multiple iterations before the value is returned
int factorial(int n)
{
    // return 0 for negative values of n
    if (n < 0)
    {
        return 0;
    }
    // return 1 for 0! and 1!
    if (n < 2)
    {
        return 1;
    }

    int fac = 1;
    while (n--)
    {
        printf("before fac *= n, fac = %d, n = %d\n", fac, n);
        fac *= n;
        printf("after fac *= n, fac = %d, n = %d\n", fac, n);
    }
    printf("return fac, fac = %d\n", fac);
    return fac;
}
