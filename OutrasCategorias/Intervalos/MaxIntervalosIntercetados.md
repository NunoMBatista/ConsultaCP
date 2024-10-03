Algoritmo que indica qual a maior quantidade de intervalos intercetados de entre qualquer momento possível
Complexidade: O(log(N)*N) ? (sort)
```c++
int MaxIntervalosIntercetados(int n, vi &ent, &sai){                 //n intervalos
	sort(all(ent));                                                //ent -> inicio de cada intervalo
	sort(all(sai));                                                //sai -> fim de cada intervalo
	int ind1 = 0, ind2 = 0, cur = 0, maxi = 0;
	while (ind1 < n){
		if (ent[ind1] < sai[ind2]){
			cur++;
			if (cur > maxi) maxi = cur;
			ind1++;
		}else{
			cur--;
			ind2++;
		}
	}
	cout<<maxi<<endl;
}
```
