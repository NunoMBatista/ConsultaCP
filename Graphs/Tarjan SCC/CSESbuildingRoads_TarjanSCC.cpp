#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;

ll n, m;
vector<vector<ll>> graph;  
vector<vector<ll>> SCCs;
vector<bool> visited;
vector<ll> ids; 
vector<ll> low;
ll counter; 
stack<ll> S;
vector<bool> onStack;
ll id;

void dfs(ll cur){
    S.push(cur);
    onStack[cur] = true;
    ids[cur] = low[cur] = id;
    id++;

    for(auto adj: graph[cur]){
        if(ids[adj] == -1){
            dfs(adj);
        }
        // If statement after the DFS callback
        if(onStack[adj]){
            low[cur] = min(low[cur], low[adj]);
        }
    }

    // SCC root found
    ll top = -1;
    if(ids[cur] == low[cur]){
        vector<ll> newSCC;
        while(top != cur){
            top = S.top(); S.pop();
            onStack[top] = false;
            low[top] = ids[cur];
            newSCC.push_back(top);
        }
        SCCs.push_back(newSCC);
        counter++;
    }
}

void tarjan(){
    id = 1;
    counter = 0;
    
    for(ll i = 1; i <= n; ++i){
        if(ids[i] == -1){
            dfs(i);
        }
    }
    
}

void solve(){
    cin >> n >> m; 
    graph.resize(n+1);
    ids.resize(n+1, -1);
    low.resize(n+1, 0);
    onStack.resize(n+1, false);
    ll u, v;

    for(ll i = 0; i < m; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    tarjan();
    
    cout << counter-1 << endl;
    for(ll i = 0; i < counter-1; i++){
        cout << SCCs[i][0] << " " << SCCs[i+1][0] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}