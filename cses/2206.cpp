#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
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
    vector<int> p(n);
    vector<ii> seg(4*n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    auto upd = [&] (auto&& self, int i, int l, int r, int x, int k) -> void {
        if (l == r) {
            seg[i] = {k-l, k+l};
            return;
        }
        int md = (l+r)/2;
        if (x <= md) self(self, 2*i, l, md, x, k);
        else self(self, 2*i+1, md+1, r, x, k);
        seg[i].first = min(seg[2*i].first, seg[2*i+1].first);
        seg[i].second = min(seg[2*i].second, seg[2*i+1].second);
    };
    auto query = [&] (auto&& self, int i, int l, int r, int x, int y) -> pair<int, int> {
        if (r < x or y < l) return make_pair(inf, inf);
        if (x <= l and r <= y) return seg[i];
        int md = (l+r)/2;
        auto li = self(self, 2*i, l, md, x, y);
        auto ri = self(self, 2*i+1, md+1, r, x, y);
        pair<int, int> ans;
        ans.first = min(li.first, ri.first);
        ans.second = min(li.second, ri.second);
        return ans;
    };
    for (int i = 1; i <= n; ++i) upd(upd, 1, 1, n, i, p[i-1]);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int k, x; cin >> x >> k;
            upd(upd, 1, 1, n, x, k);
        } else {
            int x; cin >> x;
            ii ansl = query(query, 1, 1, n, 1, x);
            ii ansr = query(query, 1, 1, n, x, n);
            cout << min(ansl.first+x, ansr.second-x) << endl;
        }
    }
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
