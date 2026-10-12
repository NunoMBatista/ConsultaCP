Algoritmo que encontra a maior subsequência comum a duas strings (não necessariamente contínua)
Complexidade: O(N*M), sendo N = tamanho da string A e M = tamanho da string B
```c++
// Variants: each comment below says how to change the line right ABOVE it.
//   CONTIGUOUS = longest common SUBSTRING (no skipping characters)
//   DUPLICATE  = longest part that appears twice in ONE string s
//   both       = longest duplicate substring of s
int LCS(string a, string b, int tamA, int tamB){
	vv bu(tamA + 1, vi(tamB + 1, 0));
	// CONTIGUOUS: add a new line  int best = 0;
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = bu[i-1][j-1] + 1;
			// CONTIGUOUS: inside this if, also do  best = max(best, bu[i][j]);
			// DUPLICATE: the condition becomes  a[i-1] == b[j-1] && i != j
			else bu[i][j] = max(bu[i-1][j], bu[i][j-1]);
			// CONTIGUOUS: this becomes  else bu[i][j] = 0;
		}
	}
	return bu[tamA][tamB];
	// CONTIGUOUS: this becomes  return best;
}
// DUPLICATE: call it as LCS(s, s, n, n)
```

Para obter a subsequência em si (e não só o tamanho), constrói-se a mesma tabela e depois anda-se para trás desde bu[tamA][tamB]. O tamanho é res.size().
Complexidade: O(N*M) para a tabela + O(N+M) para a reconstrução
```c++
string LCSString(string a, string b, int tamA, int tamB){
	// Tabela igual à do LCS: bu[i][j] = tamanho da LCS de a[0..i-1] e b[0..j-1]
	vv bu(tamA + 1, vi(tamB + 1, 0));
	for (int i = 1; i <= tamA; i++){
		for (int j = 1; j <= tamB; j++){
			if (a[i-1] == b[j-1]) bu[i][j] = bu[i-1][j-1] + 1;
			else bu[i][j] = max(bu[i-1][j], bu[i][j-1]);
		}
	}
	// Reconstrução: andar para trás desde bu[tamA][tamB] pelo caminho que deu o máximo
	string res = "";
	int i = tamA, j = tamB;
	while (i > 0 && j > 0){
		if (a[i-1] == b[j-1]){                  // carácter igual -> faz parte da LCS
			res += a[i-1];
			i--; j--;
		}
		else if (bu[i-1][j] >= bu[i][j-1]) i--; // o valor veio de cima
		else j--;                               // o valor veio da esquerda
	}
	reverse(res.begin(), res.end());            // foi construída de trás para a frente
	return res;
}
```

Counting LCSs (length + number of ways), e.g. MIUP 2023 J:
```c++
// Count LCSs: returns {LCS length, number of ways to form an LCS of that length}
// Works for string or vector (e.g. vector<pii>).
// Ways = different choices of matched positions.
template<class T> pair<int, ll> LCSCount(const T& a, const T& b){
	int lengthA = a.size(), lengthB = b.size();
	// len[i][j] = LCS length using the first i elements of a and the first j of b
	vv len(lengthA + 1, vi(lengthB + 1, 0));
	// ways[i][j] = how many LCSs of length len[i][j] (an empty prefix has 1 way)
	vector<vll> ways(lengthA + 1, vll(lengthB + 1, 1));
	for (int i = 1; i <= lengthA; i++)
		for (int j = 1; j <= lengthB; j++){
			bool match = (a[i-1] == b[j-1]);
			len[i][j] = max(len[i-1][j], len[i][j-1]);
			if (match) len[i][j] = max(len[i][j], len[i-1][j-1] + 1);
			// add the ways of each neighbour that reaches the same length:
			// diagonal = use the match, up = skip a[i-1], left = skip b[j-1].
			// The diagonal's ways are inside both up and left -> subtract once.
			ll total = 0;
			if (match && len[i-1][j-1] + 1 == len[i][j])
				total += ways[i-1][j-1];
			if (len[i-1][j] == len[i][j]) total += ways[i-1][j];
			if (len[i][j-1] == len[i][j]) total += ways[i][j-1];
			if (len[i-1][j-1] == len[i][j]) total -= ways[i-1][j-1];
			ways[i][j] = total;
			// modulo problems: ways[i][j] = ((total % MOD) + MOD) % MOD;
		}
	return {len[lengthA][lengthB], ways[lengthA][lengthB]};
}
// Memory: 2 tables of n*m. For n, m ~ 4000, keep only the previous row of each table.
```
