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

const int inf = 1e5+10;
const int mod = 1e9+7;
const int maxn = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int solve1(int n, int d, vector<ii> edg){
    vector<vector<int>> g(n);
    for (auto [u, v] : edg) g[u].pb(v), g[v].pb(u);

    vector<deque<int>> dp(n), dpp = dp;

    vector<vector<int>> tr(n), tr2(n);

    auto dfs = [&] (auto&& self, int u, int p) -> void {
        int mx = 0, big = -1;
        for (auto v : g[u]) {
            if (v == p) continue;
            self(self, v, u);
            if (ckmax(mx, sz(dp[v]))) big = v;
        }
        if (big != -1) swap(dp[u], dp[big]);
        dp[u].push_front(1);
        vector<ii> trocas;
        for (auto v : g[u]) {
            if (v == p or v == big) continue;
            int best = 0;
            for (int i = sz(dp[v])-1; i >= (d-1)/2; --i) ckmax(best, dp[v][i]), dp[u][i+1] += best;
            for (int i = 0; i < min(sz(dp[v]), (d-1)/2); ++i) {
                while (sz(trocas) <= i+1) trocas.emplace_back(-inf, 0), tr[u].pb(big);
                if (d-i-2 < sz(dp[v])) {
                    if (ckmax(trocas[i+1].first, dp[v][i] - dp[v][d-i-2])) tr[u][i+1] = v;
                    trocas[i+1].second += dp[v][d-i-2];
                }
                else if (ckmax(trocas[i+1].first, dp[v][i])) tr[u][i+1] = v;
            }
        }
        for (int i = 1; i < min(sz(trocas), (d+1)/2); ++i) {
            dp[u][i] += trocas[i].second;
            if (ckmax(dp[u][i], (d-i<sz(dp[u])?dp[u][d-i]:0) + trocas[i].first)) {}
            else tr[u][i] = big;
        }
        while (sz(dp[u]) > d + 1) {
            ckmax(end(dp[u])[-2], dp[u].back());
            dp[u].pop_back();
        }
        if (sz(dp[u]) > d) dp[u][0] += dp[u][d];
        tr2[u].resize(sz(trocas)+2);
        iota(all(tr2[u]), 0);
        for (int i = sz(trocas); i >= 0; --i) {
            if (ckmax(dp[u][i], dp[u][i+1])) tr2[u][i] = tr2[u][i+1];
        }
    };
    dfs(dfs, 0, 0);
    return *max_element(all(dp[0]));
}

void SS() {
    int n, d; cin >> n >> d;
    if (n == 1) {
        cout << "1\n1" << endl;
        exit(0);
    }
    vector<pair<int, int>> edg(n-1);
    for (auto& [x, y] : edg) cin >> x >> y, --x, --y;
    cout << solve1(n, d, edg) << endl;
    //auto ans = solve1(n, d, edg);
    //cout << sz(ans) << endl;
    //for (auto x : ans) cout << x + 1 << ' ';
    //cout << endl;
    exit(0);
}

int32_t main(){_
    SS();
    int tt = 1;
    while (true) {
        int n = rnd(1, 15), d = rnd(1, 3);
        vector<ii> edg;
        for (int i = 1; i < n; ++i) edg.emplace_back(i, rnd(0, i-1));
        //vector<int> my = solve1(n, d, edg); 
        int my = solve1(n, d, edg);
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for (auto [x, y] : edg) dist[x][y] = dist[y][x] = 1;
        for (int i = 0; i < n; ++i) dist[i][i] = 0;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    ckmin(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ok(1<<n);
        ok[0] = 1;
        int resp = 0, m = 0;
        for (int i = 1; i < (1<<n); ++i) {
            int l;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) l = j;
            }
            if (ok[i - (1 << l)] == 0) continue;
            ok[i] = 1;
            for (int j = 0; j < l; ++j) {
                if ((i >> j) & 1) ok[i] &= (dist[l][j] >= d);
            }
            if (ok[i] and ckmax(resp, __builtin_popcount(i))) m = i; 
        }
        //if (sz(my) != resp) {
        if (my != resp) {
            cout << "Wrong answer on test " << tt << endl;
            cout << n << ' ' << d << endl;
            for (auto [x, y] : edg) cout << x + 1 << ' ' << y + 1 << endl;
            //cout << "Your output: " << sz(my) << " - ";
            //for (auto x : my) cout << x + 1 << ' ';
            cout << "Your output: " << my << endl;
            cout << "Correct answer: " << resp << " - ";
            for (int i = 0; i < n; ++i) if ((m >> i) & 1) cout << i + 1 << ' ';
            cout << endl;
            exit(0);
        }
        cout << "Accepted on test " << tt++ << endl;
    }
}
