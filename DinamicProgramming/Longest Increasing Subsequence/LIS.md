Algoritmo que encontra a maior sequencia estritamente crescente dentro de uma sequencia de numeros.
Complexidade: O(log(N)*N) sendo N = tamanho da sequencia original de numeros
```c++
void printLIS(int i, vi &p, vi &arr){       //imprime LIS, sabendo o ultimo indice
	if (p[i] == -1){
		cout<<arr[i];
		return;
	}
	printLIS(p[i], p, arr);
	cout<<' '<<arr[i];
}

pii LIS(int n, vi &p, vi &arr){     //retorna maior LIS e o ultimo indice do maior LIS
	int k= 0, lis_end = 0;
	vi L(n, 0), L_id(n, 0);
	p.assign(n, -1);

	for (int i = 0; i < n; i++){
		int pos = lower_bound(L.begin(), L.begin() + k, arr[i]) - L.begin();
		L[pos] = arr[i];
		L_id[pos] = i;
		p[i] = pos ? L_id[pos-1]:-1;
		if (pos == k){
			k = pos + 1;
			lis_end = i;
		}
	}
	return mp(k, lis_end);
}
```
