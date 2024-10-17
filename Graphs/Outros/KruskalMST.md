Algoritmo que calcula a Minimum Spanning Tree. MST é a menor arvore de um grafo que conecta todos os seus vertices
Complexidade: O(E*log(V))
```c++
//Cada valor começa por ser o seu proprio set
void makeSet(int v, vi &parent) {
	parent[v] = v;
}
int findSet(int v, vi &parent) {
	if (v != parent[v]) parent[v] = findSet(parent[v], parent);	
	return parent[v];
}
void unionSets(int u, int v, vi &parent) {
	int root1 = findSet(u, parent);
	int root2 = findSet(v, parent);
	parent[root2] = root1;
}
bool check(int u, int v, vi &parent) {
	return findSet(u, parent) == findSet(v, parent);
}

template<class T> T KruskalMST(vector<tuple<T, int, int>> edges, int V){
	sort(all(edges));
	vi parent(V);
	for (int i = 0; i < V; i++){
		makeSet(i, parent);
	}
	T mst_cost = 0, num_taken = 0;
	for (auto &[w, u, v]: edges){
		if (check(u, v, parent)) continue;
		mst_cost += w;
		unionSets(u, v, parent);
		++num_taken;
		if (num_taken == V-1) break;
	}
	return mst_cost;
}
```
