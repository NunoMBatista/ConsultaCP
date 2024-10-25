Algoritmo que encontra um caminho eulariano. Caminho eulariano é aquele que passa por todas as arestas 1 vez apenas e termina no mesmo vertice que começa
Complexidade: O(|E|)

```c++
//Para grafo direcionado, nao é preciso arestas. Guarda-se o vertices de saida diretamente na list. Outras mudanças são necessárias
//Verificar se é conexo (dfs) e todos os vertices têm grau par. Para semi-eulariano, 2 vertices com grau impar, restantes par
vi hierholzer(int s, vector<list<int>> &graph, vector<pair<pii, bool>> &arestas){
	int n = graph.size();
	vi ans, idx(n, 0), st;
	st.pb(s);
	while (!st.empty()){
		int u = st.back();
		//ciclo nao necessario para grafo direcionado
		while (!graph[u].empty() && arestas[graph[u].front()].se){
			graph[u].pop_front();
		}
		if (!graph[u].empty()){
			pii are = arestas[graph[u].front()].fi;
			if (are.fi == u) st.pb(are.se);
			else st.pb(are.fi);
			arestas[graph[u].front()].se = true;
			graph[u].pop_front();
		}else{
			ans.pb(u);
			st.pop_back();
		}
	}
	reverse(all(ans));
	return ans;
}
```
