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

bool ord(pii a, pii b){
    return a.fi > b.fi;
}

void solve(){
    int n;
    cin>>n;
    vpii ent(n);
    vpii sai(n);
    vi cont(n, 0);
    for (int j = 0; j < n; j++){
        cin>>ent[j].fi>>sai[j].fi;
        ent[j].se = sai[j].se = j;
    }
    sort(all(ent), ord);
    sort(all(sai), ord);
    int ind1 = 0, ind2 = 0, cur = 0;
    while (ind2 < n){
        if (ent[ind1].fi >= sai[ind2].fi){
            cont[sai[ind2].se] = cont[ent[ind1].se] + 1;
            if (cont[sai[ind2].se] > cur) cur = cont[sai[ind2].se];
            ind1++;
        }else{
            cont[sai[ind2].se] = cur;
            ind2++;  
        } 
    }
    cout<<cur + 1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cout<<fixed<<setprecision();
    ll t = 1;
    //cin>>t;
    for(ll i = 0; i < t; i++){
        solve();
    }
    return 0;
}