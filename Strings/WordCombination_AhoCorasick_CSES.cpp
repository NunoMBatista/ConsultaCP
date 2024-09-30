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

int rec(vll &dp, int ind, vi &tam, vv &ocor);

string text;    //Text
int n;          //Size of text
int k;          //Number of keys
int maxs = 0;   // Should be equal to the sum of the length of all keywords.
int maxc = 26; // Maximum number of characters in input alphabet

// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive .
int buildMatchingMachine(string arr[], int k, vector<map<int, bool>> &out, vi &f, vv &g){
    int states = 1;
    for ( int i = 0; i < k; ++i){ // Construct values for goto function, i .e ., fill g
        const string &word = arr[i];
        int currentState = 0;
        for ( int j = 0; j < (int) word.size(); ++j){
            int ch = word[j]-'a';
            if (g[currentState][ch] == -1){ // Allocate a new node (create a new state) if a node for ch doesnt exist .
                g[currentState][ch] = states++;
            }
            currentState = g[currentState][ch];
        }
        out[currentState][i] = true; // Add current word in output function
    }
    for ( int ch = 0; ch < maxc; ++ch){
        if (g[0][ch] == -1){
            g[0][ch] = 0;
        }
    }
    queue<int> q;
    for ( int ch = 0; ch < maxc; ++ch){
        if (g[0][ch] != 0){
            f [g[0][ch]] = 0;
            q.push(g[0][ch]) ;
        }
    }
    while (q.size () ) {
        int state = q.front () ;
        q.pop();
        for ( int ch = 0; ch < maxc; ++ch){
            if (g[state][ch] != -1){
                int failure = f [state];
                while (g[ failure][ch] == -1){ // Find the deepest node labeled by proper suffix of string from root to current state .
                    failure = f [ failure ];
                }
                failure = g[failure][ch];
                f [g[state][ch]] = failure ;
                for (pair<int, bool> par: out[failure]){
                    out[g[state][ch]][par.fi] = par.se;
                }
                q.push(g[state][ch]) ;
            }
        }
    }
    return states ;
}
int findNextState(int currentState, char nextInput, vector<map<int, bool>> &out, vi &f, vv &g){ //Returns the next state the machine will transition to using goto and failure functions.
    int answer = currentState;
    int ch = nextInput -'a';
    while (g[answer][ch] == -1){
        answer = f[answer];
    }
    return g[answer][ch];
}

void searchWords(string arr[], int k, string text, vector<map<int, bool>> &out, vi &f, vv &g, vv &ocor, vi &tam) {
    buildMatchingMachine(arr, k, out, f, g); // Build machine with goto, failure and output functions
    int currentState = 0;
    for ( int i = 0; i < (int) text.size() ; ++i){
        currentState = findNextState(currentState, text[i], out, f, g) ;
        /*if (out[currentState] == 0){ // If match not found, move to next state
            continue;
        }*/
        for (pair<int, bool> par: out[currentState]){ // Match found, print all matching words of arr[]
            ocor[i-tam[par.fi]+1].pb(par.fi);
        }
    }
}

void solve(){
    cin>>text;
    n = (int) text.size();
    vv ocor(n);                     //To store the index where each key starts in texts
    cin>>k;
    string arr[k];                  //Stores every key
    vi tam(k);                      //Stores every key size
    for (int j = 0; j < k; j++){
        cin>>arr[j];
        tam[j] = arr[j].size();
        maxs += tam[j];
    }
    vector<map<int, bool>> out(maxs);                       // Stores the word number for each state (letter in text)
    //vi out(maxs, 0);                                      // Bit i in this mask is one if the word with index i in that state. To use if there are less than 64 keys
    vi f (maxs, -1);                                        // FAILURE FUNCTION IS IMPLEMENTED USING f[]
    vv g (maxs, vi(maxc, -1));                              // GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
    searchWords(arr, k, text, out, f, g, ocor, tam);        // Each state (char in text) has the key numbers of the keys that start in that state in ocor  
    return;
}

int rec(vll &dp, int ind, vi &tam, vv &ocor){
    if (dp[ind] != -1){
        return dp[ind];
    }
    if (ind > n){
        return 0;
    }
    if (ind == n){
        return 1;
    }
    dp[ind] = 0;
    for (int num: ocor[ind]){
        dp[ind] = (dp[ind] + rec(dp, ind + tam[num], tam, ocor)%MOD)%MOD;
    }
    return dp[ind]%MOD;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cout<<fixed<<setprecision(8);
    ll t=1;
    for(ll i = 0; i < t; i++){
        solve();
    }
    return 0;
    /*int maxs = 12;
    n = 8;
    vv ocor(n);
    vi out(maxs, 0); // Bit i in this mask is one if the word with index i appears when the
    vi f (maxs, -1); // FAILURE FUNCTION IS IMPLEMENTED USING f[]
    vv g (maxs, vi(MAXC, -1)); // GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
    string arr [] = {"he", "she", "hers", "his" };
    string text = "ahishers";
    int k = sizeof (arr)/sizeof (arr [0]) ;
    vi tam(k);
    tam[0] = 2;
    tam[1] = 3;
    tam[2] = 4;
    tam[3] = 3;
    searchWords(arr, k, text, out, f, g, ocor, tam);
    return 0;*/
}