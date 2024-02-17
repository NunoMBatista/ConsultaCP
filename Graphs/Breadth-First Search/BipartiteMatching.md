Check if a given graph is bipartite.

The core idea is to color each vertex with 0s and 1s alternately, If two adjacent vertices have the same color, the graph is not bipartite.

```c++
vv graph(1001);
vi color (1001, -1);

bool bipartite(int start){
    int cur;
    queue<int> Q;
    color[start] = 1;
    Q.push(start);

    while(!Q.empty()){
        cur = Q.front(); Q.pop();

        for(auto u: graph[cur]){
            if(color[u] == -1){
                color[u] = 1 - color[cur];
                Q.push(u);
            }
            else if(color[u] == color[cur])
                return false;
        }
    }
    return true;
}

int main(){
    int m, u, v, start;
    cin >> m;
    forn(i, m){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> start;

    if (bipartite(start) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
  
    return 0;
}
```

> STDIN:
> 7
> 1 5
> 2 5
> 2 6
> 3 6
> 3 7
> 4 5
> 4 7
> 1

> STDOUT:
> Yes
