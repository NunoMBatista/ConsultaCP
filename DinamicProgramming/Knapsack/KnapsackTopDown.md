Given $N$ objects with weights $w_i$ and values $v_i$, what is the max value you can carry in a sack with $W$ weight capacity?

- In each sub-problem, having the $i$ th object selected, there are two options:
  - Put $i$ in the sack and solve the sub-problem for weight $W - w_i$ with the rest of the $i - 1$ objects.
  - Don't put $i$ in the bag and solve the sub-problem for weight $W$ with the rest of the $i - 1$ objects.

- Choose the maximum value between those two options.


```c++

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> items;
vector<vector<int>> DP (1001, vector<int> (1001, -1));

int knap (int idx, int W){
    if (idx == 0) //acaba a recursão
        return 0;

    if (DP[idx][W] >= 0)
        return DP[idx][W]; //se uma resposto já foi memoized, ela é usada

    if (items[idx].second > W){
        DP[idx][W] = knap(idx-1, W); //quando o peso do item passa a ser maior que a capacidade do saco, o index do item muda
        return DP[idx][W];
    }
    else
        DP[idx][W] = max(knap(idx-1, W), items[idx].first + knap(idx-1, W - items[idx].second)); //verificar se a solução mais valiosa é seguindo a árvore recursiva com o idx
    return DP[idx][W];
}

int main (void){
    int n, W, v, w;
    cin >> n >> W;

    for(int i = 0; i < n; i++){
        cin >> v >> w;
        items.push_back({v, w});
    }
    cout << knap(n, W) << endl;

    return 0;
}
```
