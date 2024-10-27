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
    vector<int> lvl(n, -1);
    vector<vector<int>> g(n);
    for (auto& [x, y] : edg) {
        cin >> x >> y;
        --x, --y;
        g[x].pb(y), g[y].pb(x);
    }
    auto dfs = [&] (auto&& self, int u) -> void {
        for (auto v : g[u]) {
            if (lvl[v] == -1) {
                lvl[v] = 1 + lvl[u];
                self(self, v);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (lvl[i] != -1) continue;
        lvl[i] = 1;
        dfs(dfs, i);
    }
    for (auto [x, y] : edg) {
        if (lvl[y] < lvl[x]) swap(x, y);
        cout << x+1 << ' ' << y+1 << endl;
    }
}
 
int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
