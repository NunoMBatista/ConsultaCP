#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1e9+7;
double eps = 1e-12;
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln  "\n" 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e9
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))
#define pqTopMaior(t) priority_queue<t, vector<t>, less<t>>
#define pqTopMenor(t) priority_queue<t, vector<t>, greater<t>>
inline int mod(int a, int m) {return ((a%m) + m)%m;}

const int MAXN = 2e5 + 5;

int children[MAXN];
int counter = 2;

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

void dfs(int cur, int depth, vv &adjMatrix, vb &visited, vi &L, vi &E, vi &H, int &idx){
  H[cur] = idx;
  E[idx] = cur;
  L[idx++] = depth;
  visited[cur] = true;
  for (int nxt: adjMatrix[cur]){
    if (!visited[nxt]){
      dfs(nxt, depth+1, adjMatrix, visited, L, E, H, idx);
      E[idx] = cur;
      L[idx++] = depth;
    }
  }
}

void buildRMQ(vv &adjMatrix, int m, vi &visited){
  vi L(2*MAXN), E(2*MAXN), H(MAXN, -1);
	vb aux(MAXN, false);
  int idx = 0;
  dfs(0, 0, adjMatrix, aux, L, E, H, idx);
  //LCA(i, j) é o E[ indice do min( L(H[i]...H[j]) ) ]. Para isto usamos uma SegTree ou SparseTable em L (E[SpT.query(H[i], H[j])])
  SparseTable Spt = SparseTable(L);
  int a, b;
  for (int i = 0; i < m; i++){
    cin>>a>>b;
    int lca = E[Spt.RMQ(min(H[a], H[b]), max(H[a], H[b]))];
		if (lca != 0){
			if (visited[a] > 1){
				if (lca == b){
					cout<<L[H[a]] - L[H[b]]<<endl;
				}else if (lca == a){
			 		if (visited[b] > 1){
						cout<<L[H[a]] + L[H[children[adjMatrix[0][visited[a]-2]]]] - L[H[b]]<<endl;
					}else{
						cout<<-1<<endl;
					}
				}else{
					cout<<-1<<endl;
				}
			}else{
				if (lca == b){
			 		cout<<L[H[a]] - L[H[b]]<<endl;
			 	}else if (visited[b] > 1){
			 		cout<<L[H[a]] + L[H[children[adjMatrix[0][visited[b]-2]]]] - L[H[b]]<<endl;
				}else{
					cout<<-1<<endl;
				}
			}
		}else{
			cout<<-1<<endl;
		}
  }
}

int dfsCiclo(int no, bitset<MAXN> &ciclo, vi &visited){
	visited[no] = 1;
	ciclo[no] = true;
	if (ciclo[children[no]]){
		visited[no] = counter;
		return children[no];
	}else if (visited[children[no]] > 0) return -1;
	else{
		int res = dfsCiclo(children[no], ciclo, visited);
		if (res > 0 && visited[res] != counter) visited[no] = counter;
		return res;
	}
}

void solve(){
	int n, q;
	cin>>n>>q;
	vv parent(MAXN);
	vi visited(MAXN, 0);
	for (int i = 0; i < n; i++){
		cin>>children[i+1];
		parent[children[i+1]].pb(i+1);
	}
	for (int i = 1; i <= n; i++){
		if (visited[i] == 0){
			bitset<MAXN> ciclo;
			int c = dfsCiclo(i, ciclo, visited);
			if (c > 0){
			 	parent[0].pb(c);
			 	counter++;
			}
		}
	}
	buildRMQ(parent, q, visited);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout<<fixed<<setprecision();
	//cin>>getline(cin, string);
	ll t = 1;
	//cin>>t;
	for(ll i = 0; i < t; i++){
		solve();
	}
	return 0;
}
