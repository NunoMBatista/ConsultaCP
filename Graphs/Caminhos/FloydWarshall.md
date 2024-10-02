Algoritmo que encontra o caminho mais curto de todos os vertices a todos os vertices. Também deteta ciclos infinitos
Complexidade: O(V^3)
```c++
void FW(vv &matrix, vv *p = NULL){
	int numVertices = (int) matrix.size();
	if (p){
		for (int i = 0; i < numVertices; i++){
			for (int j = 0; j < numVertices; j++){
			 	p[i][j] = i;
			}
		}
	}
	for (int k = 0; k < numVertices; k++){
		for (int i = 0; i < numVertices; i++){
			for (int j = 0; j < numVertices; j++){
				if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX){
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					if (p) p[i][j] = p[k][j];
				}
			}
		}
	}
}

void printPath(int i, int j){						//Nao sei se esta funcao esta 100% correta mas a ideia está la
	if (i != j) printPath(i, p[i][j]);
	cout<<j<<endl;
}
```
