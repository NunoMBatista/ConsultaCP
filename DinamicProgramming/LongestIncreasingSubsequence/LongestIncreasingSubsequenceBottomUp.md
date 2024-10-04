Given a sequence of integers $s_i$ in a sequence $S$ of length $N$ find out the size of the largest subsequence $SB$ of numbers such that $sb_i > sb_i-1, \forall i \in S $.

Extra: find the largest sequence itself, not just it's length.

To do that, we can iterate through the length of $S$ **``[for(k = 0; k < N; k++)``** and compute the length of the LIS ending at index $k$ which is 1 more than the LIS ending at the largest LIS ending at index $i$ before $k$ as long as $S[i] < S[k]$:

$LIS[k] = 1 + \max \\{ LIS[i] \ | \ i < k \land A[i] < A[k] \\}$

Extra: keep track of the previous indexes in an array $prevIndexTracker$:

`prevIndexTracker[i]` is defined as the first index such that $S[idx] < S[i]$ by iterating from $k$ to $0$ i.e.: `rforn(idx, k)`


```c++
ll maxBeforeK(vll &sequence, vll &LIS, ll k){
    ll out = 0;
    forn(i, k){
        if(sequence[i] < sequence[k] && LIS[i] > out){
            out = LIS[i];
        }
    }
    return out;
}

ll setPrevIndex(vll &sequence, ll k){
    rforn(idx, k){
        if(sequence[idx] < sequence[k]){
            return idx;
        }
    }
    return -1;
}

ll DP (vll &sequence, ll n, vll &prevIndexTracker, vll &LIS){
    forn(k, n){
        LIS[k] = 1 + maxBeforeK(sequence, LIS, k);
        prevIndexTracker[k] = setPrevIndex(sequence, k);
    } 
    return *max_element(all(LIS));
}

void solve(){
    ll n = 7; // Sequence's size
    vll sequence = {5, 2, 8, 6, 3, 6, 9, 5};
    vll prevIndexTracker(n, 0);
    vll LIS(n, 0);

    ll LIS_size = DP(sequence, n, prevIndexTracker, LIS);
    cout << LIS_size << endl;

    ll max_index = distance(LIS.begin(), max_element(all(LIS))); // Index of the element at the end of the longest increasing subsequence  
   
    vll LongestIncreasingSubsequence(LIS_size); 
    rforn(idx, LIS_size-1){
        LongestIncreasingSubsequence[idx] = sequence[max_index];
        max_index = prevIndexTracker[max_index];
    }
  
    for(auto i: LongestIncreasingSubsequence){
        cout << i << " "; 
    }
    cout << endl; 
}
```
