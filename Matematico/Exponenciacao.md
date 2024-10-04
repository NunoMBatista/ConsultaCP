Algoritmo que permite exponenciar qualquer numero, em modulo m, eficientemente
Complexidade: O(log(p)) sendo p = potencia, b = base e m = modulo
```c++
int modPow(int b, int p, int m){
	if (p == 0) return 1;
	int ans = modPow(b, p/2, m);
	ans = mod(ans*ans, m);
	if (p&1) ans = mod(ans*b, m);
	return ans;
}
```
