The Depth-first search algorithm starts at the selected root node and searches each branch as far as possible backtracking.  
Unlike BFS, which uses a queue data structure, DFS uses a stack.  
  
1 - Initialize a visited array $vis$ and a stack of nodes $S$.  
2 - Insert the root into $S$.  
3 - While $S$ is not empty:  
&nbsp;&nbsp;&nbsp;&nbsp;4 - For each node $v$ on top of $S$, $vis[v] = true$, pop $v$ it and insert every node adjacent to $v$ into $S$.  
&nbsp;&nbsp;&nbsp;&nbsp;5 - Run the DFS function with the node on top of $S$ as an argument.  

Evidently, the recursive call acts as a stack, so the stack itself does not need to be initialized.  
  
```c++
void DFS(vector<bool> &vis, vector<vector<ll>> &adj, int v){
    vis[v] = true;
    for(auto i : adj[v]){
      if(vis[i] == false)
        DFS(vis, adj, i);
    } 
} 
```
