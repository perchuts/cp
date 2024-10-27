#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) (int) x.size()
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
 
const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 3e5+100;
 
template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> p(n), ans(q);
    vector<int> vals;
    for (auto& x : p) {
        cin >> x;
        vals.pb(x);
    }
    sort(all(vals)), vals.erase(unique(all(vals)), end(vals));
    for (auto& x : p) x = lower_bound(all(vals), x) - begin(vals);
    vector<int> freq(n);
    const int block = 450;
    vector<vector<iii>> qs(500);
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        --l, --r;
        qs[l/block].pb({r, l, i});
    }
    for (int bl = 0; bl < 500; ++bl) {
        sort(all(qs[bl]));
        int lp = block * bl, rp = lp, resp = 0;
        auto add = [&] (int x) {
            freq[p[x]]++;
            if (freq[p[x]] == 1) resp++;
        };
        auto rem = [&] (int x) {
            freq[p[x]]--;
            if(freq[p[x]] == 0) resp--;
        };
        for (auto [r, l, idq] : qs[bl]) {
            while (rp <= r) add(rp++);
            while (lp < l) rem(lp++);
            while (lp > l) add(--lp);
            ans[idq] = resp;
        }
        while (lp < rp) rem(lp++);
    }
    for (auto x : ans) cout << x << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
