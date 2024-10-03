Algoritmo que encontra qual a maior quantidade de intervalos que se conseguem juntar sem se intersetarem
Complexidade: O(log(N)*N) ? (sort)
```c++
bool ord(pii a, pii b){
	return a.fi > b.fi;
}

int MaxIntervalosDisjuntos(int n, vpii &ent, vpii &sai){              //n intervalos
	sort(all(ent), ord);                                                 //ent -> inicio de cada intervalo, numero intervalo
	sort(all(sai), ord);                                                 //sai -> fim de cada intervalo, numero intervalo
	int ind1 = 0, ind2 = 0, cur = 0;
	while (ind2 < n){
		if (ent[ind1].fi >= sai[ind2].fi){
			cont[sai[ind2].se] = cont[ent[ind1].se] + 1;
			if (cont[sai[ind2].se] > cur) cur = cont[sai[ind2].se];
			ind1++;
		}else{
			cont[sai[ind2].se] = cur;
			ind2++;
		}
	}
	return cur + 1;
}
```
