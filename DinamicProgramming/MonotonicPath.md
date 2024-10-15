Algoritmo que encontra quantos caminho Euclideanos existem numa grelha N*M
Complexidade: Se N != M, complexidade O(N*M), se N == M, complexidade O(N), usando a sequencia de Catalan
```c++
//n e m arestas, NAO vertices
ll Monotonic(int n, int m, ll p){				//Se for n*n, usar mod(Catalan(n)*(n+1), m)
	n++;
	m++;
	vvll T(n, vll(m));
	for (int i = 0; i < n; i++){
	T[i][0] = 1;
	}
	for (int i = 0; i < m; i++){
	T[0][i] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 1; j < n; j++){
			T[i][j] = mod(mod(T[i-1][j], p) + mod(T[i][j-1], p), p);
		}
	}
	return mod(T[n-1][m-1], p);
}
```
