Given an array $coins$ with $n$ elements, what's the minimum amount of coins whose sum is equal to $change$?

$dp[sub]$ caches the minimum ammount of coins needed to form $sub$.

$dp[0]  = 0$ is the base case.

Iterating through every sub from $1$ to $change$, we test every coin that fits in $sub$ and update $dp$ accordingly: $dp[sub] = \min \\{ dp[sub], sp[sub-coin] + 1 \\}$

```c++
ll min_coins(ll change, vll &coins){
    vll dp(change, INF); 
    dp[0] = 0; 

    forsn(sub, 1, change){
        for(auto coin: coins){
            if(coin <= sub){
                dp[cur] = min(dp[sub], dp[sub-coin] + 1);
            }
        }
    }
    return dp[change-1];
}

void solve(){
    vll coins = {5, 4, 1};
    ll change = 13; 
  
    cout << min_coins(change, coins) << endl;
}
```
