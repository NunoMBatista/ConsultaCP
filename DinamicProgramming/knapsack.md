Algoritmo que permite calcular o maior valor possivel de obter, colocando objetos com um peso especifico numa mochila com peso maximo
Complexidade: O(N*M) sendo N = numero de objetos possiveis e M = peso maximo da mochila
```c++
int knapsack(int W, int n, vi &price, vi &weight){        //linear memory
	vi aux(W+1, 0);
	for (int i = 0; i < n; i++){
		for (int j = W; j > 0; j--){
			if (weight[i] <= j){
				aux[j] = max(aux[j - weight[i]] + price[i], aux[j]);
			}
		}
	}
	return aux[W];
}
```
