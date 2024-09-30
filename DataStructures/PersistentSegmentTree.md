Estrutura que permite guardar e alterar Segment Trees ao longo do tempo
Complexidade: Construção da primeira SegTree - O(2*N) sendo N = tamanho do array
              Update - O(log(N)) sendo N = tamanho do array
```c++
struct Node{ int mn, l, r; };

int init(int l, int r, Node st[], int* curr){
	if (l == r){ st[++(*curr)].mn = INF; return (*curr); }
	int m = l+(r-l)/2;
	int p = ++(*curr);
	st[p] = {0, init(l, m, st, curr), init(m+1, r, st, curr)};
	st[p].mn = min(st[st[p].l].mn, st[st[p].r].mn);
	return p;
}

int update(int i, int l, int r, int k, int x, Node st[], int* curr){
	if (l == r){ st[++(*curr)].mn = x; return *curr; }
	int m = l+(r-l)/2;
	int p = ++(*curr);
	if (k <= m){
		st[p] = {0, update(st[i].l, l, m, k, x, st, curr), st[i].r};
	} else {
		st[p] = {0, st[i].l, update(st[i].r, m+1, r, k, x, st, curr)};
	}
	st[p].mn = min(st[st[p].l].mn, st[st[p].r].mn);
	return p;
}

int query(int i, int l, int r, int tl, int tr, Node st[]){
	if (l > tr || r < tl) return INF;
	if (tl <= l && r <= tr) return st[i].mn;
	int m = l+(r-l)/2;
	return min(query(st[i].l, l, m, tl, tr, st), query(st[i].r, m+1, r, tl, tr, st));
}

int arr[n+1], root[n+2], curr = 1;				//Tres linhas seguintes por no solve
map<int, int> pos;
Node st[22*n];
```
