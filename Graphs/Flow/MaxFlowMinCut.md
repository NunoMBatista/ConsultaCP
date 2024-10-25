Algoritmo que encontra o maior fluxo que um grafo pode tranferir. Este maior fluxo também corresponde ao fluxo minimo que se deve cortar para impedir passagem de fluxo no grafo. As arestas a serem cortadas podem ser guardadas
Complexidade: ?

```c++
template<class T> void dfs(int s, vector<unordered_map<int, T>> &graph, vv &adjacency, vb &visited){
	visited[s] = true;
	for (int ver: adjacency[s]){
		if (!visited[ver] && graph[s][ver] != 0){
			dfs(ver, graph, adjacency, visited);
		}
	}
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
template<class T> T edmondsKarp(vector<unordered_map<int, T>>&graph, int source, int sink, vpii *arestas = NULL) {
	assert(source != sink);
	T flow = 0;
	vi par(sz(graph)), q = par;
	int n = graph.size();
	vv adjacency(n);
	if (arestas){
		for (int i = 0; i < n; i++){
			for (pii are: graph[i]){
				adjacency[i].pb(are.fi);
			}
		}
	}
	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;

		rep(i,0,ptr) {
			int x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
				par[e.first] = x;
				q[ptr++] = e.first;
				if (e.first == sink) goto out;
				}
			}
		}
		if (arestas){
			vb visited(n, false);
			dfs(source, graph, adjacency, visited);
			for (int i = 0; i < n; i++){
				for (pair<int, T> ver: graph[i]){
					if (!visited[i] && visited[ver.fi] && graph[ver.fi][i] == 0){
						(*arestas).pb(mp(ver.fi, i));
					}
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);

		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
	}
}
```
