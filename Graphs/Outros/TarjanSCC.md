Tarjan's SCC algorithm finds sets of nodes in a graph that are all reacheable from every node in the set.

Core idea: 

&nbsp;&nbsp;&nbsp;&nbsp;1 - Start DFS, when a node is visited for the first time, add it to a stack, mark it as visited, and assign it an id and a low-link value, the low-link value of a node is the value of the lowest id reachable from that node.

&nbsp;&nbsp;&nbsp;&nbsp;2 - On the DFS callback, if the searched node is on the stack, assign $low\_link[node] = min\{low\_link[adjacent], low-link[current]\}$.

&nbsp;&nbsp;&nbsp;&nbsp;3 - After visiting all neighbors, if the current node is the root of a SCC, i.e. if $id[current] = low\_link[current]$, pop every node from the stack until reaching the current node. The popped nodes form the SCC.

```c++
vector<vector<ll>> graph;  
vector<vector<ll>> SCCs;
vector<bool> visited;
vector<ll> ids; 
vector<ll> low;
ll counter; 
stack<ll> S;
vector<bool> onStack;
ll id;

void dfs(ll cur){
    S.push(cur);
    onStack[cur] = true;
    ids[cur] = low[cur] = id;
    id++;

    for(auto adj: graph[cur]){
        if(ids[adj] == -1){
            dfs(adj);
        }
        // If statement after the DFS callback
        if(onStack[adj]){
            low[cur] = min(low[cur], low[adj]);
        }
    }

    // SCC root found
    ll top = -1;
    if(ids[cur] == low[cur]){
        vector<ll> newSCC;
        while(top != cur){
            top = S.top(); S.pop();
            onStack[top] = false;
            low[top] = ids[cur];
            newSCC.push_back(top);
        }
        SCCs.push_back(newSCC);
        counter++;
    }
}

void tarjan(){
    id = 1;
    counter = 0;
  
    for(ll i = 1; i <= n; ++i){
        if(ids[i] == -1){
            dfs(i);
        }
    }
  
}
```
