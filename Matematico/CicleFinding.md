Algoritmo que encontra algum ciclo numa expressão
Complexidade: O(N), sendo que N = tamanho do ciclo
```c++
int f(int x){               //Avançar na expressão onde estamos a encontrar ciclo
	return (26*x + 11)%80;
}

pii floydCicleFinding(int x){             //Index (x) onde começa a sequencia (arr)
	int t = f(x), h = f(f(x));
	while (t != h){
		t = f(t);
		h = f(f(h));
	}
	int fase = 0, h = x;
	while (t != h){
		t = f(t);
		h = f(h);
		fase++;
	}
	int T = 1;
	h = f(t);
	while (t != h){
		h = f(h);
		T++;
	}
	return mp(T, fase);
}
```
