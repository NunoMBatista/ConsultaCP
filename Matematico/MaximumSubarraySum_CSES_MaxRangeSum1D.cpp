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

ll MaximumSubarraySumN(int n, vll &arr){
    ll maior = 0;
    //limpeza dos negativos
    maior = arr[0];
    for (int j = 0; j < n; j++){
        if (arr[j] >= 0){
            maior = 0;
            break;
        }else{
            if (arr[j] > maior) maior = arr[j];
        }
    }
    if (maior < 0) return maior;
    //fim de limpeza
    ll atual = 0, cache = -1, flag = 0;
    for (int j = 0; j < n; j++){
        if ((atual + arr[j]) < 0){
            if (cache != -1){
                if (cache > maior) maior = cache;
                cache = -1;
                flag = 0;
            }else{
                if (atual > maior) maior = atual;
            }
            atual = 0;
        }else{
            if ((atual + arr[j] >= atual) || flag){
                atual += arr[j];
                if (atual > cache){
                    cache = -1;
                    flag = 0;
                }
            }else{
                cache = atual;
                atual += arr[j];
                flag = 1;
            }
        }
    }
    if (cache != -1){
        if (cache > maior) maior = cache;
    }else{
        if (atual > maior) maior = atual;
    }
    return maior;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cout<<fixed<<setprecision();
    //cin>>getline(cin, string);
    ll t = 1;
    //cin>>t;
    for(ll i = 0; i < t; i++){
        int n;
        cin>>n;
        vll arr(n);
        for (int j = 0; j < n; j++){
            cin>>arr[j];
        }
        cout<<MaximumSubarraySumN(n, arr)<<endl;
    }
    return 0;
}