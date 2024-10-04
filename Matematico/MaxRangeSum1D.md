Algoritmo que permite saber qual a maior soma de numeros consecutivos é um certo array pode chegar. Tem em conta numeros negativos
Complexidade: O(N), sendo N = tamanho do array
```c++
ll maxRangeSum1D(int n, vll &arr){
	ll ans = 0;
	//limpeza dos negativos
	ans = arr[0];
	for (int j = 0; j < n; j++){
		if (arr[j] >= 0){
			ans = 0;
			break;
		}else{
			if (arr[j] > ans) ans = arr[j];
		}
	}
	if (ans < 0) return ans;
	//fim de limpeza
	ans = 0;
	ll sum = 0;
	for (int j = 0; j < n; j++){
		sum += arr[j];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	return ans;
}
```
