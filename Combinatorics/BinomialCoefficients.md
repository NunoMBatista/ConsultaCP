Binomial coefficients ${n \choose k}$ represent the number of ways to select a set of $k$ elements from $n$ distinct elements **(without order and without repetition)**. The analytical formula is as follows:

$$
{n \choose k} = \frac{n!}{k!(n-k)!}
$$

**Naive implementation (prone to overflowing)**

```cpp
int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}
```

**Improved implementation**

```cpp
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}
```

Sometimes, it's actually better to precompute the factorials in order to calculate the binomial compute the binomial coefficient in $O(1)$.

If **repetition of elements** is allowed, we can just calculate ${n+k-1 \choose k}$, i.e.

$$
\frac{(n+k-1)!}{k!(n-1)!}
$$

If the order matters, we want to calculate the permutations of $n$ elements **(without repetition)**, taking $k$ at a time, i.e.

$$
\frac{n!}{(n-k)!}
$$

Or just $n^k$ **(with repetition)**.
