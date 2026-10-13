# Cycle Detection (DFS)

```c++
// DIRECTED graph. state: 0 = never visited, 1 = on the current path, 2 = finished
// for (int u = 0; u < n; u++) if (state[u] == 0 && hasCycle(u, state, graph)) -> cycle
// UNDIRECTED graph: pass the parent, skip v == parent, and a visited v means a cycle
bool hasCycle(int u, vi &state, vv &graph){
	state[u] = 1;
	for (int v : graph[u]){
		if (state[v] == 1) return true;
		if (state[v] == 0 && hasCycle(v, state, graph)) return true;
	}
	state[u] = 2;
	return false;
}
```
