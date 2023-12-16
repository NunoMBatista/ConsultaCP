/*
MINIMUM NUMBER OF COINS TO SUM UP TO N
*/


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
#define pub push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
ll min_coins(ll change, vll &coins){
    vll dp(change+1, INF);
    dp[0] = 0; 

    forsn(sub, 1, change+1){
        for(auto coin: coins){
            if(coin <= sub){
                dp[sub] = min(dp[sub], dp[sub-coin] + 1);
            }
        }
    }
    return dp[change];

}

void solve(){
    ll n, change; 
    cin >> n >> change;
    vll coins(n);
    forn(i, n){
        cin >> coins[i];
    }
    ll notPossible = (ll)INF % MOD;
    ll out = min_coins(change, coins) % MOD;
    if (out == notPossible)
        cout << -1;
    else
        cout << out;
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
