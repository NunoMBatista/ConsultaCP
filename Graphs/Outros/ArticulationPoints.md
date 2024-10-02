Algoritmo que encontra vertice que, quando retirado desconexa o grafo
Complexidade: ?
```c++
void AP(int v, vv &adj, vb &check, vi &dfs, vi &low, vi &parent, int &t, int &c){
	low[v] = dfs[v] = t++;
	for (auto nbr: adj[v]){
		if (dfs[nbr] == 0){
			parent[nbr] = v;
			AP(nbr, adj, check, dfs, low, parent, t, c);
			low[v] = min(low[v], low[nbr]);
			if (!check[v]){
				if (dfs[v] == 1){
					if (dfs[nbr] != 2) c++;
				}else{
					if (low[nbr] >= dfs[v]) c++;
				}
			}
			check[v] = true;
		}else if (parent[v] != nbr){
			low[v] = min(low[v], dfs[nbr]);
		}
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	vv adj(n+1);
	vb check(n+1);
	vi dfs(n+1, 0);
	vi low(n+1, -1);
	vi parent(n+1, -1);
	int t = 1;
	int c = 0;
	AP(1, adj, check, dfs, low, parent, t, c);
}
```
