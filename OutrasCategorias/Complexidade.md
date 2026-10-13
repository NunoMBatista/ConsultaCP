# Complexity by N

C++ does about 10^8 simple operations per second (MIUP limits are 1-2 s).

```
N <= 10        O(n!)            all permutations, backtracking
N <= 20        O(2^n * n)       all subsets (bitmask), bitmask DP
N <= 40        O(2^(n/2))       meet in the middle
N <= 500       O(n^3)           Floyd-Warshall, interval DP
N <= 5000      O(n^2)           2D DP (LCS, edit distance), all pairs
N <= 10^6      O(n log n)       sort, set/map, Dijkstra, binary search
N <= 10^8      O(n)             one pass, prefix sums, sieve
N >  10^9      O(log n), O(1)   math formula, binary search, fast pow
Python is ~10x slower; with T test cases, multiply by T
```
