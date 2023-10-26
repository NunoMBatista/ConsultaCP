#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vv;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pii> > vvpii;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
ll MOD = 1000000007;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF INT_MAX
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool good(ll x, vll v, ll target){
    ll ans = 0;
    //cout << target << v[0];
    forn(i, (int)v.size()){
        ans += v[i] > target ? 0 : target - v[i];
        //cout << ans << endl;
    }
    return ans > x ? true : false;
}

void solve(){
    ll n, x;
    cin >> n >> x;
    vll v(n);
    forn(i,n){cin >> v[i];}
    sort(all(v));
    ll lb = 0, rb = 1;
    while(!good(x, v, rb))rb *= 2;
    while (rb > lb + 1){
        ll mb = lb + (rb - lb)/2;
        if (good(x, v, mb)){
            rb = mb;
        }
        else 
            lb = mb;
    }
    cout << lb << endl;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}