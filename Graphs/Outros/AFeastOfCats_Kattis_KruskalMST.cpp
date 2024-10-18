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

//Cada valor começa por ser o seu proprio set
void makeSet(int v, vi &parent) {
	parent[v] = v;
}
int findSet(int v, vi &parent) {
	if (v != parent[v]) parent[v] = findSet(parent[v], parent);
	return parent[v];
}
void unionSets(int u, int v, vi &parent) {
	int root1 = findSet(u, parent);
	int root2 = findSet(v, parent);
	parent[root2] = root1;
}
bool check(int u, int v, vi &parent) {
	return findSet(u, parent) == findSet(v, parent);
}

template<class T> T KruskalMST(vector<tuple<T, int, int>> edges, int V){
	sort(all(edges));
	vi parent(V);
	for (int i = 0; i < V; i++){
		makeSet(i, parent);
	}
	T mst_cost = 0, num_taken = 0;
	for (auto &[w, u, v]: edges){
		if (check(u, v, parent)) continue;
		mst_cost += w;
		unionSets(u, v, parent);
		++num_taken;
		if (num_taken == V-1) break;
	}
	return mst_cost;
}

void solve(){
	ll n, c, a, b, v;
	cin>>n>>c;
	vector<tuple<ll, int, int>> edges;
	for (int i = 0; i < (c*(c-1))/2; i++){
		cin>>a>>b>>v;
		edges.pb(make_tuple(v, a, b));
	}
	ll custo = KruskalMST(edges, c);
	if (custo + c > n) cout<<"no"<<endl;
	else cout<<"yes"<<endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout<<fixed<<setprecision();
	//cin>>getline(cin, string);
	ll t;
	cin>>t;
	for(ll i = 0; i < t; i++){
		solve();
	}
	return 0;
}
