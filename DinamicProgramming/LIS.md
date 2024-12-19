Algoritmo que encontra a maior sequencia estritamente crescente dentro de uma sequencia de numeros.
Complexidade: O(log(N)*N) sendo N = tamanho da sequencia original de numeros

```c++
int LIS(vi &arr){     //retorna tamanho da LIS
	vi lis;
	for (int x : arr)
	{
		auto it = lower_bound(lis.begin(), lis.end(), x);
		if (it == lis.end())
			lis.push_back(x);
		else
			*it = x;
	}

	return lis.size();
}
```
