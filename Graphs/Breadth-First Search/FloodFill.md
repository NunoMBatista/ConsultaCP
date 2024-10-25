Algoritmo que preenche uma grid e que calcula quantas "ilhas" existem nessa grid
Complexidade: O(N*M), sendo N = numero de linhas das grid e M = numero de colunas da grid
```c++
bool valid(int i, int j, int n, int m, vector<vector<char>> &grid){
	return i>=0 && j>= 0 && i < n && j < m && grid[i][j] == '.';
}

void dfs(int i, int j, int n, int m, vv& visited,vector<vector<char>> &grid){
	visited[i][j] = 1;
	for (int k = 0; k < 4; k++){
		int ni = i + di[k], nj = j + dj[k];
		if (valid(ni, nj, n, m, grid) && !visited[ni][nj]){
			dfs(ni, nj, n, m, visited, grid);
		}
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<char>> grid(n, vector<char> (m));
	vv visited(n, vi (m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin>>grid[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (valid(i, j, n, m, grid) && !visited[i][j]){
				dfs(i, j, n, m, visited, grid);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
```
