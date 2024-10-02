#include <bits/stdc++.h>
#include <cmath>
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

typedef tuple<int, ll, ll, ll> edge;
class min_cost_max_flow {
private:
  int V;
  ll total_cost;
  vector<edge> EL;
  vector<vi> AL;
  vll d;
  vi last, vis;

  bool SPFA(int s, int t) { // SPFA to find augmenting path in residual graph
    d.assign(V, INF); d[s] = 0; vis[s] = 1;
    queue<int> q({s});
    while (!q.empty()) {
      int u = q.front(); q.pop(); vis[u] = 0;
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow, cost] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] > d[u] + cost)) {      // positive residual edge
          d[v] = d[u]+cost;
          if(!vis[v]) q.push(v), vis[v] = 1;
        }
      }
    }
    return d[t] != INF;                           // has an augmenting path
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    vis[u] = 1;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow, cost] = EL[AL[u][i]];
      if (!vis[v] && d[v] == d[u]+cost) {                      // in current layer graph
        if (ll pushed = DFS(v, t, min(f, cap-flow))) {
                    total_cost += pushed * cost;
          flow += pushed;
          auto &[rv, rcap, rflow, rcost] = EL[AL[u][i]^1]; // back edge
          rflow -= pushed;
          vis[u] = 0;
          return pushed;
        }
      }
    }
    vis[u] = 0;
    return 0;
  }

public:
  min_cost_max_flow(int initialV) : V(initialV), total_cost(0) {
    EL.clear();
    AL.assign(V, vi());
    vis.assign(V, 0);
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, ll c, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0, c);                 // u->v, cap w, flow 0, cost c
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, 0, 0, -c);                // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
    if (!directed) add_edge(v, u, w, c);         // add again in reverse
  }

  pair<ll, ll> mcmf(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (SPFA(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return {mf, total_cost};
  }
};

void solve(){
		/*ll n, m, big = 100 * 1000001;
    cin >> n >> m;

    ll nodes = ((n+10)*2)+2;
    ll s = nodes-1;
    ll t = nodes-2;
    min_cost_max_flow mf(nodes);

    // Create the initial two edges
    mf.add_edge(s,0,m,0); // Source to 0's in
    for(int i = 1; i <= n; i++) {
        mf.add_edge((i*2)+1,t,1,0); // n's out to sink
    }

    // Build internal edges
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            ll t;
            cin >> t;
            mf.add_edge((2*i)+1,(2*(j+1)),1,t);
        }
    }

    mf.add_edge(0,1,m,0);

    // Connect node in/out
    for(ll i = 1; i < n+1; i++) {
        mf.add_edge(2*i,2*i+1,1,-big);
    }

    // Connect the source to the sink so we can skip extra paths
    mf.add_edge(0,t,INF,0);

    pair<ll,ll> res = mf.mcmf(s, t);
    res.second += big * n;

    cout << res.second << endl;
	*/	
    ll n, m, val, big = 100 * 1000001;
    cin>>n>>m;
    int source = 0, sink = 2 * (n+1) + 1;
    min_cost_max_flow mf(2*(n+1) + 2);
    mf.add_edge(source, 1, m, 0);
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            cin>>val;
            mf.add_edge((2*i) - 1, (2*j), 1, val);
        }
    }
		for (int i = 1; i <= n; i++){
			mf.add_edge((2*i) + 1, sink, 1, 0);
		}
    for (int i = 1; i <= n; i++){
        mf.add_edge((2*i), (2*i) + 1, 1, -big);
    }
		mf.add_edge(1, sink, INF, 0);
    pair<ll, ll> res = mf.mcmf(source, sink);
    cout<<res.se + n*big<<endl;
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

