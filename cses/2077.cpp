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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].pb(v), g[v].pb(u);
    }
    vector<int> tin(n), low(n), vis(n), ans(n);
    int t = 0;
    auto dfs = [&] (auto&& self, int u, int p = -1) -> void {
        vis[u] = 1;
        int child = 0;
        tin[u] = low[u] = ++t;
        for (auto v : g[u]) {
            if (v == p) continue;
            if (vis[v] == 0) {
                self(self, v, u);
                ckmin(low[u], low[v]);
                if (low[v] >= tin[u] and p != -1) ans[u] = 1;
                ++child;
            } else ckmin(low[u], tin[v]);
        }
        if (child > 1 and p == -1) ans[u] = 1;
    };
    dfs(dfs, 0);
    vector<int> resp;
    for (int i = 0; i < n; ++i) if (ans[i]) resp.pb(i+1);
    cout << sz(resp) << endl;
    for (auto x : resp) cout << x << ' ';
    cout << endl;
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
