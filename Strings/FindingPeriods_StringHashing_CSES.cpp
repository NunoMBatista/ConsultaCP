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
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
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
inline ll mod(ll a, ll m) {return ((a%m) + m)%m;}

vi P;

//p = Size of alphabet
vi prepareP(int n, int p){
		P.assign(n, 0);
		P[0] = 1;
		for (int i = 1; i < n; i++){
				P[i] = ((ll)P[i-1]*p) % MOD;
		}
		return P;
}

vi computeRollingHash(string T, int p){
		vi P = prepareP((int)T.length(), p);
		vi h(T.size(), 0);
		for (int i = 0; i < (int) T.length(); i++){
				if (i != 0) h[i] = h[i-1];
				h[i] = (h[i] + ((ll)T[i]*P[i]) % MOD) % MOD;
		}
		return h;
}

int extEuclidean(int a, int b, int &x, int &y){
	int xx = y = 0;
	int yy = x = 1;
	while (b){
		int q = a/b;
		int t = b;
		b = a%b;
		a = t;
		t = xx;
		xx = x-q*xx;
		x = t;
		t = yy;
		yy = y - q*yy;
		y = t;
	}
	return a;
}

int modInverse(int A, int M){          //Para combinações/fatoriais, escrever comb ou fatoriais
	int x, y;
	int d = extEuclidean(A, M, x, y);
	if (d != 1) return -1;
	return mod(x, M);
}


int hash_fast(int L, int R, vi &h){
		if (L == 0) return h[R];
		int ans = 0;
		ans = ((h[R] - h[L-1]) % MOD + MOD) % MOD;
		ans = ((ll) ans * modInverse(P[L], MOD)) % MOD;
		return ans;
}


void solve(){
		string pal;
		cin>>pal;
		int n = pal.size();
		vi h = computeRollingHash(pal, 29);
		vi res;
		for (int i = 0; i < n; i++){
				int dist = min(i, n-1-(i+1));
				if (hash_fast(0, dist, h) == hash_fast(i+1, i+1 + dist, h)){
						int ind = i+1;
						bool flag = true;
						while (ind + dist < n-1){
								int newDist = min(dist, n - 1 - (ind + dist + 1));
								if (hash_fast(ind, ind + newDist, h) != hash_fast(ind + dist + 1, ind + dist + 1 + newDist, h)){
										flag = false;
										i = ind-1;
										break;
								}
								ind += dist + 1;
						}
						if (flag){
								int aux = i+1;
								while (aux < n){
										res.pb(aux);
										aux+=i+1;
								}
								break;
						}
				}
		}
		int k = res.size();
		if (k > 0){
				for (int i = res[k-1]+1; i < n; i++){
						if (hash_fast(i, n-1, h) == hash_fast(0, n-1-i, h)){
								res.pb(i);
						}
				}
		}
		res.pb(n);
		cout<<res[0];
		for (int i = 1; i < res.size(); i++){
				cout<<' '<<res[i];
		}
		cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout<<fixed<<setprecision();
	//cin>>getline(cin, string);
  solve();
	return 0;
}
