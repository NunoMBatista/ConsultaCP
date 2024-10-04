Algoritmo que consegue encontrar a maior soma possível que se pode fazer com qualquer submatriz de uma matriz. Tem em conta numeros negaticos
Complexidade: O(N³), sendo N = lado da matriz
```c++
ll maxRangeSum2D(int n, vvll &mat){
	for (int i = 0; i < n; i++){
		for (int j = 1; j < n; j++){
			mat[i][j] += mat[i][j-1];
		}
	}
	ll maior = -INF;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			ll subrect = 0;
			for (int k = 0; k < n; k++){
				if (i > 0) subrect += mat[k][j] - mat[k][i-1];
				else subrect += mat[k][j];
				if (subrect < 0) subrect = 0;
				maior = max(maior, subrect);
			}
		}
	}
	return maior;
}
```
