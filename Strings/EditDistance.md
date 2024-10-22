Algoritmo que permite "editar" 2 string para que fiquem iguais. Este exemplo indica o número mínimo alterações para isso acontecer.
Complexidade: O(n*m), tempo e espaço
```c++
int EditDistance(string a, string b, int tamA, int tamB){
	vv bu(tamA + 1, vi(tamB + 1, 0));
	for (int i = 0; i <= tamA; i++){
		bu[i][0] = i;
	}
	for (int i = 0; i <= tamB; i++){
		bu[0][i] = i;
	}
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = min(min(bu[i-1][j-1], bu[i-1][j] + 1), bu[i][j-1] + 1);
			else bu[i][j] = min(min(bu[i-1][j] + 1, bu[i][j-1] + 1), bu[i-1][j-1] + 1);
		}
	}
	return bu[tamA][tamB];
}
```
