Estrutura que permite fazer range queries eficientemente (demorando mais tempo a sua construção). Semelhante a SegTree, mas aqui o array nunca pode ser alterado.
Complexidade: Construção -> O(N*log(N))
              Query -> O(1)
```c++
class SparseTable{
  private:
    vi A, P2, L2;             //A -> o array, P2 -> P2[x] = 2^x, L2 -> L2[x] = floor(log2(x))
    vv SpT;
	public:
    SparseTable(){}
 
    SparseTable(vi &initialA){
      A = initialA;
      int n = (int) A.size();
      int L2_n = (int) log2(n)+1;
      P2.assign(L2_n+1, 0);
      L2.assign((1<<L2_n)+1, 0);
      for (int i = 0; i <= L2_n; i++){
			  P2[i] = (1<<i);
				L2[(1<<i)] = i;
			}
      for (int i = 2; i < P2[L2_n]; i++){
			  if (L2[i] == 0) L2[i] = L2[i-1];
      }
 
      // the initialization phase
      SpT = vv (L2[n]+1, vi(n));
      for (int j = 0; j < n; j++){
			  SpT[0][j] = j;
      }
 
      //the two nested loops below have overall time complexity = O(n log(n))
      for (int i = 1; P2[i] <= n; i++){
			  for (int j = 0; j+P2[i]-1 < n; j++){
          int x = SpT[i-1][j];
					int y = SpT[i-1][j+P2[i-1]];
					SpT[i][j] = A[x] <= A[y] ? x : y;
				}
      }
    }
    
    int RMQ(int i, int j){
      int k = L2[j-i+1];
      int x = SpT[k][i];
      int y = SpT[k][j-P2[k]+1];
      return A[x] <= A[y] ? x : y;
    }
};

//Dentro de solve ou main
SparseTable Spt = SparseTable(L);
```
