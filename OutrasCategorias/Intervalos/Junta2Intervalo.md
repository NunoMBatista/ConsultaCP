Função simples que permite juntar 2 intervalos
```c++
pll junta(pll a, pll b){
	if (a.fi < b.se && a.se > b.fi){
		return mp(max(a.fi, b.fi), min(a.se, b.se));
	}else{
		return mp(-1, -1);
	}
}
```
