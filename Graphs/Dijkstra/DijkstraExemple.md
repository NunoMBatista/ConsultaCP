Dijkstra's algorithm finds the shortest path in a directed and weighted graph storing the value in a distance vector.
Complexity: $O(E\log{V})$

```c++
vvpii graph(1001);
vi visited(1001, false);
vi dist(1001, INT_MAX);

int dijkstra (int start, int target){
    priority_queue<pii, vpii, greater<pii>> PQ; 
    dist[start] = 0;  
    PQ.push(mp(dist[start], start));

    pii cur; 
    while(!PQ.empty()){
        cur = PQ.top(); PQ.pop();
        if(visited[cur.se] == false){
            visited[cur.se] = true;
            if(cur.se == target)
                break;
                
            for(auto v: graph[cur.se]){
                if(dist[v.se] > dist[cur.se] + v.fi){ //v.fi is the distance between v and cur - v.se is the distance between start and v
                    dist[v.se] = dist[cur.se] + v.fi;
                    PQ.push(mp(dist[v.se], v.se);
                }
            }
        }
    }
    return dist[target];   
}
void solve(){
    int n, m, u, v, w, s, t; 
    cin >> n >> m;

    forn(i, m){
        cin >> u >> v >> w;
        graph[u].pb(mp(w, v));
    }
    cin >> s >> t;
    cout << dijkstra(s, t) << endl;
}
``` 
