#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 

const ll inf = 1e9;
#define DEFAULTVALUE -inf

//#define op(l, r) max(l, r+l)
pair<ll, ll> op(pair<ll, ll> l, pair<ll, ll> r){
    return make_pair((max(l.first, r.first + l.second)), (l.second + r.second));
}

struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0;
    pair<ll, ll> val = {DEFAULTVALUE, 0};

    Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vector<int>& v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = op(l->val, r->val);
            //cout << lo << " " << hi << " " <<  val << endl;
        }
        else {
            val = {v[lo], v[lo]};
            // cout << val << endl;
        }
    }
    pair<ll, ll> query(ll L, ll R) {
        if (R <= lo){
            return make_pair(DEFAULTVALUE, 0);
        }else if (hi <= L){
            return make_pair(DEFAULTVALUE, 0);
        }
        if (L <= lo && hi <= R) return val;
        // cout << "prepush: " << lo << " " << hi << " " <<  val << endl;
        push();
        // cout << "pospush: " << lo << " " << hi << " " <<  val << endl;
        // cout << "\n\n\n";

        return op(l->query(L, R), r->query(L, R));
    }
    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R){
            mset = val.first = x, madd = 0;
            val.second -= val.second;
            val.second += x;
        }
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = op(l->val, r->val);
        }
    }
    void add(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val.first += x;
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = op(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        else if (madd)
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
    }
};


void solve(){
    int type, a, b, n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    for(auto &i: v) cin >> i;

    auto* root = new Node(v, 0, n);
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         cout << (root->query(i, j+1)).first << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl << endl;

    while(q--){
        cin >> type >> a >> b;

        if(type == 1){
            root->set(a-1, a, b);
            continue;
        }

        // cout << type << " " << a << " " << b << endl;
        cout << max(0LL, root->query(a-1, b).first) << endl;
        // // for(int i = 0; i < n; i++){
        // //     cout << root->query(i, i+1)) << " ";
        // // }
        // cout << endl << endl;
    }


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