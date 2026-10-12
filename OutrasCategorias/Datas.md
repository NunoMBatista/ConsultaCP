Calculadora de datas: ano bissexto, dias no mês, dia da semana e nº de dias desde 1/1/1 (para diferença entre datas ou somar N dias).
Complexidade: O(1). Usar long long no ano (há problemas com anos até 5*10^6).
```c++
// Ano bissexto: divisível por 4, exceto séculos que não são divisíveis por 400
bool bissexto(ll y){ return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

int diasNoMes(int m, ll y){
	int dm[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (m == 2 && bissexto(y)) ? 29 : dm[m-1];
}

// Dia da semana: 0 = Domingo, 1 = Segunda, ..., 6 = Sábado
int diaSemana(int d, int m, ll y){
	int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
	if (m < 3) y--;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

// Nº de dias desde uma data fixa (1/1/1 = 1). Diferença entre datas = dias(d2) - dias(d1)
ll dias(int d, int m, ll y){
	if (m < 3){ y--; m += 12; }   // Jan e Fev contam como meses 13 e 14 do ano anterior
	return 365*y + y/4 - y/100 + y/400 + (153*(m-3) + 2)/5 + d - 306;
}
```
