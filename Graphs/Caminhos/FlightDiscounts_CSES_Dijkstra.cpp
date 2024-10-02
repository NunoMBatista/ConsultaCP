#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vector<ll> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 10e9+7;
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
#define INF 2e15
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define cut(str, s, e) (string(str.begin() + s, str.end() + e))

vector<ll> dijkstra(vector<vector<pii>>& graph, ll source, ll target, vi &maiorE) {
    ll n = graph.size();
    vector<ll> dist(n, INF);
    vector<bool> visited(n, false);
    dist[source] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        if (u == target) {
            break;
        }
        for (auto& neighbor : graph[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;
            if (weight > maiorE[u]){
                if (dist[v] >= dist[u] + weight/2 + maiorE[u]/2 + maiorE[u]%2) {
                    dist[v] = dist[u] + weight/2 + maiorE[u]/2 + maiorE[u]%2;
                    maiorE[v] = weight;
                    pq.push(make_pair(dist[v], v));
                }
            }else{
                if (dist[v] >= dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    maiorE[v] = maiorE[u];
                    pq.push(mp(dist[v], v));
                }
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    ll n, m, a, b, c;
    for(ll i = 0; i < t; i++){
        cin>>n>>m;
        vi maiorEN(n+1, 0);
        vi maiorEO(n+1, 0);
        vvpii adjn(n+1), adjo(n+1);
        for (ll j = 0; j < m; j++){
            cin>>a>>b>>c;
            adjn[a].pb(mp(b,c));
            adjo[b].pb(mp(a,c));
        }
        vi resn = dijkstra(adjn, 1, n, maiorEN);
        vi reso = dijkstra(adjo, n, 1, maiorEO);
        cout<<min(resn[n], reso[1])<<endl;
    }
    return 0;
}