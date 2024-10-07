Varios algoritmos que envolvem teoria de numeros:
    extEuclidean: Algoritmo extendido de Euclides, ax + by = gcd(a, b)
    modInverse: Indica o inverso modular de um numero, i.e., Ax(mod(m)) = 1 (A e M têm de ser, no minimo, coprimos)
    diophantine: Algoritmo que indica a solucao para a equacao ax + bx = sol
    crt: Chinese Remainder Theorem, encontra x tal que x seja congruente com todo o r(i) mod(m(i))
    Catalan: Sequencia de numeros que tem varias aplicações
    LCM e GCD: Lowest Common Multiplier e Greatest Common Divisor
```c++
int extEuclidean(int a, int b, int &x, int &y){
	int xx = y = 0;
	int yy = x = 1;
	while (b){
		int q = a/b;
		int t = b;
		b = a%b;
		a = t;
		t = xx;
		xx = x-q*xx;
		x = t;
		t = yy;
		yy = y - q*yy;
		y = t;
	}
	return a;
}

int modInverse(int A, int M){          //Para combinações/fatoriais, escrever comb ou fatoriais
	int x, y;
	int d = extEuclidean(A, M, x, y);
	if (d != 1) return -1;
	return mod(x, M);
}
di
pii diophantine(int a, int b, int sol){         //a*x + b*y = sol
	int x, y;
	int d = extEuclidean(a, b, x, y);           //gcd(a, b)    
	int mult = sol/d;
	x *= mult;
	y *= mult;
	b /= d;
	a /= d;
	int liminf = 0, limsup = INF;
	if ((x < 0) != (b < 0)){
		liminf = abs(x/b);
		if (x%b) liminf++;
	}else{
		limsup = abs(x/b);
	}
	if ((y < 0) != (a < 0)){
		int aux = abs(y/a);
		if (y%a) aux++;
		liminf = max(liminf, aux);
	}else{
		limsup = min(limsup, abs(y/a));
	}
	if (liminf > limsup) return mp(-1, -1);         //Só devolve uma solução para a equação, mas há um limite (finito ou infinito de soluções)
	else return mp(x + b*liminf, y + a*liminf);
}

int crt(vi &r, vi &m){
	int mt = accumulate(m.begin(), m.end(), 1, multiplies<>());
	int x = 0;
	for (int i = 0; i < (int) m.size(); i++){
		int a = mod((ll)r[i] * modInverse(mt/m[i], m[i]), m[i]);
		x = mod(x + (ll)a * (mt/m[i]), mt);
	}
	return x;
}

vll Catalan(int n, ll m){                  //n inclusive
	vll cat(n+1);
	cat[0] = 1;
	for (int i = 0; i < n; i++){
		cat[i+1] = mod(mod(mod((4*i)+2,m) * mod(cat[i],m), m) * modInverse(i+2, m),m);
	}
	return cat;
}

inline long long int gcd(int a, int b){
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

inline long long int lcm (int a, int b){
	return (a / gcd(a, b)) * b;
}
```
