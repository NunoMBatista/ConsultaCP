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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
template<class T> T edmondsKarp(vector<unordered_map<int, T>>&graph, int source, int sink) {
    assert(source != sink);
    T flow = 0;
    vi par(sz(graph)), q = par;

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
	//reset e leitura de valores
	ll n, m;
	cin>>n>>m;
	//criar sempre um "novo" sink e source
	ll i_source = 0, i_sink = n*2 + 1;
	vi pop(n + 1);
	vi custos(n + 1);
	vector<unordered_map<int, ll>> graph((n+1)*2);
	for (ll i = 1; i <= n; i++){
		cin>>pop[i]>>custos[i];
		graph[(i*2) - 1][i*2] = custos[i];
	}
	while(m--) {
		//Se a aresta nao for de duplo sentido, o res do sentido contrario tem de ser 0
		ll n_1, n_2;
		cin>>n_1>>n_2;
		graph[n_1*2][(n_2*2) - 1] = INF;
		graph[n_2*2][(n_1*2) - 1] = INF;
	}
	ll safe;
	cin>>safe;
	//ligar source e sink aos vertices necessarios
	for (ll i = 1; i <= n; i++){
		graph[i_source][(i*2) - 1] = pop[i];
	}
	graph[(safe*2) - 1][i_sink] = INF;
	ll maxFlow = edmondsKarp(graph, i_source, i_sink);
	cout<<maxFlow<<endl;
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
