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

pll junta(pll a, pll b){
    if (a.fi < b.se && a.se > b.fi){
        return mp(max(a.fi, b.fi), min(a.se, b.se));
    }else{
        return mp(-1, -1);
    }
}

void solve(){
    int n, k, val;
    cin>>n>>k;
    map<pair<int, bool>, bool> ocor;
    vll arr(n);
    for (int j = 0; j < n; j++){
        cin>>arr[j];
    }
    sort(all(arr));
    pll aux = mp(arr[0], arr[0] + k), res;
    //cout<<aux.fi<<' '<<aux.se<<endl;
    for (int j = 1; j < n; j++){
        int quo = (arr[j] - aux.fi)/(2*k);
        res = junta(mp(aux.fi + quo*2*k, aux.se + quo*2*k) , mp(arr[j], arr[j] + k));
        if (res.fi == -1 && res.se == -1){
            res = junta(mp(aux.fi + (quo+1)*2*k, aux.se + (quo+1)*2*k) , mp(arr[j], arr[j] + k));
            if (res.fi == -1 && res.se == -1){
                cout<<-1<<endl;
                return;
            }
        }
        aux = res;
    }
    cout<<aux.fi<<endl;
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