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

void solve(){
    int n;
    cin>>n;
    vi ent(n);
    vi sai(n);
    for (int j = 0; j < n; j++){
        cin>>ent[j]>>sai[j];
    }
    sort(all(ent));
    sort(all(sai));
    int ind1 = 0, ind2 = 0, cur = 0, maxi = 0;
    while (ind1 < n){
        if (ent[ind1] < sai[ind2]){
            cur++;
            if (cur > maxi) maxi = cur;
            ind1++;
        }else{
            cur--;
            ind2++;
        }
    }
    cout<<maxi<<endl;
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