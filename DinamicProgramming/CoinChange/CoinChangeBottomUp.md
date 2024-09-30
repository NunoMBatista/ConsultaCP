**MINIMUM AMMOUNT**

Given an array $coins$ with $n$ elements, what's the minimum amount of coins whose sum is equal to $change$?

$dp[sub]$ caches the minimum ammount of coins needed to form $sub$.

$dp[0]  = 0$ is the base case (we need 0 coins to get the change 0).

Iterating through every sub from $1$ to $change$, we test every coin that fits in $sub$ and update $dp$ accordingly: $dp[sub] = \min \\{ dp[sub], \space dp[sub-coin] + 1 \\}$

```c++
ll min_coins(ll change, vll &coins){
    vll dp(change + 1, INF); 
    dp[0] = 0; 

    forsn(sub, 1, change + 1){
        for(auto coin: coins){
            if(coin <= sub){
                dp[sub] = min(dp[sub], dp[sub-coin] + 1);
            }
        }
    }
    return dp[change];
}

void solve(){
    vll coins = {5, 4, 1};
    ll change = 13; 
  
    cout << min_coins(change, coins) << endl;
}
```

**HOW MANY WAYS (with order, 2+2+3 and 2+3+2 count as 2 different ways)**

Given an array $coins$ with $n$ elements, how many sets of coins are there whose sum is equal to $change$?

$dp[sub]$ caches the ammount of ways to form $sub$.

$dp[0]  = 1$ is the base case (there's only $1$ way to get the change $0$).

Iterating through every sub from $1$ to $change$, we test every coin that fits in $sub$ and update $dp$ accordingly: $dp[sub] = dp[sub] + dp[sub-coin]$.

```c++
ll coin_combs(ll change, vll &coins){
    vll dp(change + 1, 0); 
    dp[0] = 1; 

    forsn(sub, 1, change + 1){
        dp[sub] = 0;
        for(auto coin: coins){
            if(coin <= sub){
                dp[sub] = dp[sub] + dp[sub-coin];
            }
        }
    }
    return dp[change];
}

void solve(){
    vll coins = {5, 4, 1};
    ll change = 5; 
  
    cout << coin_combs(change, coins) << endl;
}
```

**HOW MANY WAYS (without order)**

Same as the with order version but the outer loop iterates through the coins and the inner loop iterates through the $sub$ values.

```c++

ll coin_combs(ll change, vt<ll> &coins){
    vt<ll> dp(change + 1, 0);
    dp[0] = 1;

    for(auto coin: coins){
        for(int sub = 1; sub <= change; sub++){
            if(coin <= sub){
                dp[sub] = dp[sub] + dp[sub-coin];
            }
        }
    }

    return dp[change];
}

void solve(){
    vll coins = {5, 4, 1};
    ll change = 5; 
  
    cout << coin_combs(change, coins) << endl;
}
```
