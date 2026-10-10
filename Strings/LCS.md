Algoritmo que encontra a maior subsequência comum a duas strings (não necessariamente contínua)
Complexidade: O(N*M), sendo N = tamanho da string A e M = tamanho da string B
```c++
int LCS(string a, string b, int tamA, int tamB){
	vv bu(tamA + 1, vi(tamB + 1, 0));
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = bu[i-1][j-1] + 1;
			else bu[i][j] = max(bu[i-1][j], bu[i][j-1]);
		}
	}
	return bu[tamA][tamB];
}
```

Para obter a subsequência em si (e não só o tamanho), constrói-se a mesma tabela e depois anda-se para trás desde bu[tamA][tamB]. O tamanho é res.size().
Complexidade: O(N*M) para a tabela + O(N+M) para a reconstrução
```c++
string LCSString(string a, string b, int tamA, int tamB){
	// Tabela igual à do LCS: bu[i][j] = tamanho da LCS de a[0..i-1] e b[0..j-1]
	vv bu(tamA + 1, vi(tamB + 1, 0));
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = bu[i-1][j-1] + 1;
			else bu[i][j] = max(bu[i-1][j], bu[i][j-1]);
		}
	}
	// Reconstrução: andar para trás desde bu[tamA][tamB] pelo caminho que deu o máximo
	string res = "";
	int i = tamA, j = tamB;
	while (i > 0 && j > 0){
		if (a[i-1] == b[j-1]){                  // carácter igual -> faz parte da LCS
			res += a[i-1];
			i--; j--;
		}
		else if (bu[i-1][j] >= bu[i][j-1]) i--; // o valor veio de cima
		else j--;                               // o valor veio da esquerda
	}
	reverse(res.begin(), res.end());            // foi construída de trás para a frente
	return res;
}
```
