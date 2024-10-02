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

//Para grafo direcionado, nao é preciso arestas. Guarda-se o vertices de saida diretamente na list
//Verificar se é conexo (dfs) e todos os vertices têm grau par
vi hierholzer(int s, vector<list<int>> &graph, vector<pair<pii, bool>> &arestas){	
	int n = graph.size();
	vi ans, idx(n, 0), st;
	st.pb(s);
	while (!st.empty()){
		int u = st.back();
		//ciclo nao necessario para grafo direcionado
		while (!graph[u].empty() && arestas[graph[u].front()].se){
			graph[u].pop_front();
		}
		if (!graph[u].empty()){
			pii are = arestas[graph[u].front()].fi;
			if (are.fi == u) st.pb(are.se);	
			else st.pb(are.fi);
			arestas[graph[u].front()].se = true;
			graph[u].pop_front();	
		}else{
			ans.pb(u);
			st.pop_back();
		}
	}
	reverse(all(ans));
	return ans;
}

void solve(){
	int n, m, a, b;
	cin>>n>>m;
	vector<pair<pii, bool>> arestas;
	vector<list<int>> graph(n +1);
	for (int i = 0; i < m; i++){
		cin>>a>>b;
		arestas.pb(mp(mp(a, b), false));
		graph[a].pb(i);
		graph[b].pb(i);
	}
	int count = 0;
	for (int i = 0; i <= n; i++){
		if (graph[i].size()&1){
			count++;
		}
	}
	if (count != 0 && count != 2){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	vi res = hierholzer(1, graph, arestas);
	if (res.size() != m + 1){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	cout<<res[0];
	for (int i = 1; i <= m; i++){
		cout<<' '<<res[i];
	}
	cout<<endl;
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
