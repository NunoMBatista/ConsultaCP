Algoritmo que permite "editar" 2 string para que fiquem iguais. Este exemplo indica o número mínimo alterações para isso acontecer.
Complexidade: O(n*m), tempo e espaço
```c++
int EditDistance(string a, string b, int tamA, int tamB){
	vv bu(tamA + 1, vi(tamB + 1));
	for (int i = 0; i <= tamA; i++) bu[i][0] = i;   // apagar tudo
	for (int j = 0; j <= tamB; j++) bu[0][j] = j;   // inserir tudo
	for (int i = 1; i <= tamA; i++)
		for (int j = 1; j <= tamB; j++)
			bu[i][j] = min({bu[i-1][j] + 1,                          // apagar a[i-1]
			                bu[i][j-1] + 1,                          // inserir b[j-1]
			                bu[i-1][j-1] + (a[i-1] != b[j-1])});     // substituir (grátis se iguais)
	return bu[tamA][tamB];
}
```

Versão que devolve as operações (manter / trocar / apagar / inserir) por ordem. Mesma tabela + reconstrução em O(n+m).
```c++
// Igual ao EditDistance, mas devolve as operações por ordem (da esquerda para a direita de a)
vector<string> EditOps(string a, string b, int tamA, int tamB){
	vv bu(tamA + 1, vi(tamB + 1));
	for (int i = 0; i <= tamA; i++) bu[i][0] = i;
	for (int j = 0; j <= tamB; j++) bu[0][j] = j;
	for (int i = 1; i <= tamA; i++)
		for (int j = 1; j <= tamB; j++)
			bu[i][j] = min({bu[i-1][j] + 1, bu[i][j-1] + 1, bu[i-1][j-1] + (a[i-1] != b[j-1])});
	// Andar para trás desde bu[tamA][tamB], vendo de que vizinho veio cada valor
	vector<string> ops;
	int i = tamA, j = tamB;
	while (i > 0 || j > 0){
		if (i > 0 && j > 0 && bu[i][j] == bu[i-1][j-1] + (a[i-1] != b[j-1])){
			if (a[i-1] == b[j-1]) ops.push_back(string("manter ") + a[i-1]);
			else ops.push_back(string("trocar ") + a[i-1] + " por " + b[j-1]);
			i--; j--;
		}
		else if (i > 0 && bu[i][j] == bu[i-1][j] + 1){ ops.push_back(string("apagar ") + a[i-1]); i--; }
		else { ops.push_back(string("inserir ") + b[j-1]); j--; }
	}
	reverse(ops.begin(), ops.end());   // foram encontradas de trás para a frente
	return ops;
}
```
