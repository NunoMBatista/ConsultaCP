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

template<class T> void dfs(int s, vector<unordered_map<int, T>> &graph, vv &adjacency, vb &visited){
	visited[s] = true;
	for (int ver: adjacency[s]){
		if (!visited[ver] && graph[s][ver] != 0){
			dfs(ver, graph, adjacency, visited);
		}
	}
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
template<class T> T edmondsKarp(vector<unordered_map<int, T>>&graph, int source, int sink, vpii *arestas = NULL) {
	assert(source != sink);
	T flow = 0;
	vi par(sz(graph)), q = par;
	int n = graph.size();
	vv adjacency(n);
	if (arestas){
		for (int i = 0; i < n; i++){
			for (pii are: graph[i]){
				adjacency[i].pb(are.fi);
			}
		}
	}
	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		int ptr = 1;
		q[0] = source;

		rep(i,0,ptr) {
			int x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
				par[e.first] = x;
				q[ptr++] = e.first;
				if (e.first == sink) goto out;
				}
			}
		}
		if (arestas){
			vb visited(n, false);
			dfs(source, graph, adjacency, visited);
			for (int i = 0; i < n; i++){
				for (pair<int, T> ver: graph[i]){
					if (!visited[i] && visited[ver.fi] && graph[ver.fi][i] == 0){
						(*arestas).pb(mp(ver.fi, i));
					}
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (int y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);

		flow += inc;
		for (int y = sink; y != source; y = par[y]) {
			int p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
	}
}

void solve(){
	int n, m, a, b;
	cin>>n>>m;
	vector<unordered_map<int, float>> graph(n+1);
	vpii minCutEdges;
	for (int i = 0; i < m; i++){
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	float res = edmondsKarp(graph, 1, n, &minCutEdges);
	cout<<res<<endl;
	for (pair<int, float> edge: minCutEdges){
		cout<<edge.fi<<' '<<edge.se<<endl;
	}
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
