#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int ll

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
    int n; cin >> n;
    vector<int> aa(n), bb(n), c(2*n);
    for (auto& x : aa) cin >> x;
    for (auto& x : bb) cin >> x;
    for (int i = 0; i < n; ++i) c[i] = c[i+n] = aa[i] - bb[i];
    vector<int> pr(2*n+1), cmp = {0};
    for (int i = 1; i <= 2*n; ++i) pr[i] = pr[i-1] + c[i-1], cmp.pb(pr[i]);
    sort(all(cmp)), cmp.erase(unique(all(cmp)), end(cmp)); 
    vector<ii> seg(8*n);
    auto upd = [&] (auto&& self, int i, int l, int r, int x, int a, int b) -> void {
           if (l == r) {
                seg[i].first += a;
                seg[i].second += b;
                return;
           }
           int md = (l + r) / 2;
           if (x <= md) self(self, 2*i, l, md, x, a, b);
           else self(self, 2*i+1, md+1, r, x, a, b);
           seg[i].first = seg[2*i].first + seg[2*i+1].first;
           seg[i].second = seg[2*i].second + seg[2*i+1].second;
    };
    auto query = [&] (auto&& self, int i, int l, int r, int x, int y) -> pair<int, int> {
            if (r < x or y < l or x > y) return make_pair(0, 0);
            if (x <= l and r <= y) return seg[i];
            int md = (l + r) / 2;
            auto p1 = self(self, 2*i, l, md, x, y);
            auto p2 = self(self, 2*i+1, md+1, r, x, y);
            return make_pair(p1.first + p2.first, p1.second + p2.second);
    };
    for (int i = 1; i <= n; ++i) upd(upd, 1, 0, 2*n-1, lower_bound(all(cmp), pr[i]) - begin(cmp), 1, pr[i]);
    int ans = 1e18;
    for (int i = n+1; i <= 2*n; ++i) {
        int t = pr[i-n-1]; 
        auto menor = query(query, 1, 0, 2*n-1, 0, lower_bound(all(cmp), t) - begin(cmp));
        auto maior = query(query, 1, 0, 2*n-1, 1+lower_bound(all(cmp), t) - begin(cmp), 2*n-1);
        ckmin(ans, t * (menor.first - maior.first) - menor.second + maior.second);
        upd(upd, 1, 0, 2*n-1, lower_bound(all(cmp), pr[i-n]) - begin(cmp), -1, -pr[i-n]);
        upd(upd, 1, 0, 2*n-1, lower_bound(all(cmp), pr[i]) - begin(cmp), 1, pr[i]);
    }
    cout << ans << endl;
}

int32_t main(){_
    int t = 1; //cin >> t;
  while(t--) solve();
}
