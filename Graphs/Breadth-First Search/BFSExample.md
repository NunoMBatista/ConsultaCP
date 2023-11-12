BFS searches a tree, starting from the root and exploring every node at the current depth before moving on to the next depth level by using a queue, hence, the name Breadth-First.
Complexity: $0(|V| + |A|)$. 


### Pseudo-Code
```
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as explored
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if _v_ is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as explored then
11                  label w as explored
12                  w.parent := v
13                  Q.enqueue(w)
```


## C++
```c++
vector<bool> visited(1001, false);
vv graph(1001);

void BFS (int root, int goal){
    int cur;
    queue<int> Q;
    visited[root] = true;
    cout << "visiting root\n";
    Q.push(root);

    while(!Q.empty()){
        cur = Q.front(); Q.pop();
        cout << "visiting node " << cur << endl; 

        if (cur == goal)
            return;

        for(auto w: graph[cur]){
            if(visited[w] == false){
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

int main(void){
    int m, u, v;
    cin >> m;  

    forn(i, m){
        cin >> u >> v;
        graph[u].push_back(v);
    }

    BFS(1, 17); 
    return 0;

}
```

> <font color="#00b050">STDIN:</font>
> 16
> 1 2
> 1 3 
> 1 4
> 2 5
> 2 6 
> 3 7
> 4 8
> 5 9 
> 5 10
> 6 11
> 6 12 
> 6 13 
> 7 14 
> 7 15 
> 8 16
> 8 17

><font color="#00b050"> STDOUT: </font>
> Visiting root
> Visiting node 1
> Visiting node 2
> Visiting node 3
> Visiting node 4
> Visiting node 5
> Visiting node 6
> Visiting node 7
> Visiting node 8
> Visiting node 9
> Visiting node 10
> Visiting node 11
> Visiting node 12
> Visiting node 13
> Visiting node 14
> Visiting node 15
> Visiting node 16
> Visiting node 17

