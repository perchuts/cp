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
    int n, m; cin >> n >> m;
    vector<ii> edg(m);
    vector<int> lvl(n, -1), dp(n);
    vector<vector<int>> g(n);
    for (auto& [x, y] : edg) {
        cin >> x >> y;
        --x, --y;
        g[x].pb(y), g[y].pb(x);
    }
    int explored = 0;
    auto pre = [&] (auto&& self, int u) -> void {
        explored++;
        for (auto v : g[u]) {
            if (lvl[v] == -1) {
               lvl[v] = lvl[u] + 1;
               self(self, v);
               dp[u] += dp[v];
            } else if (lvl[v] < lvl[u]) dp[u]++;
            else dp[u]--;
        }
        if (u != 0) dp[u]--;
    };
    lvl[0] = 0;
    pre(pre, 0);
    if (explored != n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 1; i < n; ++i) if (dp[i] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    lvl = vector<int>(n, -1);
    vector<ii> ans;
    auto dfs = [&] (auto&& self, int u) -> void {
        for (auto v : g[u]) {
            if (lvl[v] == -1) {
                lvl[v] = 1 + lvl[u];
                self(self, v);
                ans.pb({u+1, v+1});
            } else if (lvl[v] > lvl[u]) {
                ans.pb({v+1, u+1});
            }
        }
    };
    lvl[0] = 0;
    dfs(dfs, 0);
    for (auto [x, y] : ans) cout << x << ' ' << y << endl;
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
