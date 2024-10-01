Algoritmo que permite agrupar grupos cuja ordem de agrupamento nao importa
Complexidade: O(log(N)) ?
```c++
//Cada valor começa por ser o seu proprio set
void makeSet(int v, vi &parent) {
	parent[v] = v;
}
int findSet(int v, vi &parent) {
	if (v != parent[v])
	parent[v] = findSet(parent[v], parent);
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
```
