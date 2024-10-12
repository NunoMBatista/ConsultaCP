Algoritmo que encontra o Lowest Common Ancestor de dois vértices de uma árvore, com a ajudar de uma SparseTable (pode se tambem usar uma SegTree
Complexidade: O(N), sendo N = número de Nós na Árvore + Complexidade da SparseTable/SegTree
Cuidado com os tamanhos de L, E, e H.
```c++
void dfs(int cur, int depth, vv &adjMatrix, vb &visited, vi &L, vi &E, vi &H, int &idx){
    H[cur] = idx;
	E[idx] = cur;
	L[idx++] = depth;
	visited[cur] = true;
	for (int nxt: adjMatrix[cur]){
	  if (!visited[nxt]){
			dfs(nxt, depth+1, adjMatrix, visited, L, E, H, idx);
	  	E[idx] = cur;
			L[idx++] = depth;
		}
	}
}

void buildRMQ(int n, vv &adjMatrix, int m){
	vi L(2*n), E(2*n), H(n, -1);
	vb visited(n, false);
	int idx = 0;
	dfs(0, 0, adjMatrix, visited, L, E, H, idx);
	//LCA(i, j) é o E[ indice do min( L(H[i]...H[j]) ) ]. Para isto usamos uma SegTree ou SparseTable em L (E[SpT.query(H[i], H[j])])
	SparseTable Spt = SparseTable(L);
	int a, b;
	for (int i = 0; i < m; i++){
		cin>>a>>b;
		a--;b--;
		int lca = E[Spt.RMQ(min(H[a], H[b]), max(H[a], H[b]))];
}
```
