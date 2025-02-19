Estrutura que permite realizar operações de querie e update em arrays de soma cumulativa
Complexidade: Inicialização - O(m + n) sendo n = o tamanho do array cuja ocorrencia dos seus valores está a ser contabilizada e m = valor máximo dentro do array de valores
              Queries e Inserções - O(log(m)) 

```c++
int m;
ll ft[5000010];		//tamMax+1 > m
ll ftAux[5000001];

//Fazer build às ft's necessárias (ftAux só no caso de RURQ)
void build(ll* v){
		for (int i = 0; i <= m; i++){
				v[i] = 0;
		}
}

void build(ll* v, const vll &f){					//Recebe array com frequencias de valores
		for (int i = 0; i <= m; i++){
				v[i] = f[i];
				if (i + (i & -(i)) <= m){
						v[i + (i & -(i))] += v[i];
				}
		}
}

void build(ll *v, const vi &s){						//Recebe array dos valores por contar
		vll f(m+1, 0);
		for (int i = 0; i < (int)s.size(); i++){
			 ++f[s[i]];
		}
		build(v, f);
}

//Operações a usar em caso de PURQ e PUPQ, usar apenas ft
ll rsq(ll *v, int j){
		ll sum = 0;
		for(; j; j -= (j & -(j))){
				sum += v[j];
		}
		return sum;
}

ll rsq(ll *v, int i, int j){ return rsq(v, j) - rsq(v, i-1); } //inc/exclusion

void update(ll *fv, int i, ll v){
		for (; i < m; i += (i & -(i))){
				fv[i] += v;
		}
}

//Qual prefix sum tem o valor k
int select(ll* v, ll k){
		int p = 1;
		while (p*2 < m) p *= 2;
		int i = 0;
		while (p) {
				if (k > v[i+p]) {
						k -= v[i+p];
						i += p;
				}
				p /= 2;
		}
		return i+1;
}

//Operações a usar em caso de RUPQ, usar apenas ft
void range_update(ll *fv, int ui, int uj, ll v){
		update(fv, ui, v);
		update(fv, uj+1, -v);
}

ll point_query(ll *v, int i) { return rsq(v, i); }

//Operações a usar em caso de RURQ, usar ft e ftaux, inicializadas no início
void range_update(ll *fv, ll *vaux, int ui, int uj, ll v){
		range_update(fv, ui, uj, v);
		update(vaux, ui, v*(ui-1));
		update(vaux, uj+1, -v*(uj));
}
ll rsq(ll *v, ll*vaux, int j){
		return point_query(v, j)*j - rsq(vaux, j);
}

ll rsq(ll *v, ll *vaux, int i, int j) { return rsq(v, vaux, j) - rsq(v, vaux, i-1); }
```
