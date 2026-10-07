Algoritmo que permite tornar uma string num hash, para fazer operações de comparação de forma constante
Complexidade -> Construção dos hashes: O(n), comparação entre hashes: O(1)
Cuidado com o tipo de problema e a quantidade de comparações a serem feitas. Pode-se sofrer do Birthday Paradox.
Para evitar, aumenta-se MOD, mas é preciso ter cuidado com overflow
```c++
vi P;

//p = Size of alphabet
vi prepareP(int n, int p){
		P.assign(n, 0);
		P[0] = 1;
		for (int i = 1; i < n; i++){
				P[i] = ((ll)P[i-1]*p) % MOD;
		}
		return P;
}

vi computeRollingHash(string T, int p){
		vi P = prepareP((int)T.length(), p);
		vi h(T.size(), 0);
		for (int i = 0; i < (int) T.length(); i++){
				if (i != 0) h[i] = h[i-1];
				h[i] = (h[i] + ((ll)T[i]*P[i]) % MOD) % MOD;
		}
		return h;
}

int extEuclidean(int a, int b, int &x, int &y){
	int xx = y = 0;
	int yy = x = 1;
	while (b){
		int q = a/b;
		int t = b;
		b = a%b;
		a = t;
		t = xx;
		xx = x-q*xx;
		x = t;
		t = yy;
		yy = y - q*yy;
		y = t;
	}
	return a;
}

int modInverse(int A, int M){          //Para combinações/fatoriais, escrever comb ou fatoriais
	int x, y;
	int d = extEuclidean(A, M, x, y);
	if (d != 1) return -1;
	return mod(x, M);
}


int hash_fast(int L, int R, vi &h){
		if (L == 0) return h[R];
		int ans = 0;
		ans = ((h[R] - h[L-1]) % MOD + MOD) % MOD;
		ans = ((ll) ans * modInverse(P[L], MOD)) % MOD;
		return ans;
}
```
