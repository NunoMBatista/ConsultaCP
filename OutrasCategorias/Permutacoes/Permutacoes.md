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
