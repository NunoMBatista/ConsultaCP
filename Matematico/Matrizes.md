Algoritmos que permitem realizar operacoes com matrizes
Complexidade Mul: O(linA * (colA == linB) * colB)
Complexidade Pow: O(N³log(p)), sendo p = potencia e N = lado da matriz
```c++
vvll matMul(vvll &a, vvll &b, int MOD){              //Duas matrizes não nulas, i -> linhas, j -> colunas
	int lin = a.size();
	int col = b[0].size();
	vvll ans(lin, vll(col, 0));
	int par = b.size();
	for (int i = 0; i < lin; i++){
		for (int k = 0; k < par; k++){
			if (a[i][k] == 0) continue;
			for (int j = 0; j < col; j++){
				ans[i][j] += mod(a[i][k], MOD) * mod(b[k][j], MOD);
				ans[i][j] = mod(ans[i][j], MOD);
			}
		}
	}
	return ans;
}

vvll matPow(vvll base, int p, int MOD){          //So matrizes quadradas
	int lin = base.size();
	vvll ans(lin, vll(lin));
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < lin; j++){
			ans[i][j] = (i == j);
		}
	}
	while (p){
		if (p&1){
			ans = matMul(ans, base, MOD);
		}
		base = matMul(base, base, MOD);
		p >>= 1;
	}
	return ans;
}
```
