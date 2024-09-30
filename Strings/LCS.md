Algoritmo que encontra a maior substring comum a duas strings
Complexidade: O(N*M), sendo N = tamanho da string A e M = tamanho da string B
```c++
int LCS(string a, string b, int tamA, int tamB){
	vv bu(tamA + 2, vi(tamB, 0));
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = bu[i-1][j-1] + 1;
			else bu[i][j] = max(bu[i-1][j], bu[i][j-1]);
		}
	}
	return bu[tamA][tamB];
}
```
