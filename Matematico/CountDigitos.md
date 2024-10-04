Forma facil de saber quantos digitos um numero numa certa base tem noutra base
```c++
int countDigitos(double num, double baseNum, double baseNova){
	return floor(1 + log(num)/log(baseNova));
}
```
