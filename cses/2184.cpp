#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define pb push_back
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

const int inf = 2e9+1;
const int mod = 1e9+7;
const int maxn = 2e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int st[30][18][maxn];
ll pre[30][maxn];

void solve(){
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    for (int j = 0; j < 18; ++j) {
        for (int i = 0; i < 30; ++i) {
            for (int k = 1; k <= n; ++k) {
               if (j == 0) {
                    if ((1 << i) <= v[k-1] and v[k-1] < (1 << (i+1))) st[i][j][k] = v[k-1];
                    else st[i][j][k] = inf;
               } else st[i][j][k] = min(st[i][j-1][k], st[i][j-1][k+(1<<(j-1))]);
            }
        }
    }
    for (int i = 0; i < 30; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] = pre[i][j-1];
            if (v[j-1] < (1 << (i+1))) pre[i][j] += v[j-1];
        }
    }
    auto query = [&] (int k, int l, int r) {
        if (l == r) return st[k][0][l];
        int lg = __lg(r-l+1);
        return min(st[k][lg][l], st[k][lg][r-(1<<lg)+1]);
    };
    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = pre[29][r] - pre[29][l-1] + 1;
        for (int i = 0; i < 30; ++i) {
            int val = (i ? pre[i-1][r] - pre[i-1][l-1] : 0);
            int small = query(i, l, r);
            if (small == inf) small = 0;
            if (val + 1 < small) {
               ans = val + 1;
               break;
            }
        }
        cout << ans << endl;
    }
}

int32_t main(){_
  int t = 1; //cin >> t;
  while(t--) solve();
}
