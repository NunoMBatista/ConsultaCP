#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;
 
vector<vector<ll>> dist;
vector<vector<char>> grid;
vector<vector<pair<ll, ll>>> parents;
queue<pair<ll, ll>> q;
ll n, m; 
string out;

bool possible = false;
bool advPath = false;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};

bool edge(pair<ll, ll> coords){
    return (coords.first == 0 || coords.second == 0 || coords.first == n-1 || coords.second == m-1);
}

bool valid(ll i, ll j){
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
}

void getPath(pair<ll, ll> node){
    pair<ll, ll> parent = parents[node.first][node.second];
    if(parent.first == -1)
        return;
    if(parent.first == node.first + 1)
        out.push_back('U');
    if(parent.first == node.first - 1)
        out.push_back('D');
    if(parent.second == node.second + 1)
        out.push_back('L');
    if(parent.second == node.second - 1)
        out.push_back('R');
    getPath(parent);
}

void bfs(){
    ll curDist = 0;
    while(!q.empty()){
        pair<ll, ll> cur = q.front(); q.pop();   
        curDist = dist[cur.first][cur.second];

        for(int k = 0; k < 4; k++){
            pair<ll, ll> next = {cur.first + di[k], cur.second + dj[k]};

            // curDist + 1 < dist[next.first][next.second] ensures that it is worth it to visit de adjacent node
            if((valid(next.first, next.second) && (curDist + 1 < dist[next.first][next.second]))){
                dist[next.first][next.second] = curDist + 1; // The distance from the origin to the next node is always the current distance + 1
                q.push(next);
                parents[next.first][next.second] = cur; // The next node's parent is the current one
            }
        }

        if(advPath && (edge(cur))){
            cout << "YES" << endl << dist[cur.first][cur.second] << endl;
            getPath(cur);
            reverse(out.begin(), out.end());
            cout << out << endl;
            possible = true;            
        }
    }
}

void solve(){
    cin >> n >> m; 
    char add;
    grid.resize(n, vector<char>(m));
    dist.resize(n, vector<ll>(m, INT_MAX));

    pair<ll, ll> start;
    parents.resize(n, vector<pair<ll, ll>>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> add; 
            if(add == 'A'){
                start = {i, j};
            }
            if(add == 'M'){
                q.push({i, j});
                dist[i][j] = 0;
            }
            grid[i][j] = add;
        }
    }

    // BFS for each one of the monsters
    bfs();
    
    advPath = true; // Flag to indicate that the next BFS will define the adventurer's path
    q.push(start);
    parents[start.first][start.second] = {-1, -1}; // This is set to {-1, -1} in order for the getPath function to know when it has reached the origin
    dist[start.first][start.second] = 0;
    
    bfs();

    if(!possible)
        cout << "NO" << endl;
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