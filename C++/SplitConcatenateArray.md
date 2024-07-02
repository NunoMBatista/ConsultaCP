$a := x + y$, swap x and y to obtain $sa = y + x$, for example if $x = [1, 2]$ and $y = [3, 4]$, then $a = [1, 2, 3, 4]$ and $sa = [3, 4, 1, 2]$:

```c++
vector<int> a = {1, 2, 3, 4};

vector<int> x(a.begin(), a.begin() + 2);
vector<int> y(a.begin() + 2, a.end());

vector<int> sa = y;
sa.insert(sa.end(), x.begin(), x.end());
```
