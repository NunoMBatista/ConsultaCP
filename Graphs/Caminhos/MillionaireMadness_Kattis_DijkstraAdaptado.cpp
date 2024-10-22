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

int dijkstra(vector<vector<pii>>& graph, int source, int target) {
	int n = graph.size();
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);
	dist[source] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, source));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u]) {
			continue;
		}
		visited[u] = true;
		if (u == target) {
			break;
		}
		for (auto& neighbor : graph[u]) {
			int v = neighbor.first;
			int weight = neighbor.second;
			if (dist[v] > max(dist[u], weight)) {
				dist[v] = max(dist[u], weight);
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	return dist[target];
}

void solve(){
	int l, c, val;
	cin>>l>>c;
	vi aux(c);
	vvpii adjMat(l*c);
	for (int i = 0; i < l; i++){
		for (int j = 0; j < c; j++){
			cin>>val;
			if (i > 0){
				adjMat[i*c + j].pb(mp((i-1)*c + j, max(0, aux[j] - val)));
				adjMat[(i-1)*c + j].pb(mp(i*c + j, max(0, val - aux[j])));
			}
			if (j > 0){
				adjMat[i*c + j].pb(mp(i*c + j - 1, max(0, aux[j-1] - val)));
				adjMat[i*c + j - 1].pb(mp(i*c + j, max(0, val - aux[j-1])));
			}
			aux[j] = val;
		}
	}
	cout<<dijkstra(adjMat, 0, l*c - 1)<<endl;
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
