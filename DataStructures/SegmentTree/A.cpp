#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
#define op(l, r) (l + r);
#define DEFAULTVALUE 0
const ll inf = 1e9;
struct Node {
    Node *l = 0, *r = 0;
    ll lo, hi, mset = inf, madd = 0;
    ll val = DEFAULTVALUE;
    Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
    Node(vector<int>& v, ll lo, ll hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            ll mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = op(l->val, r->val);
        }
        else val = v[lo];
    }
    ll query(ll L, ll R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return op(l->query(L, R), r->query(L, R));
    }
    void set(ll L, ll R, ll x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = val = x, madd = 0;
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
            val += x;
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
    int type, k, u, n, q; 
    cin >> n >> q; 

    vector<int> v(n);
    for(auto &i: v) cin >> i;

    Node *root = new Node(v, 0, n);

    while(q--){
        cin >> type >> k >> u; 
        if(type == 1){
            root->set(k-1, k, u);
            continue;
        }
        cout << root->query(k-1, u) << endl;

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