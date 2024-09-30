Algoritmo que encontra uma string noutra.
Complexidade: O(N + M) sendo N = tamanho do string pesquisada e M = tamanho da string procurada
```c++
string T, P;                    // T = text, P = pattern
int n, m;                       // n = |T|, m = |P|

void kmpPreprocess(vi &b) {                         // call this first
	int i = 0, j = -1; b[0] = -1;                   // starting values
	while (i < m) {                                 // pre-process P
	while ((j >= 0) && (P[i] != P[j])) j = b[j];    // different, reset j
		++i; ++j;                                   // same, advance both
		b[i] = j;
	}
}

void kmpSearch(vi &b) {                             // similar as above
	int i = 0, j = 0;                               // starting values
	while (i < n) {                                 // search through T
	while ((j >= 0) && (T[i] != P[j])) j = b[j];    // if different, reset j
		++i; ++j;                                   // if same, advance both
		if (j == m) {                               // a match is found
			printf("P is found at index %d in T\n", i-j);
			j = b[j];                               // prepare j for the next
		}
	}
}

void solve(){
	cin>>T;
	cin>>P;
	n = (int) T.size();
	m = (int) P.size();
	vi b(m+1);                // b = back table
	kmpPreprocess(b);
	kmpSearch(b);
}
```
