Dijkstra's algorithm finds the shortest path in a directed and weighted graph storing the value in a distance vector.
Complexity: $O(E\log{V})$
```c++							 
vector<int> dijkstra(vector<vector<pii>>& adjMatrix, int source, int target) {
	int n = adjMatrix.size();
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);
	dist[source] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) {
			continue;
		}
		visited[u] = true;
		if (u == target) {
			break;
		}
		for (auto& neighbor : adjMatrix[u]) {
			int v = neighbor.first;
			int weight = neighbor.second;
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}
```
