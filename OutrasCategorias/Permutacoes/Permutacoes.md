Algoritmo que permite criar todas as permutacoes possiveis de um array
Complexidade: O(n!)
```c++
//l = 0, r = n-1
void permute(vector<int> &a, int l, int r){
	if (l >= r){
		//verificar permutação, guardá-la leva a MLE
		verifica();
	}
	else{
		//Fazer todas as permutacoes
		for (int i = l; i <= r; i++){
			swap(a[l], a[i]);
			permute(a, l+1, r);
			swap(a[l], a[i]);
		}
	}
}
```

Forma mais simples de imprimir todas as permutações, todas as combinações (subconjuntos) e as combinações de tamanho k:
```c++
// Todas as permutacoes de v (por ordem, sem repetidas)
sort(all(v));
do {
	for (int x : v) cout << x << " ";
	cout << ln;
} while (next_permutation(all(v)));

// Todas as combinacoes (subconjuntos) de v: bit i de m ligado -> v[i] escolhido
for (int m = 0; m < (1 << n); m++){
	for (int i = 0; i < n; i++) if (m >> i & 1) cout << v[i] << " ";
	cout << ln;
}

// Combinacoes de tamanho k: permutar uma mascara com k uns
vi sel(n, 0);
fill(sel.end() - k, sel.end(), 1);
do {
	for (int i = 0; i < n; i++) if (sel[i]) cout << v[i] << " ";
	cout << ln;
} while (next_permutation(all(sel)));
```
