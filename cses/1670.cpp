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
const int maxn = 4e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
    vector<int> grid(9), pot(9, 1);
    for (auto& x : grid) cin >> x;
    for (int i = 1; i < 9; ++i) pot[i] = pot[i-1] * 10;
    auto getPos = [&] (int x, int y) {
        return x / pot[y] % 10;
    };
    auto change = [&] (int& x, int k, int v) {
        x = x + pot[k] * (v - getPos(x, k));
    };
    auto swap = [&] (int& x, int a, int b) {
        int v1 = getPos(x, a), v2 = getPos(x, b);
        change(x, a, v2), change(x, b, v1);
    };
    int m = 0, target = 0;
    for (int i = 0; i < 9; ++i) m += pot[i] * grid[i], target += (pot[i] * (i+1));
    unordered_map<int, int> dist;
    queue<int> q;
    dist[m] = 0, q.push(m);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        if (u == target) {
            cout << dist[u] << endl;
            exit(0);
        }
        for (int i = 0; i < 9; ++i) {
            if (i % 3 != 2) {
                int v = u;
                swap(v, i, i+1);
                if (!dist.count(v)) dist[v] = dist[u]+1, q.push(v);
            }
            if (i < 6) {
                int v = u;
                swap(v, i, i+3);
                if (!dist.count(v)) dist[v] = dist[u]+1, q.push(v);
            }
        }
    }
    assert(false);
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
