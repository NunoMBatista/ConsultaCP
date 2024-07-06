### Top Down

Given $N$ objects with weights $w_i$ and values $v_i$, what is the max value you can carry in a sack with $W$ weight capacity?

- In each sub-problem, having the $i$ th object selected, there are two options:

  - Put $i$ in the sack and solve the sub-problem for weight $W - w_i$ with the rest of the $i - 1$ objects.
  - Don't put $i$ in the bag and solve the sub-problem for weight $W$ with the rest of the $i - 1$ objects.
- Choose the maximum value between those two options.

### Bottom Up

$dp[i][x]$ is the maximum number of pages we can get for price at most x, only buying among the first i books.`

```c++
void solve() {
    int n, C; 
    cin >> n >> C; 
    vt<int> costs(n); read(costs);
    vt<int> values(n); read(values);

    vt<vt<int>> dp(n+1, vt<int>(C+1, 0));

    ll left;
    for(ll i = 1; i <= n; i++){
        for(ll x = 0; x <= C; x++){
            dp[i][x] = dp[i-1][x];

            left = x - costs[i-1];
            if(left >= 0){
                dp[i][x] = max(
                                dp[i-1][x], 
                                dp[i-1][left] + values[i-1]
                                );
            }
        }
    }

    cout << dp[n][C] << endl;
}

```
