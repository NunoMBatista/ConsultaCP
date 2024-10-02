Algoritmo que encontra o caminho mais curto entre um vertice e os restantes. Também indentifica ciclos negativos
Complexidade: O(V*E)
```c++
vi BF(vvpii &adjList, int source){
	int n = adjList.size();
	vi dist(n+1, INF);
	dist[source] = 0;
	for (int i = 1; i < n; i++){
		bool modified = false;
		for (int j = 1; j <= n; j++){
			if (dist[j] != INF){
				for (auto nbr: adjList[j]){
					int v = nbr.fi;
					int weight = nbr.se;
					if (dist[v] > dist[j] + weight){
						dist[v] = dist[j] +weight;
						modified = true;
					}
				}
			}
		}
		if (!modified) break;
	}
	bool hasNegativeCycle = false;
	for (int i = 1; i <= n; i++){
		if (dist[i] != INF){
			for (auto nbr: adjList[i]){
				int v = nbr.fi;
				int weight = nbr.se;
				if (dist[v] > dist[i] + weight){
					hasNegativeCycle = true;
				}
			}
		}
	}
	if (hasNegativeCycle){
		for (int i = 0; i <= n; i++){ 
			dist[i] = -1;
		}
	}
	return dist;
}
```
