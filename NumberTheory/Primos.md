Varios algoritmos que envolvem numeros primos:
    gerador: indica se um numero, ate 10⁷, é primo e guarda-os num array
             Complexidade: dificil de dizer, ligeiramente acima de O(N), sendo N = 10⁷, no maximo
    isPrime: verifica se numero é primo. Se N < 10⁷, usa gerador, senão, faz teste
             Complexidade: se N < 10⁷, O(1) (com gerador ja precalculado)
                           se nao, O(N^(1/2))
    primeFactor: fatoriza em fatores primos, utilizando os numeros primos gerados anteriormente
                 Complexidade: O(log(N)) ? (um numero nao tem mais de log(N) fatores primos
    numFatPrimos: Conta quantos fatores primos um numero tem
                  Complexidade: O(log(N)) ? (mesma razao anterior)
    numDivisores: Conta quantos divisores um numero tem (Multiplicatorio de (n+1), sendo n o numero de vezes que cada fator primo aparece)
                  Complexidade: O(log(N)) ? (mesma razao anterior)
    numCoprimos: Conta quantos coprimos tem um numeros: (N * Multiplicatorio(1 - 1/a), sendo a cada fator primo de N)
                 Complexidade: O(log(N)) ? (mesma razao anterior)
    numDiffFatPrimos: Indica quantos fatores primos diferentes cada numero tem. Feito para muitas queries
                      Complexidade: dificil de dizer, O(N * N/ln(N) (quantidade de numeros primos ate N)) extimativa alta, consulta O(1)
    numCoprimosMtQueries: Indica quantos coprimos cada numero tem. Feito para muitas queries
                      Complexidade: dificil de dizer, O(N * N/ln(N) (quantidade de numeros primos ate N)) extimativa alta, consulta O(1)

```c++
ll sieve_size;
bitset<10000010> bs;
vll p;

void gerador(ll upperbound){                //Não maior de 10^7
	sieve_size = upperbound+1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 0; i < sieve_size; i++){
		if (bs[i]){
			for (ll j = i*i; j < sieve_size; j+=i) bs[j] = 0;
			p.push_back(i);
		}
	}
}

bool isPrime(ll N){
	if (N < sieve_size) return bs[N];
	for (int i = 0; i < (int) p.size() && p[i]*p[i] <= N; i++){
		if (N%p[i] == 0) return false;
	}
	return true;
}

//Por no solve
gerador(10000000);

vll primeFactor(ll N){      //Fatorizar em numeros primos, não esquecer de gerar numeros primos
	vll factors;
    int tam = p.size();
	for (int i = 0; (i < tam) && (p[i]*p[i] <= N); i++){
		while (N%p[i] == 0){
			N /= p[i];
			factors.pb(p[i]);
		}
	}
	if (N != 1) factors.pb(N);
	return factors;
}

int numFatPrimos(ll N){     //Quantos fatores primos tem um numero
	int ans = 1;
	for (int i = 0; (i < (int) p.size()) && (p[i]*p[i] <= N); i++){
		while (N%p[i] == 0) {
			N/=p[i];
			ans++;
		}
	}
	return ans + (N != 1);
}

int numDivisores(ll N){          //Multiplicatorio de (n+1), sendo 'n' o numero de vezes que cada fator primos aparece
	int ans = 0;
	for (int i = 0; (i < (int) p.size()) && (p[i]*p[i] <= N); i++){
		int power = 0;
		while (N%p[i] == 0){
			N /= p[i];
			++power;
		}
		ans *= power+1;
	}
	return (N != 1) ? 2*ans : ans;
}

ll sumDivisores(ll N){          //Multiplicatório de (a^(n+1) - 1)/(a-1), sendo 'a' cada fator primo e 'n' o número de vezes que 'a' se repete
	ll ans = 1;
	for (int i = 0; (i < (int) p.size()) && (p[i]*p[i] <= N); i++){
		ll multiplier = p[i], total = 1;
		while (N%p[i] == 0){
			N /= p[i];
			total += multiplier;
			multiplier *= p[i];
		}
		ans *= total;
	}
	if (N != 1) ans *= (N+1);
	return ans;
}

ll numCoprimos(ll N){       //N * Multiplicatorio de (1 - 1/a), sendo 'a' cada fator primo de N
	ll ans = N;
	for (int i = 0; (i < (int) p.size()) && (p[i]*p[i] <= N); i++){
		if (N%p[i] == 0) ans -= ans/p[i];
		while (N%p[i] == 0) N/=p[i];
	}
	if (N != 1) ans -= ans/N;
	return ans;
}
 
vi numDiffFatPrimos(ll MAX_N){    //MAX_N <= 10^7       Numero de fatores primos diferentes para mt queries
	vi arr(MAX_N + 10, 0);
	for (int i = 2; i <= MAX_N; i++){
		if (arr[i] == 0){
			for (int j = i; j <= MAX_N; j+=i){
				++arr[j];
			}
		}
	}
	return arr;
}

vi numCoprimosMtQueries(ll Max_n){      //Max_n <= 10^7     Numero de coprimos para mt queries
	vi arr(Max_n);
	for (int i = 1; i <= Max_n; i++) arr[i] = i;
	for (int i = 2; i <= Max_n; i++){
		if (arr[i] == i){
			for (int j = i; j <= Max_n; j+=i){
				arr[j] = (arr[j]/i) * (i-1);
			}
		}
	}
	return arr;
}
```
