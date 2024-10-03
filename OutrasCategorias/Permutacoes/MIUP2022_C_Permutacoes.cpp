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

pii transforma(string a){
	return mp(a[0]-'A', a[1]-'1');
}

bool checkHorse(pii arr, pii dest){
	if ((arr.fi + 1 == dest.fi) && (arr.se + 2 == dest.se)) return true;
	if ((arr.fi - 1 == dest.fi )&& (arr.se + 2 == dest.se)) return true;
	if ((arr.fi + 1 == dest.fi )&& (arr.se - 2 == dest.se)) return true;
	if ((arr.fi - 1 == dest.fi )&& (arr.se - 2 == dest.se)) return true;
	if ((arr.fi + 2 == dest.fi )&& (arr.se + 1 == dest.se)) return true;
	if ((arr.fi - 2 == dest.fi )&& (arr.se + 1 == dest.se)) return true;
	if ((arr.fi + 2 == dest.fi )&& (arr.se - 1 == dest.se)) return true;
	if ((arr.fi - 2 == dest.fi )&& (arr.se - 1 == dest.se)) return true;
	return false;
}

bool checkRook(pii arr, pii dest){
	if (arr.fi == dest.fi || arr.se == dest.se) return true;
	return false;
}

bool checkBishop(pii arr, pii dest){
	if (abs(arr.fi - dest.fi) == abs(arr.se - dest.se)) return true;
	return false;
}

bool checkQueen(pii arr, pii dest){
	return checkRook(arr, dest) || checkBishop( arr,  dest);
}

bool checkArchBishop(pii arr, pii dest){
	return checkBishop(arr, dest) || checkHorse(arr, dest);
}

bool checkChancellor(pii arr, pii dest){
	return checkRook(arr, dest) || checkHorse(arr, dest);
}

void permute(vvpii &all_combs, vpii &a, int l, int r, int &count){ 
    // Base case 
    if (l == r){
			all_combs.pb({});
			for(pii num: a){
				all_combs[count].pb(num);
			}
			count++;
		}
    else { 
        // Permutations made 
        for (int i = l; i <= r; i++) { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(all_combs, a, l + 1, r, count); 
  
            // backtrack 
            swap(a[l], a[i]); 
        } 
    } 
}
void solve(){
	int n;
	cin>>n;
	string aux;
	cin>>aux;
	pii arr = transforma(aux);
	vpii jogadas;
	for (int i = 0; i < n; i++){
		cin>>aux;
		jogadas.pb(transforma(aux));
	}
	int total = INF;
	pii ini;
	string res = "";
	vvpii all_combs;
	int count = 0;
	permute(all_combs, jogadas, 0, n-1, count);
	vb visited(26, false);
	for(int i = 0; i < count; i++){
		int cur = 0;
		ini = arr;
		for (int j = 0; j < n; j++){
			if (checkArchBishop(ini, all_combs[i][j])) cur++;
			else cur+=2;
			ini.fi = all_combs[i][j].fi;
			ini.se = all_combs[i][j].se;
		}
		if (total > cur){
			total = cur;
			res = "A";
			visited.clear();
			visited.resize(26, false);
			visited['A'-'A'] = true;
		}else if (total == cur){
			if (!visited['A'-'A']){
				res += "A";
		 		visited['A'-'A'] = true;
			}
		}
		cur = 0;
		ini = arr;
		for (int j = 0; j < n; j++){
			if (checkChancellor(ini, all_combs[i][j])) cur++;
			else cur+=2;
			ini.fi = all_combs[i][j].fi;
			ini.se = all_combs[i][j].se;
		}
		if (total > cur){
			total = cur;
			res = "C";
			visited.clear();
			visited.resize(26, false);
			visited['C'-'A'] = true;
		}else if (total == cur){ 
			if (!visited['A'-'C']){
				res += "C";
		 		visited['A'-'C'] = true;
			}
		}
		cur = 0;
		ini = arr;
		for (int j = 0; j < n; j++){
			if (checkQueen(ini, all_combs[i][j])) cur++;
			else cur+=2;
			ini.fi = all_combs[i][j].fi;
			ini.se = all_combs[i][j].se;
		}
		if (total > cur){
			total = cur;
			res = "Q";
			visited.clear();
			visited.resize(26, false);
			visited['Q'-'A'] = true;
		}else if (total == cur){
			if (!visited['Q'-'A']){
		 		res+="Q";
		 		visited['Q'-'A'] = true;
			}
		}
	}
	ini = arr;
	cout<<total<<' '<<res<<endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//cout<<fixed<<setprecision();
	//cin>>getline(cin, string);
	ll t;
	cin>>t;
	for(ll i = 0; i < t; i++){
		solve();
		cout<<2<<endl;
	}
	return 0;
}
