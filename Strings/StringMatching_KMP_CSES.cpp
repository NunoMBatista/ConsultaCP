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

string T, P;                    // T = text, P = pattern
int n, m;                       // n = |T|, m = |P|

void kmpPreprocess(vi &b) {                         // call this first
    int i = 0, j = -1; b[0] = -1;                   // starting values
    while (i < m) {                                 // pre-process P
    while ((j >= 0) && (P[i] != P[j])) j = b[j];    // different, reset j
        ++i; ++j;                                   // same, advance both
        b[i] = j;
    }
}

void kmpSearch(vi &b) {                             // similar as above
    int i = 0, j = 0;                               // starting values
    while (i < n) {                                 // search through T
    while ((j >= 0) && (T[i] != P[j])) j = b[j];    // if different, reset j
        ++i; ++j;                                   // if same, advance both
        if (j == m) {                               // a match is found
            printf("P is found at index %d in T\n", i-j);
            j = b[j];                               // prepare j for the next
        }
    }
}

void solve(){
    cin>>T;
    cin>>P;
    n = (int) T.size();
    m = (int) P.size();
    vi b(n);                // b = back table
    kmpPreprocess(b);
    kmpSearch(b);
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