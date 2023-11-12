Verificar se um grafo é [[Bipartite Matching|bipartido]].

O objetivo é colorir cada vértice com $0$ e $1$, alternadamente, caso duas cores iguais estejam seguidas, sabe-se que o grafo não é bipartido.

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
        cout << "Sim\n";
    else
        cout << "Não\n";
  
    return 0;
}
```

> <font color="#00b050">STDIN:</font> [[Bipartite Graph Input]]
> 7
> 1 5
> 2 5
> 2 6
> 3 6
> 3 7
> 4 5 
> 4 7
> 1

> <font color="#00b050">STDOUT:</font>
> Sim
