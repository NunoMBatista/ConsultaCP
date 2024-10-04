Conjunto de algoritmos que permite calcular fatoriais e combinações, tendo-os já pré-calculados
    modInverse: Faz o inverso modular de um número
                Complexidade: ?
    fatoriais:  Pré-calcula os fatorias e inversos modulares dos fatoriais até tam, módulo m
                Complexidade: O(N), sendo N = número máximo cujo fatorial se quer calcular
    comb: Depois de ter os fatoriais pré-calculados, calcula-se qualquer combinação 
          Complexidade: O(1), tendo já os fatoriais pré-calculados

```c++
int modInverse(int A, int M){
	int m0 = M;
	int y = 0, x = 1;

	if (M == 1)
		return 0;

	while (A > 1) {
		// q is quotient
		int q = A / M;
		int t = M;

		// m is remainder now, process same as
		// Euclid's algo
		M = A % M, A = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}

vpll fat;

void fatoriais(int tam, int m, vpll &res){
	res.pb(mp(1,1));
	for (int j = 1; j <= tam; j++){
		res.pb(mp((res[j-1].fi*j)%m, 0));
	}
	ll inv = modInverse(res[tam].fi, m);
	res[tam].se = inv;
	for (int j = tam-1; j > 0; j--){
		res[j].se = (res[j+1].se*(j+1))%m;
	}
}

ll comb(int c, int d, int m){
	if (d == 0) return 1;
	if ((d > 0) && (d > c)) return 0;
	return (((fat[c].fi*fat[d].se)%m)*fat[c-d].se)%m;
}
fatoriais(5000, MOD, fat);                                 //Colocar dentro da main
```
